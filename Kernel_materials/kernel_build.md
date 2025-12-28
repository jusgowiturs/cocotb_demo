## Creating Busy Box for FileSystem
# prerequisite
```bash
sudo apt update
sudo apt install gcc-arm-linux-gnueabihf make build-essential flex bison libssl-dev libelf-dev  bc 
echo "Host GCC:"; gcc --version | head -n1
echo "Make:"; make --version | head -n1
echo "Flex:"; flex --version | head -n1
echo "Bison:"; bison --version | head -n1
echo "ARM Cross-Compiler:"; arm-linux-gnueabihf-gcc --version | head -n1

```
# Git Clone Busy box
```bash
git clone git://git.busybox.net/busybox.git
cd busybox
//Copy config file share by prof and download
cp <>path of config-busybox> .config
```


# Download Linux 6.6
```bash
wget https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-6.6.tar.xz
tar -xf linux-6.6.tar.xz
cp <Path of config-linus> .config
```


# Checking for bootable SD card about .config
```bash
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- mrproper
cp /mnt/d/BS_ES/EL_FPGA/coco_tb/KERNEL_SRC/.config .config
./CheckingbootableSD.sh # download from github/..

make -j$(nproc) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- zImage
make -j$(nproc) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules

make -j$(nproc) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules_prepare dtbs
./CheckingbootableSD.sh # download from github/..
grep -E "CONFIG_TMPFS|CONFIG_BLK_DEV_INITRD|CONFIG_RD_GZIP" .config # Both should be 'y' If your kernel is ready for your Renode setup, you should see:
CONFIG_BLK_DEV_INITRD=y (Essential: allows loading the external .cpio)
CONFIG_TMPFS=y (Highly recommended: allows mounting the RAM filesystem)
```

```bash
export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabihf-
```


```bash
# Required device nodes
mkdir -p /home/jusgowiturs/initramfs/{bin,sbin,etc,proc,sys,dev,usr/bin}
cd /home/jusgowiturs/initramfs
sudo mknod -m 600 dev/console c 5 1
sudo mknod -m 666 dev/null    c 1 3

# Minimal /init
cat > /home/jusgowiturs/initramfs/init <<'EOF'
#!/bin/sh
mount -t proc none /proc
mount -t sysfs none /sys
mount -t devtmpfs none /dev
echo "Userspace up; dropping to shell."

# Setting up for autoloading drivers if needed
for f in /sys/bus/platform/devices/*/modalias ; do
	[ -f "$f" ] && modprobe "$(cat "$f")" 2>/dev/null || true
done

exec /bin/sh < /dev/console > /dev/console 2>&1
EOF

chmod +x /home/jusgowiturs/initramfs/init
```
## Busy box

- make oldconfig
- make -j$(nproc) CROSS_COMPILE=arm-linux-gnueabihf- install CONFIG_PREFIX=/home/jusgowiturs/initramfs
## build our module then pack initramfs 



# Rootfs bindling
find . | cpio -o -H  newc > ../initramfs.cpio  

# TO Extract
mkdir ~/initramfs
cd ~/initramfs
cpio -idmv < ../initramfs.cpio  

# Repack
find . | cpio -o -H newc > ../initramfs.cpio  



# Information

TO know kernel entry point
arm-linux-gnueabihf-readelf -h vmlinux | grep "Entry point"



## To convert a DTB (Device Tree Blob) back into a human-readable DTS (Device Tree Source) on your Linux host in 2025, you use the Device Tree Compiler (DTC).
#### Install the Compiler 
- If you don't have it already, install the device-tree-compiler package: 
```bash
sudo apt update
sudo apt install device-tree-compiler
dtc -I dtb -O dts -o zynq-zed-peripherals.dts zynq-zed-peripherals.dtb

```