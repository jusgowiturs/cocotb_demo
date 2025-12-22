🧱 DAY 1 — Kernel Module Basics (3 hours)
🎯 Goal

Understand what a kernel module really is.

Tasks

Write Hello Kernel Module

Use:

module_init

module_exit

pr_info

Load/unload:

insmod hello.ko
rmmod hello
dmesg

Concepts to Understand

What is THIS_MODULE

Difference between kernel & userspace

Why MODULE_LICENSE("GPL") matters

❌ Don’t

Don’t touch sysfs

Don’t touch device drivers

🧰 DAY 2 — Kernel Build System & Makefile (2.5 hours)
🎯 Goal

Understand how your code becomes a .ko

Tasks

Study this line deeply:

make -C $(KDIR) M=$(PWD) modules


Build with:

make
make clean

Concepts

Meaning of:

obj-m

Module.symvers

modules.order

Outcome

You should be able to explain the build flow verbally.

🧠 DAY 3 — Memory, Sections & Static Variables (3 hours)
🎯 Goal

Stop guessing about memory.

Learn

.text

.data

.bss

stack vs heap

static keyword

Practice

Answer confidently:

Why is static unsigned long phys_base; initialized to 0?

✔ Because it lives in .bss

❌ Don’t

Don’t use kmalloc yet

📦 DAY 4 — Character Device (Basics) (3 hours)
🎯 Goal

Understand file_operations

Tasks

Implement:

.open

.read

Register char device

Create /dev node

Concepts

Who calls .read()?

What is copy_to_user()?

Important

Understand this structure:

static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .read  = demo_read,
};

🪟 DAY 5 — sysfs (Very Important) (3 hours)
🎯 Goal

Clean kernel ↔ user interface

Tasks

Create sysfs attribute:

DEVICE_ATTR_RW(ctrl);


Implement:

ctrl_show

ctrl_store

Concepts

Why text-based?

Why locking is required

Why kstrtoul() is used

You must clearly understand:

How ctrl gets linked to ctrl_show() and ctrl_store()

🔒 DAY 6 — Concurrency & Locking (2.5 hours)
🎯 Goal

Avoid race conditions

Learn

mutex

When kernel code can sleep

Why sysfs callbacks sleep-safe

Practice

Protect shared variables

Remove lock and understand the bug

🔌 DAY 7 — Platform Driver + MMIO (3 hours)
🎯 Goal

Real embedded driver structure

Tasks

Write platform driver

Implement:

probe()

remove()

Use:

ioremap

readl / writel

Concepts

Device Tree

Why probe is called automatically

🧪 DAY 8 — Emulation using Renode (3 hours)
🎯 Goal

Test without hardware

Tasks

Boot kernel in Renode

Load module:

insmod simple_kernel_module.ko


Test:

cat /sys/.../ctrl
echo 0x1 > /sys/.../ctrl

Learn

Debug via dmesg

Observe MMIO behavior

🧹 DAY 9 — Cleanup, Install & depmod (2.5 hours)
🎯 Goal

Professional workflow

Tasks

Use:

make modules_install
depmod -a
modprobe simple_kernel_module


Understand:

/lib/modules/$(uname -r)/updates/

modules.dep

🏁 Final Outcome (After 9 Days)

You will be able to:
✔ Write a kernel module from scratch
✔ Explain build system
✔ Create sysfs & char interfaces
✔ Handle MMIO safely
✔ Emulate & test using Renode
✔ Debug kernel issues confidently

🕒 Summary Table
Day	Topic	Hours
1	Hello module	3
2	Build system	2.5
3	Memory model	3
4	Char device	3
5	sysfs	3
6	Locking	2.5
7	Platform driver	3
8	Renode	3
9	Install & cleanup	2.5

👉 Total ≈ 25 hours

💡 Final Advice (Important)

Understanding beats speed.

If one day slips, don’t rush — kernel learning compounds.