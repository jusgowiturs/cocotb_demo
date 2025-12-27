
What is a Kernel Module

A kernel module is code that runs inside the Linux kernel

It can be loaded and unloaded at runtime

It extends kernel functionality without rebooting

Kernel Space vs User Space

User programs run in user space

Kernel modules run in kernel space

Kernel code:

Has full hardware access

Must be written very carefully

Cannot use standard C libraries (printf, malloc, etc.)




[Kernel modules](https://www.kernel.org/doc/html/latest/kbuild/modules.html) — detailed explanation
Overview
A kernel module is a loadable piece of code that runs in kernel space and extends the Linux kernel at runtime without rebooting. Modules are commonly used for device drivers, filesystem add-ons, protocol handlers, and experimental kernel features.

Kernel vs user space
User space: ordinary applications, restricted access to hardware and kernel memory, use standard C library.
Kernel space: the kernel and modules run here with full hardware and memory access; mistakes can crash the system or corrupt data. Kernel code cannot use standard C library functions (no printf/malloc). Use kernel APIs instead.
Typical module structure
- An initialization function (module_init) called when the module is loaded.
- An exit/cleanup function (module_exit) called when the module is removed.
- Module metadata: MODULE_LICENSE, MODULE_AUTHOR,
- MODULE_DESCRIPTION.
Optionally exported symbols (EXPORT_SYMBOL) for other modules.


```c
// ...existing code...
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init mymod_init(void)
{
    printk(KERN_INFO "mymod: loaded\n");
    return 0;
}

static void __exit mymod_exit(void)
{
    printk(KERN_INFO "mymod: unloaded\n");
}

module_init(mymod_init);
module_exit(mymod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author");
MODULE_DESCRIPTION("Simple kernel module");
``` 

Building a module
Use the kernel build system. For an out-of-tree module, a simple Makefile:

```makefile
obj-m := mymod.o
KDIR := /lib/modules/$(shell uname -r)/build

all:
make -C $(KDIR) M=$(PWD) modules

clean:
make -C $(KDIR) M=$(PWD) clean
``` 

## Loading and Unloading
- insmod ./mymod.ko — insert module (no dependency resolution)
- modprobe mymod — insert with dependency resolution
- rmmod mymod — remove module
- lsmod — list loaded modules
- dmesg or journalctl -k — view printk/kernel logs

## Common Kernel APIs and Primitives
- Logging: printk with severity prefixes (KERN_ERR, KERN_WARNING, KERN_INFO).
- Allocation: kmalloc/kzalloc and kfree (GFP_KERNEL vs GFP_ATOMIC), vmalloc/vfree for large contiguous virtual memory.
- Synchronization: spinlock_t, mutex, rwlock, atomic_t, completions.
- Deferred work: workqueues, tasklets, kernel threads.
- User interaction: copy_to_user / copy_from_user, file_operations for character devices.
- Device model helpers: register_chrdev / cdev, device_create / class_create, platform_driver, PCI driver interfaces.
- Sysfs / procfs: expose attributes or diagnostics to user space.
- Module parameters: module_param, module_param_array for configurable behavior at load time.
- Symbol export: EXPORT_SYMBOL / EXPORT_SYMBOL_GPL to share functions with other modules.

## Concurrency & Safety Rules
- Do not sleep in atomic contexts (interrupt handlers, spinlock-held sections).
- Use the correct GFP([Get Free Page](https://docs.kernel.org/core-api/memory-allocation.html)) flags for allocation contexts.
- Validate user-supplied pointers; check copy_to/from_user return values.
- Hold locks for minimal time; offload long work to a worker.
- Ensure proper reference counting to prevent use-after-free.
## Error Handling and Resource Cleanup
- On failure during init, free all successfully acquired resources before returning an error.
- On module exit, release all resources: unregister devices, free memory, destroy workqueues, etc.

## Debugging Techniques
- printk and dmesg/journalctl -k for runtime messages.
- dynamic debug, ftrace, perf and tracepoints for tracing performance and call paths.
- kgdb for live kernel debugging; kdump and crash for postmortem.
- check /proc/kallsyms to inspect exported symbols.

## Security & Licensing
- MODULE_LICENSE affects access to GPL-only symbols.
- Minimize kernel interface surface exposed to user space; validate inputs and avoid arbitrary memory access.
- Prefer using stable kernel APIs; be cautious with undocumented internals.

## Best Practices
- Keep init fast and simple; fail cleanly on error.
- Use existing kernel helpers (refcounts, rails, regulator frameworks) instead of reimplementing.
- Add clear MODULE_* metadata and Kconfig/Makefile entries when integrating into a kernel tree.
- Document assumptions, context (sleepable/atomic), and required kernel configuration.


## Minimal Example with Module Parameter
```c
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int hello_count = 1;
module_param(hello_count, int, 0444);
MODULE_PARM_DESC(hello_count, "Number of hello messages");

static int __init hello_init(void)
{
    int i;
    for (i = 0; i < hello_count; ++i)
        printk(KERN_INFO "hello_mod: Hello %d\n", i+1);
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "hello_mod: Goodbye\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author Name");
MODULE_DESCRIPTION("Minimal hello kernel module");
```

## Further Reading
- "Linux Device Drivers" (LDD3) — fundamentals and examples
- Kernel Documentation at: /usr/src/linux/Documentation/ and https://www.kernel.org/doc/
- man pages and online resources for specific APIs (kmalloc, workqueue, cdev, platform driver)








```// filepath: d:\BS_ES\EL_FPGA\coco_tb\cocotb_demo\Kernel_materials\Kernel_Module_Basics.md
// ...existing code...
# Kernel Module Basics — Detailed Guide

## What is a Kernel Module
A kernel module is loadable code that runs inside the Linux kernel. Modules extend kernel functionality (device drivers, filesystem modules, protocol handlers, tracing helpers, etc.) and can be inserted or removed at runtime without rebooting.

## Kernel Space vs User Space
- User space: normal applications run with restricted privileges and use standard C libraries.
- Kernel space: kernel and modules run here with full hardware and memory access. Bugs in kernel space can crash the whole system.
- Kernel code cannot use user-space C library functions (printf, malloc, etc.); it must use kernel APIs (printk, kmalloc, etc.).

## Typical Module Structure
A minimal module usually contains:
- an initialization function (called when module is loaded),
- a cleanup/exit function (called when module is removed),
- module metadata (MODULE_LICENSE, MODULE_AUTHOR, MODULE_DESCRIPTION),
- optional module parameters and exported symbols.

Example skeleton:
```c
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init mymod_init(void)
{
    printk(KERN_INFO "mymod: loaded\n");
    return 0;
}

static void __exit mymod_exit(void)
{
    printk(KERN_INFO "mymod: unloaded\n");
}

module_init(mymod_init);
module_exit(mymod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author Name");
MODULE_DESCRIPTION("Simple kernel module");
```

## Building Out-of-Tree Modules
Use the kernel build system. Typical Makefile for out-of-tree module:
```makefile
obj-m := mymod.o
KDIR := /lib/modules/$(shell uname -r)/build

all:
\tmake -C $(KDIR) M=$(PWD) modules

clean:
\tmake -C $(KDIR) M=$(PWD) clean
```

## Loading and Unloading
- insmod ./mymod.ko — insert module (no dependency resolution)
- modprobe mymod — insert with dependency resolution
- rmmod mymod — remove module
- lsmod — list loaded modules
- dmesg or journalctl -k — view printk/kernel logs

## Common Kernel APIs and Primitives
- Logging: printk with severity prefixes (KERN_ERR, KERN_WARNING, KERN_INFO).
- Allocation: kmalloc/kzalloc and kfree (GFP_KERNEL vs GFP_ATOMIC), vmalloc/vfree for large contiguous virtual memory.
- Synchronization: spinlock_t, mutex, rwlock, atomic_t, completions.
- Deferred work: workqueues, tasklets, kernel threads.
- User interaction: copy_to_user / copy_from_user, file_operations for character devices.
- Device model helpers: register_chrdev / cdev, device_create / class_create, platform_driver, PCI driver interfaces.
- Sysfs / procfs: expose attributes or diagnostics to user space.
- Module parameters: module_param, module_param_array for configurable behavior at load time.
- Symbol export: EXPORT_SYMBOL / EXPORT_SYMBOL_GPL to share functions with other modules.

## Concurrency & Safety Rules
- Do not sleep in atomic contexts (interrupt handlers, spinlock-held sections).
- Use the correct GFP flags for allocation contexts.
- Validate user-supplied pointers; check copy_to/from_user return values.
- Hold locks for minimal time; offload long work to a worker.
- Ensure proper reference counting to prevent use-after-free.

## Error Handling and Resource Cleanup
- On failure during init, free all successfully acquired resources before returning an error.
- On module exit, release all resources: unregister devices, free memory, destroy workqueues, etc.

## Debugging Techniques
- printk and dmesg/journalctl -k for runtime messages.
- dynamic debug, ftrace, perf and tracepoints for tracing performance and call paths.
- kgdb for live kernel debugging; kdump and crash for postmortem.
- check /proc/kallsyms to inspect exported symbols.

## Security & Licensing
- MODULE_LICENSE affects access to GPL-only symbols.
- Minimize kernel interface surface exposed to user space; validate inputs and avoid arbitrary memory access.
- Prefer using stable kernel APIs; be cautious with undocumented internals.

## Best Practices
- Keep init fast and simple; fail cleanly on error.
- Use existing kernel helpers (refcounts, rails, regulator frameworks) instead of reimplementing.
- Add clear MODULE_* metadata and Kconfig/Makefile entries when integrating into a kernel tree.
- Document assumptions, context (sleepable/atomic), and required kernel configuration.

## Minimal Example with Module Parameter
```c
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int hello_count = 1;
module_param(hello_count, int, 0444);
MODULE_PARM_DESC(hello_count, "Number of hello messages");

static int __init hello_init(void)
{
    int i;
    for (i = 0; i < hello_count; ++i)
        printk(KERN_INFO "hello_mod: Hello %d\n", i+1);
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "hello_mod: Goodbye\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author Name");
MODULE_DESCRIPTION("Minimal hello kernel module");
```

## Further Reading
- "Linux Device Drivers" (LDD3) — fundamentals and examples
- Kernel Documentation at: /usr/src/linux/Documentation/ and https://www.kernel.org/doc/
- man pages and online resources for specific APIs (kmalloc, workqueue, cdev, platform driver)
