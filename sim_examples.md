# Running Example Designs for Simulation and Driver Development

## Overview

To provide students with a coherent path from RTL design through Linux device driver development, two running examples are proposed. Both can be demonstrated in simulation environments and later migrated to real hardware with minimal changes. Each example is structured to introduce concepts incrementally: AXI-Lite registers, interrupts, Linux kernel UIO, platform drivers, and integration with standard subsystems.

---

## Example 1: Smart Timer (PWM and Event Generator)

### Functional Description

The Smart Timer is an AXI-Lite peripheral that generates a PWM signal and provides timestamped button or edge events. It exposes a register interface to configure parameters and report status, and raises interrupts on specific events.

### RTL Features (progressive development)

* **Version 1**: AXI-Lite register bank with control, period, duty cycle, and status registers.
* **Version 2**: Hardware debounce and edge detection logic for button inputs. Interrupt line asserted on events.
* **Version 3**: Event FIFO with timestamps for edge detection. Additional power-control features such as clock gating when idle.

### Suggested Registers

* `CTRL`: control bits (PWM enable, debounce enable, interrupt enable).
* `PWM_PERIOD`: PWM period/divider.
* `PWM_DUTY`: PWM duty cycle.
* `BTN_VAL`: current button state.
* `INT_STAT`: interrupt status (write-one-to-clear).
* `EVT_COUNT`: number of entries in event FIFO.
* `EVT_DATA`: timestamp and event type.

### Simulation Demonstration

* **RTL unit tests**: cocotb testbenches to verify PWM duty cycle and debounce behavior.
* **Waveform inspection**: GTKWave traces to visualise PWM output.
* **Linux co-simulation**: Renode with a Verilated peripheral mapped into the system address space. Linux running in co-sim accesses registers via UIO or a platform driver.

### Driver Development Path

1. Userspace access via UIO: direct register reads/writes.
2. Minimal platform driver: memory-mapped registers, interrupt handling, character device interface.
3. Integration with kernel subsystems: expose PWM output via the PWM or LED framework; expose button input via the input subsystem.
4. Extensions: support for non-blocking I/O (`poll`, `select`), event delivery, and power management.

---

## Example 2: Virtual Sensor with Threshold Interrupts

### Functional Description

The Virtual Sensor is an AXI-Lite peripheral that generates a synthetic data stream (e.g., pseudo-random or sine waveform). It stores samples in a FIFO and provides threshold-based interrupt generation. The design supports timestamping and optional streaming output.

### RTL Features (progressive development)

* **Version 1**: Register bank with control, status, threshold, sample rate, and data registers. FIFO for sample storage.
* **Version 2**: Threshold comparison logic and interrupt line.
* **Version 3**: Timestamp latch for each sample. Optional AXI-Stream output for DMA use cases.

### Suggested Registers

* `CTRL`: start/stop, interrupt enable.
* `THRESH`: threshold value.
* `STATUS`: current device status.
* `SAMPLE_RATE_DIV`: sampling rate divider.
* `FIFO_LEVEL`: number of samples in FIFO.
* `DATA`: FIFO data pop.

### Simulation Demonstration

* **RTL unit tests**: cocotb tests to verify threshold crossings, interrupt generation, and FIFO operation.
* **Data capture**: dump synthetic samples to CSV and plot using Python.
* **Linux co-simulation**: Renode with Verilated peripheral; Linux drivers access samples through a character device or the IIO framework.

### Driver Development Path

1. Character device with read/write and ioctl interfaces.
2. Interrupt handling and support for `poll`/`select`.
3. Integration with the Industrial I/O (IIO) framework: buffered capture, sysfs configuration for sampling frequency and threshold.
4. Optional extensions: zero-copy buffer access using `mmap`.

---

## Proposed Sequence for Online Labs

1. **Register interface**: implement AXI-Lite register bank and verify with cocotb tests.
2. **Peripheral behavior**: add PWM generator or sample generator; measure duty cycle or sample statistics in simulation.
3. **Interrupts**: implement interrupt logic; verify correct signaling and clearing of status registers.
4. **Userspace drivers**: access the peripheral in co-simulated Linux using UIO.
5. **Platform driver**: implement a minimal driver with device tree support.
6. **Subsystem integration**: connect to PWM/LED/Input for Smart Timer or to IIO for Virtual Sensor.
7. **Advanced I/O**: add non-blocking access and buffer mapping.
8. **Power management and testing**: implement basic runtime power management and self-tests.

---

## Tooling

* **HDL simulation**: Verilog/SystemVerilog with Verilator or Icarus Verilog.
* **Testbenches**: cocotb for Python-based unit testing.
* **Waveform analysis**: GTKWave for signal traces.
* **System co-simulation**: Renode with Verilated peripherals to run Linux.
* **Driver development**: staged progression from UIO to platform drivers and subsystem integration.

