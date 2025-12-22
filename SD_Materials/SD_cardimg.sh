dd if=/dev/zero of=sdcard.img bs=1M count=1024
mkfs.fat sdcard.img
sudo mkdir /mnt/sdcard
sudo mount -o loop sdcard.img /mnt/sdcard
cp zImage zynq-zed-peripherals_a.dtb boot.scr /mnt/sdcard
sudo umount /mnt/sdcard



echo "Loading kernel..."
fatload mmc 0:1 0x02000000 /boot/zImage
echo "Loading device tree..."
fatload mmc 0:1 0x1F00000 /boot/zynq-zed-peripherals.dtb
echo "Booting kernel..."
bootz 0x02000000 - 0x1F00000
/mkimage -C none -A arm -T script -d boot.cmd boot.scr




1. Create a Blank SD Card Image:

This step will create a 4GB image file (sdcard.img) using /dev/zero, which means it will initialize a blank image. You can adjust the size (here it's 1GB for example):

dd if=/dev/zero of=sdcard.img bs=1M count=1024


This will create a 1GB image file. If you want a larger image (e.g., 4GB), change count=1024 to count=4096.

2. Create Partition Table:

Now that you have a blank image, you need to partition it. We'll create two partitions:

A FAT32 partition for the boot files (zImage, zynq-zed-peripherals.dtb, and boot.scr).

A Linux partition for the root filesystem.

2.1. Create the Partition Table using fdisk:
sudo fdisk sdcard.img


Once inside fdisk, follow these steps:

Create a new DOS partition table:

Command (m for help): o


Create the first partition (boot partition) with a size of 512MB:

Command (m for help): n
Partition type (default p): p
Partition number (1-4, default 1): 1
First sector (2048-8388607, default 2048): [Press Enter]
Last sector, +/-sectors or +/-size{K,M,G,T,P} (2048-8388607, default 8388607): +512M


Create the second partition (rootfs) with the remaining space:

Command (m for help): n
Partition type (default p): p
Partition number (2-4, default 2): 2
First sector (1050624-8388607, default 1050624): [Press Enter]
Last sector, +/-sectors or +/-size{K,M,G,T,P} (1050624-8388607, default 8388607): [Press Enter]


Change partition types (make the first partition FAT32 and the second Linux):

Change partition 1 to W95 FAT32 (LBA):

Command (m for help): t
Partition number (1,2, default 2): 1
Hex code or alias (type L to list all): c


Make sure partition 2 is set to Linux (if not, change it):

Command (m for help): t
Partition number (1,2, default 2): 2
Hex code or alias (type L to list all): 83


Write the partition table to the image:

Command (m for help): w

3. Create Filesystems:

Now that the partitions are set up, create filesystems on them.

3.1. Create a FAT32 filesystem on partition 1 (boot partition):
sudo losetup --find --partscan --show sdcard.img


This will output a device name like /dev/loop0.

Now, create a FAT32 filesystem on the first partition:

sudo mkfs.vfat -F 32 /dev/loop0p1

3.2. Create an ext4 filesystem on partition 2 (root filesystem):
sudo mkfs.ext4 /dev/loop0p2

4. Mount the Partitions:

Now, we need to mount these partitions to copy the necessary files.

sudo mount /dev/loop0p1 /mnt1
sudo mount /dev/loop0p2 /mnt2

5. Copy Files to the Boot Partition:

You will need to copy the following files to the boot partition (/mnt1):

zImage (kernel image)

zynq-zed-peripherals.dtb (device tree)

boot.scr (U-Boot script)

Assuming you have these files ready on your local machine:

Copy the files to /mnt1 (boot partition):

sudo cp zImage zynq-zed-peripherals.dtb boot.scr /mnt1/


Create the boot script (boot.cmd):

In the boot partition (/mnt1), create a boot.cmd file to tell U-Boot how to load the kernel and device tree:

echo "Loading kernel..." > /mnt1/boot.cmd
echo "fatload mmc 0:1 0x02000000 /boot/zImage" >> /mnt1/boot.cmd
echo "Loading device tree..." >> /mnt1/boot.cmd
echo "fatload mmc 0:1 0x1F00000 /boot/zynq-zed-peripherals.dtb" >> /mnt1/boot.cmd
echo "Booting kernel..." >> /mnt1/boot.cmd
echo "bootz 0x02000000 - 0x1F00000" >> /mnt1/boot.cmd


This script will load the kernel and device tree from the SD card and boot the system.

Convert boot.cmd to boot.scr:

Use mkimage to convert boot.cmd into a boot.scr:

mkimage -C none -A arm -T script -d /mnt1/boot.cmd /mnt1/boot.scr

6. Unmount and Clean Up:

Unmount the partitions:

sudo umount /mnt1
sudo umount /mnt2


Detach the loop device:

sudo losetup -d /dev/loop0

7. Write the SD Card Image to the SD Card:

Now, you need to copy the sdcard.img to the actual SD card. Assuming the SD card is mounted as /dev/sdX (replace X with the actual letter for your SD card), run:

sudo dd if=sdcard.img of=/dev/sdX bs=4M status=progress


Ensure you use the correct device identifier for your SD card (e.g., /dev/sdb or /dev/sdc). Be very careful here to avoid overwriting any other drives.

8. Eject the SD Card and Insert into the PYNQ-Z1:

After the dd command finishes, unmount the SD card from your machine:

sudo umount /dev/sdX


Now, insert the SD card into your PYNQ-Z1 board and power it on.

9. Booting the PYNQ-Z1:

The board should now boot from the SD card, loading the kernel (zImage), the device tree (zynq-zed-peripherals.dtb), and executing the boot script (boot.scr).

If everything is set up correctly, the PYNQ-Z1 should boot into the Linux system.

Summary of Files and Structure:

Your SD card's boot partition (/dev/loop0p1) should contain:

zImage (kernel)

zynq-zed-peripherals.dtb (device tree blob)

boot.scr (U-Boot script)

Your root filesystem partition (/dev/loop0p2) should contain the root filesystem. You can later copy over your rootfs if you have it ready.

Let me know if you encounter any issues along the way!