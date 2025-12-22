obj-m += simple_kernel_module.o
KDIR	?=	/home/jusgowiturs/arm-kernel/linux-6.6
PWD  := $(shell pwd)

ARCH=arm
CROSS_COMPILE=arm-linux-gnueabihf-


all:
	make -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	make -C $(KDIR) M=$(PWD) clean


install:
	sudo make -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) INSTALL_MOD_PATH=/home/jusgowiturs/initramfs  modules_install
	sudo depmod -a