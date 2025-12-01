# Files inseide SD Card

- BOOT.BIN
- boot.py
- boot.scr
- image.ub
- REVISION
  - Release 2021_11_18 14a7328
Board 2021_11_18 14a7328 https://github.com/Xilinx/PYNQ




# PYNQ SD card image preparation 
    https://pynq.readthedocs.io/en/latest/pynq_sd_card.html

    The SD card build flow will create the BOOT.bin, the u-boot bootloader, the Linux Device tree blob, the Linux kernel and the PYNQ-Linux root filesystem.

Using Powershell
This package includes:
-   dd
-   cat
-   cp
-   many other UNIX tools
`choco install gnuwin32-coreutils.install -y`


After installation, verify:dd verion by
`dd --version`

```powershell
# 1 tells \\.\PhysicalDrive1
# 0 tells \\.\PhysicalDrive0
Get-Disk


```




https://www.youtube.com/watch?v=mIBODati0FE





From CHatgpt
# STEP 1 — Install the required tools in WSL

Run:
sudo apt update
sudo apt install parted dosfstools mount util-linux
sudo apt install kpartx

mkdir ~/SDCARD
cd ~/SDCARD
# Create a 512MB SD boot image file
dd if=/dev/zero of=sd_boot.img bs=1M count=512

sudo parted sd_boot.img --script mklabel msdos
sudo parted sd_boot.img --script mkpart primary fat32 1MiB 100%





cd ~/SDCARD/
 1995  dd if=/dev/zero of=sd_boot.img bs=1M count=512
 1996  ls
 1997  sudo parted sd_boot.img --script mklabel msdos
 1998  sudo parted sd_boot.img --script mkpart primary fat32 1MiB 100%
 1999  sudo apt update
 2000  sudo apt install parted dosfstools mount util-linux
 2001  sudo parted sd_boot.img --script mklabel msdos
 2002  sudo parted sd_boot.img --script mkpart primary fat32 1MiB 100%
 2003  ls
 2004  sudo losetup --find --partscan --show sd_boot.img
 2005  ls
 2006  sudo mkfs.vfat /dev/loop2p1
 2007  ls -l /dev/loop2*
 2008  sudo apt install kpartx
 2009  sudo kpartx -av /dev/loop2
 2010  ls -l /dev/loop2*
 2011  ls -l /dev/loop2
 2012  ls -l /dev/loop3
 2013  sudo losetup --find --show sd_boot.img
 2014  sudo kpartx -av /dev/loop1
 2015  ls /dev/mapper/
 2016  sudo mkfs.vfat /dev/mapper/loop1p1
 2017  sudo mount /dev/mapper/loop1p1 /mnt/sd
 2018  sudo mkdir -p /mnt/sd
 2019  sudo mount /dev/mapper/loop1p1 /mnt/sd
 2020  ls /mnt/sd
 2021  sudo file -s /dev/mapper/loop1p1
 2022  sudo file -s /dev/dm-0
 2023  sudo mkdir -p /mnt/sd
 2024  sudo mount /dev/mapper/loop1p1 /mnt/sd
 2025  mount | grep mapper
 2026  cp zImage /mnt/sd/
 2027  sudo cp zImage /mnt/sd/
 2028  sudo cp *.dtb /mnt/sd/
 2029  sudo sync
 2030  sudo umount /mnt/sd
 2031  sudo kpartx -d /dev/loop1
 2032  sudo losetup -d /dev/loop1
 2033  ls
 2034  cp sd_boot.img /mnt/d/BS_ES/




 git clone https://github.com/buildroot/buildroot.git

 arm-linux-gnueabi-readelf -h vmlinux | grep Entry
  Entry point address:               0xc0208000







  ###### 30th November 2025
  ##### Trying to boot from SD card
  ### To visualise in vs code
sudo mkdir -p /mnt/e
sudo mount -t drvfs E: /mnt/e

Official Website:
https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18841973/Build+U-Boot
https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18842279/Build+Device+Tree+Blob


git clone https://github.com/Xilinx/u-boot-xlnx.git
Add tool chain to path and then set tool chain as below(tool chain name may vary based on toll chain version).
Zynq:
export CROSS_COMPILE=arm-linux-gnueabihf-

export ARCH=arm

ZynqUS+:

export CROSS_COMPILE=aarch64-linux-gnu-

export ARCH=aarch64

Microblaze:

export CROSS_COMPILE=microblazeel-xilinx-linux-gnu-

export ARCH=microblazeel

make 
xilinx_zynq_defconfig



https://www.youtube.com/watch?v=U2QBNz2XzYs

