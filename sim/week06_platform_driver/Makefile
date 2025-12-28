obj-m += smarttimer_platform.o

#KDIR ?= /mnt/d/BS_ES/EL_FPGA/src_img/KERNEL_SRC
KDIR ?= /home/jusgowiturs/arm-linux/linux-6.6/
ARCH ?= arm
CROSS_COMPILE ?= arm-linux-gnueabihf-
KERNEL_VERSION := $(shell make -s -C $(KDIR) kernelrelease)
HOME := /home/jusgowiturs

all:
	$(MAKE) -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) clean

install:
	$(MAKE) -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE)  INSTALL_MOD_PATH=/tmp/initramfs/ modules_install
	# 2. Update module dependencies so 'modprobe' works in Renode
	@echo "Running depmod for kernel version: $(KERNEL_VERSION)"
	/sbin/depmod -b $(HOME)/initramfs/ $(KERNEL_VERSION)
