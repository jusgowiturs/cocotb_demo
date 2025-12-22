# 🧱 DAY 1 — Kernel Module Basics (3 hours)

## 🎯 Goal

- Understand what a kernel module really is.
- Tasks
- Write Hello Kernel Module
- Use:
    - module_init
    - module_exit
    - pr_info
- Load/unload:

```
insmod hello.ko
rmmod hello
dmesg
```

## Concepts to understand
- `THIS_MODULE`
- Kernel vs. userspace
- Why `MODULE_LICENSE("GPL")` matters

## ❌ Don’t
- Don’t touch sysfs
- Don’t touch device drivers

---

# 🧰 DAY 2 — Kernel Build System & Makefile (2.5 hours)

## 🎯 Goal
- Understand how source becomes a `.ko`.

## Tasks
- Study this line closely:
```bash
make -C $(KDIR) M=$(PWD) modules
```
- Build with:
```bash
make
make clean
```

## Concepts
- `obj-m`
- `Module.symvers`
- `modules.order`
- Build flow overview — be able to explain verbally

---

# 🧠 DAY 3 — Memory, Sections & Static Variables (3 hours)

## 🎯 Goal
- Stop guessing about memory layout.

Learn

.text

.data

.bss

stack vs heap

static keyword

## Practice
- Answer: Why is `static unsigned long phys_base;` initialized to 0?
    - Because it lives in `.bss`

## ❌ Don’t
- Don’t use `kmalloc` yet

---

# 📦 DAY 4 — Character Device (Basics) (3 hours)

## 🎯 Goal
- Understand `file_operations`.

## Tasks
- Implement `.open` and `.read`
- Register char device and create `/dev` node

## Concepts
- Who calls `.read()`?
- What is `copy_to_user()`?

## Example
```c
static const struct file_operations fops = {
        .owner = THIS_MODULE,
        .read  = demo_read,
};
```

---

# 🪟 DAY 5 — sysfs (Very Important) (3 hours)

## 🎯 Goal
- Provide a clean kernel ↔ user interface.

## Tasks
- Create sysfs attribute:
```c
DEVICE_ATTR_RW(ctrl);
```
- Implement `ctrl_show` and `ctrl_store`

## Concepts
- Why text-based interfaces?
- Why locking is required
- Why use `kstrtoul()`
- How `ctrl` links to `ctrl_show()` and `ctrl_store()`

---

# 🔒 DAY 6 — Concurrency & Locking (2.5 hours)

## 🎯 Goal
- Avoid race conditions.

## Learn
- `mutex`
- When kernel code can sleep
- Why sysfs callbacks are sleep-safe

## Practice
- Protect shared variables
- Remove lock intentionally to observe the bug

---

# 🔌 DAY 7 — Platform Driver + MMIO (3 hours)

## 🎯 Goal
- Real embedded driver structure.

## Tasks
- Write a platform driver implementing:
    - `probe()`
    - `remove()`
- Use `ioremap`, `readl`, `writel`

## Concepts
- Device Tree basics
- Why `probe()` is called automatically

---

# 🧪 DAY 8 — Emulation using Renode (3 hours)

## 🎯 Goal
- Test without hardware.

## Tasks
- Boot kernel in Renode
- Load module:
```bash
insmod simple_kernel_module.ko
```
- Test:
```bash
cat /sys/.../ctrl
echo 0x1 > /sys/.../ctrl
```

## Learn
- Debug via `dmesg`
- Observe MMIO behavior

---

# 🧹 DAY 9 — Cleanup, Install & depmod (2.5 hours)

## 🎯 Goal
- Professional workflow.

## Tasks
- Install and register modules:
```bash
make modules_install
depmod -a
modprobe simple_kernel_module
```

## Understand
- `/lib/modules/$(uname -r)/updates/`
- `modules.dep`

---

# 🏁 Final Outcome (After 9 Days)
You will be able to:
- Write a kernel module from scratch
- Explain the build system
- Create sysfs & char interfaces
- Handle MMIO safely
- Emulate & test using Renode
- Debug kernel issues confidently

---

# 🕒 Summary Table

| Day | Topic                 | Hours |
|-----|-----------------------|-------|
| 1   | Hello module          | 3     |
| 2   | Build system          | 2.5   |
| 3   | Memory model          | 3     |
| 4   | Char device           | 3     |
| 5   | sysfs                 | 3     |
| 6   | Locking               | 2.5   |
| 7   | Platform driver       | 3     |
| 8   | Renode                | 3     |
| 9   | Install & cleanup     | 2.5   |

Total ≈ 25 hours

---

## 💡 Final Advice
Understanding beats speed. If one day slips, don’t rush — kernel learning compounds.
