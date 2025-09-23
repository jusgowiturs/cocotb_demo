---
marp: true
---

# Embedded Linux + FPGAs

**Audience**: Undergrad EE students, minimal OS background, some Verilog experience.  
**Running Example**: Smart Timer (PWM with registers + interrupts).  
**Simulation-first**: Verilator + QEMU/Renode.

---

## Goals
- Understand memory-mapped I/O and AXI-Lite register interfaces
- Learn essential Linux kernel and driver concepts
- Map FPGA hardware into Linux via Device Tree
- Build complete hardware-software integration with interrupts

---

## Week 1 — MMIO & AXI-Lite Basics  
- **Focus**: How CPUs talk to peripherals. Memory-mapped I/O, AXI-Lite handshake signals.  
- **Demo**: Verilator testbench showing read/write to a simple AXI-Lite register bank.  
- **Quiz**: MMIO vs CPU registers; valid/ready meaning.  
- **Learning Outcomes**:  
  - Explain memory-mapped I/O.  
  - Identify AXI-Lite signals and handshakes.  
  - Run a basic Verilator testbench for register access.  

---

## Week 2 — Register Design & Smart Timer V1  
- **Focus**: Good register design (CTRL, STATUS, reserved bits, W1C), basics of PWM.  
- **Demo**: Smart Timer V1 with CTRL, PERIOD, DUTY registers; duty cycle seen in waveform.  
- **Quiz**: PWM timing; register do’s/don’ts.  
- **Learning Outcomes**:  
  - Design simple control/status registers.  
  - Implement a PWM with configurable duty cycle.  
  - Verify PWM behavior in simulation.  

---

## Week 3 — Core OS Concepts  
- **Focus**: User space vs kernel space, processes, system calls, device files.  
- **Demo**: Explore `/proc`, `/sys`, `/dev`; run strace on `ls`.  
- **Quiz**: Who executes system calls? Difference between files and device files.  
- **Learning Outcomes**:  
  - Distinguish between user and kernel space.  
  - Describe how system calls work.  
  - Identify device files in Linux.  

---

## Week 4 — Kernel Modules & Debugging  
- **Focus**: What modules are, how to build and insert them, printk basics, minimal Kbuild/Makefile.  
- **Demo**: “Hello world” kernel module: insmod/rmmod, printk log messages, dmesg.  
- **Quiz**: Module lifecycle; how to debug with printk.  
- **Learning Outcomes**:  
  - Compile and insert a kernel module.  
  - Use printk and dmesg for debugging.  
  - Write a minimal kernel module with a Makefile.  

---

## Week 5 — Device Tree Basics  
- **Focus**: What Device Tree describes, syntax (nodes, reg, compatible).  
- **Demo**: Create DT node for Smart Timer, compile with `dtc`, inspect blob in Linux.  
- **Quiz**: Compatible strings, reg property format.  
- **Learning Outcomes**:  
  - Describe the role of Device Tree in Linux.  
  - Write a simple DT node for a peripheral.  
  - Compile and inspect a DT blob.  

---

## Week 6 — Platform Driver Basics  
- **Focus**: Probe/remove, binding with compatible string.  
- **Demo**: Minimal Smart Timer platform driver: probe() logs a message when binding occurs.  
- **Quiz**: What makes driver and device bind? When is remove() called?  
- **Learning Outcomes**:  
  - Explain the probe/remove process.  
  - Bind a platform driver using a compatible string.  
  - Test driver binding in Linux.  

---

## Week 7 — Character Devices & MMIO Access  
- **Focus**: Char devices, file_operations (open/release/read/write), ioremap, readl/writel.  
- **Demo**: Driver exports `/dev/smarttimer`; write() sets duty cycle, read() returns register values.  
- **Quiz**: Char device vs regular file; safe MMIO access.  
- **Learning Outcomes**:  
  - Implement a character device driver.  
  - Access MMIO registers using ioremap and readl/writel.  
  - Interact with hardware through /dev files.  

---

## Week 8 — User-Space Integration  
- **Focus**: open/read/write in C, error handling, verifying outputs.  
- **Demo**: Simple C program controls Smart Timer (set duty cycle, read back status).  
- **Integration**: First working stack: Verilog + DT + driver + user app.  
- **Learning Outcomes**:  
  - Write a C program to interact with a char device.  
  - Handle errors in user–kernel communication.  
  - Integrate hardware, driver, and user program.  

---

## Week 9 — Interrupts Part 1 (Hardware + Wiring)  
- **Focus**: What interrupts are; level vs edge; wiring an interrupt in DT.  
- **Demo**: Smart Timer V2 with IRQ output; show signal in Verilator; printk confirms interrupt fired.  
- **Quiz**: Edge vs level interrupts; DT “interrupts” property meaning.  
- **Learning Outcomes**:  
  - Explain how hardware interrupts work.  
  - Modify DT to include interrupt information.  
  - Observe interrupt firing in simulation.  

---

## Week 10 — Interrupts Part 2 + Concurrency  
- **Focus**: request_irq, simple handler, top vs bottom halves; wait_queues for blocking I/O; locking with mutex/spinlock.  
- **Demo**: Driver increments counter in IRQ handler; user process blocks on read() until event; lock around shared data.  
- **Quiz**: Why use a mutex? Why block vs busy-poll?  
- **Learning Outcomes**:  
  - Write a simple interrupt handler in Linux.  
  - Use wait_queues for blocking I/O.  
  - Apply basic locking mechanisms for concurrency.  

---

## Week 11 — Integration & Debugging in QEMU  
- **Focus**: Running the complete Smart Timer system in QEMU/Renode; common issues.  
- **Demo**: Boot Linux with custom DT + driver; debug errors (bad reg address, probe failures).  
- **Quiz**: How to spot a probe failure? Where to look in dmesg?  
- **Learning Outcomes**:  
  - Integrate hardware, DT, and driver in emulation.  
  - Debug common binding and probe errors.  
  - Use QEMU/Renode for system testing.  

---

## Week 12 — Consolidation & Mini-Project  
- **Focus**: Students extend Smart Timer with a small new feature. Discuss hardware/software tradeoffs.  
- **Demo**: Minimal test harness to check new feature works.  
- **Wrap-up**: Recap the stack; path to real hardware.  
- **Learning Outcomes**:  
  - Extend an existing hardware/software design with a new feature.  
  - Perform functional testing of hardware–software systems.  
  - Reflect on HW/SW partitioning tradeoffs.  
