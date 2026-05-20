obj-m += smarttimer_platform.o
obj-m += smarttimer_irq.o

# Allow override: make KDIR=/path/to/linux
KDIR ?= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

