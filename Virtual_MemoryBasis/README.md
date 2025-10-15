# Why Virtual Memory Basis?
- Processes should be isolated from each other
- miulti-tasking, security
- Program gets loaged in the Memory is known only at run time
- Virtualisation has to be happens at runtime
- Virtualisation not to be happens at pre-compiled or stored one and for all

## How do virtualisation 
- OS provides a virtual memory space to every process
- Addresses that are different from other processes
- For example virtual address say 1,2,3,4 for two different process but even same address like but physical address location for two different processes
- OS Kernel translates virtual - physical and back
- Each process sees its own virtual address space
- Page tables translate virtual to physical frames
- MMIO region live in physical address space(Not visible to apps directly)- By device driver can handle for process which require MMIO virtual to physical address space


## MMIO and ioremap
- Peripheral MMIO
  - Physical address (0x4000000)
  - Size(4KB)
- Kernel Virtual Address
  - __iomem   -> c attribute to tell its is iomemto flash 
  - As regular address in memory
  - Here Cache memory sitting in front of it
    - DRAM as peripheral READ larger in cache and give it to CPU or WRITE to DRAM slowly and clear out at later point in time.
    - IO device flush out immediately
    - __IOMEM at time read or write affect the value in the pointer directly
    - `writel` and `readl` kernel function
    - 
- User space
  - syscalls (open , read, iocntl) by user program(regular program)
  -  
# Deeper into OS Kernel
- Kernel vs User Space
  - 

# Device Model(Linux - Basics)
-   Device attach to buses
    -   Physical / virtual to platform, PCI, I2C
-   Drivers bind to devices and expose interfaces
-   Common User interface
    -   Character device
        -   /dev/*   (open,read,write ioctl)
        -   Sysfs attributs /sys/*   (text knobs, RO,RW)
        -   debugfs not for production
-   Interfaces to Peripherals(MAP)
    -   MMIO registers in hardware (AXI-lite, APB,...)
    -   Driver maps register(ioremap)
        -   devm_ioremap_resource
            -   Linux kernel remap function
            -   
    -   Exposes user API
        -   chr dev : /dev/ttys0, /dev/i2c-1,/dev/input/event*(Keyboard,mouse)...  with read/write/ioctl
        -   sysfs: /sys/class/.../attr 
            -   control, duty,period, status as example here
        -   UAPI 
            -   ioctl/mmap(ifneeded)
#### From registers to Files (Example)
- Hardware idea (smart timer example)
  - CTRL, PERIOD,DUTY, STATUS
- Linux demo:
  - /dev/v_reg_demo 
  - /sys/.../ctrl       #RW(enable/reset pulse)
  - /sys/.../period     #RW
  - /sys/.../duty       #RW
  - /sys/.../status     #RO (W1C semantic limited in demo)
### Typical Register Access in Drivers
```pseudocode
void __iomem *base =devm_ioremap_resource(dev,res);
u32 cntl    =   readl(base  + CTRL_OFF);
writel (ctrl| EN_BIT, base | CTRL_OFF);
```
-    Instead of * base, we use readl, writel

## Device Type
-   Character devices: byte -oriented, sequential I/O(read/write/ioctl)
-   Block device: Block oriented, buffered I/O via page cache 
-   Network interfaces: not files under /dev; 
-   accessed via sockets
-   visible under /sys/class/net*
-   tools like ip-tools,ethtool
-   

# ioctl
-   system calss - i/o control
-   send device - specific control commands from userspace to kernel space to device
-   read /write to the device is common but if control signal like to be provided, by using ioctl(fd,value), the value is given to driver instead of doing with file and driver will perform operations

```c
int fd = open("/dev/mydev",O_RDWR);// fd is not file pointer it is file descripter
ioctl(fd,MYREV_RESET);
```
# character device
-   Good for steraming data or structured control
-   Register a device: major /minor auto sith misc_register
-   Implement file ops: 
                -   .read
                -   .write
                -   .ioctl(Optional)
-   Linux kernel module 
    -   which allows to function instead of compileingfull OS, 
    -   Linux module by insmod can operate atgiven address space
-   
# /dev vs /sys
- /dev  (devtmpfs +udev): device nodes(special files
- major/minor
- Entry points for driver file ops
  - /dev/ttys0
  - /dev/sda
  - /dev/ttyS1...
- Udev - names/permissions/... 
  - /dev/disk/by-uuis/...
- /sys(sysfs):
  - Live view of kernel objects(devices, buses,.,,..)
  - Hierarchies:
    - /sys/devices,
    - /sys/bus*
    - /sys/class/*
    - Attributes: small text files for status/controls:
    - not bulk data
    - Udev listens to sysfs uevents to populate /dev


# Demonstration of Linux Device Driver
The following commands for demo purpose
```bash shell
ls      //File listing 
ls -a   //Hidden files
strace  //To get moreinformation when particular program is executed
strace ls //About ls execution
ls /
ls /dev/
ls -l /dev/
    #   // c - character type
    #   // b - block type device

cd /sys/
ls
cat /sys/block/sda/size # Number of sector
df
```


## Simulation 
- Model of the system behaviour
- Mimics the what , not necessaily the how
  - Similator could track signal changes but the simulation speed are unrelated torealworld timing
## EMulation
-  Recreating exact behaviour of a system
   -  Instrcution set level running emulating the behavious of the system
-  Gate level emulation(Behavious of each gate- not upto transistor level)
-  Functional equivalence with system
-  Cycle accurate simulation-cosimulation
-  



# Working with RENODE 
## Installation and setup
### RENODE
- Open source software development framework
- Emulate several processorfamilies
  - Instuction - accurate emulation
- Full System emulation
  - STD peripheral likes UART, SPI etc
  - Custom peripherals through software extensions
- Cosimulation with RTL
- Multi node device system reliably
- 