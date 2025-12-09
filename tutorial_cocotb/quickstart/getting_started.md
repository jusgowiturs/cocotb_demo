#  Cocotb Beginner Tutorial

##  What is Cocotb?

**Cocotb** (coroutine-based co-simulation testbench) is a Python library for writing testbenches for HDL (Verilog/VHDL) designs. Instead of writing testbenches in HDL, Cocotb lets you use Python!

It runs using a simulator (e.g., Icarus Verilog, ModelSim, GHDL) and connects your Python code to the simulation via a foreign language interface (VPI/VHPI/FLI).

---

##  Prerequisites

Make sure you have:

- Python 3.7+
- A supported HDL simulator (e.g., **Icarus Verilog** for open-source)
- **pip** installed

---

##  Installation

Install Cocotb and Icarus Verilog:

```bash
pip install cocotb
sudo apt install iverilog   # On Ubuntu/Debian
```


## Directory Structure
```
adder_project/
├── adder.v
├── test_adder.py
└── Makefile
```
## EXAMPLE Design file
```verilog
// adder.v
module adder (
    input  logic [3:0] a,
    input  logic [3:0] b,
    output logic [4:0] sum
);
    assign sum = a + b;
endmodule
```
## TestBench
```python 
# test_adder.py
import cocotb
from cocotb.triggers import Timer
import random

@cocotb.test()
async def adder_basic_test(dut):
    """Test the adder with random inputs"""
    for _ in range(10):
        a = random.randint(0, 15)
        b = random.randint(0, 15)

        dut.a.value = a
        dut.b.value = b

        await Timer(2, units="ns")  # Wait 2ns for simulation

        expected_sum = a + b
        assert dut.sum.value == expected_sum, f"Adder result is incorrect: {dut.sum.value} != {expected_sum}"
```
## Create Makefile
```
# Makefile

TOPLEVEL_LANG = verilog
VERILOG_SOURCES = $(shell pwd)/adder.v
TOPLEVEL = adder
MODULE = test_adder

SIM = icarus

include $(shell cocotb-config --makefiles)/Makefile.sim
```

## Run simulation
```
make
```
## Alternative approach without Makefile by using runner
- import get_runner  from cocotb_tools.runner 
  - Now it is updated and get it from cocotb.runner
- An alternative to the Makefile is to use the Python Test Runners, or “runner” for short

## Tips for Beginners

- Look into .cocotb/lib/python3/sitepackage toknow the cocotb installed components like cocotb bus , coverage and pytest installed?!
- Use dut.<signal>.value = x to drive signals
- Use await Timer(ns, units="ns") to delay time
- Use @cocotb.test() to define each test
- Signals are accessed with .value
- Use assertions to check expected behavior