# test_adder.py
import cocotb
from cocotb.triggers import Timer
import random

@cocotb.test
async def test_case1(dut):
    """Test the adder with random inputs"""
    for _ in range(10):
        a = random.randint(0, 15)
        b = random.randint(0, 15)

        dut.a.value = a
        dut.b.value = b
        cocotb.log.info(f"a={a}, b={b}")
        await Timer(2, units="ns")  # Wait 2ns for simulation

        expected_sum = a + b
        assert dut.sum.value == expected_sum, f"Adder result is incorrect: {dut.sum.value} != {expected_sum}"


@cocotb.test
async def test_case2(dut):
    """Test the adder with random inputs"""
    for _ in range(10):
        a = random.randint(0, 15)
        b = random.randint(0, 16)
        

        dut.a.value = a
        dut.b.value = b
        cocotb.log.info(f"a={a}, b={b}")
        await Timer(2, units="ns")  # Wait 2ns for simulation

        expected_sum = a + b
        assert dut.sum.value == expected_sum, f"Adder result is incorrect: {dut.sum.value} != {expected_sum}"

