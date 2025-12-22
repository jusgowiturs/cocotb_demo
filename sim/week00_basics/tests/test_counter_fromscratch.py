# This is to understand how cocotb works
# Import all the necessary library
import cocotb
from cocotb.clock import Clock # This Clock can be used for triggering
from cocotb.triggers import FallingEdge, RisingEdge # SOFTWARE Falling and Rising EDGE
# Lets def reset definition
# In the design code the following signals
# clk -> Clock signal
# rstn-> active low reset
# en -> enable signal
#q -> 4 bit output  count value 

async def reset(dut):
    dut.rstn.value = 0   # dut is cocotb instance for Top module, Here Top module is counter.v.
    # value is object/member for the instance
    dut.en.value =0
    # Lets wait for two falling edge using FallingEdge 
    await FallingEdge(dut.clk)
    await FallingEdge(dut.clk)
    dut.rstn.value = 1 # Deassert Reset and ENable is activated
    dut.en.value = 1


# Definition for Tick by passing number of ticks as argument
async def tick(dut, cycles=1):
    for _ in range(cycles):
        await FallingEdge(dut.clk)


# cocotb.test python decorator used by cocotb framework to mark this function as a test case. This decorator will tell cocotb that this function is a special type of coroutine that is meant to either pass or fail. 
@cocotb.test
async def first_test_case(dut):
    # Start a Clock signal using following
    # start.soon() - Schedule a coroutine to be run concurrently in a Task
    # start()- Schedule a coroutine to be run concurrently, then yield control to allow pending tasks to execute. The calling task will resume execution before control is returned to the simulator. When the calling task resumes, the newly scheduled task may have completed, raised an Exception, or be pending on a Trigger.
    cocotb.start_soon(Clock(dut.clk,10,units="ps").start())


    # Check for reset condition
    await reset(dut)

    assert int(dut.q.value)== 0, f"No reset occurred, q should be 0, got {int(dut.q.value)}"
     # Enable counting for 10 cycles
    dut.en.value = 1
    await tick(dut, 10)
    assert int(dut.q.value) == 10, f"Expected q=5 after 10 cycles, got {int(dut.q.value)}"

    # Disable and ensure the value holds over multiple cycles
    dut.en.value = 0
    snap = int(dut.q.value)
    await tick(dut, 3)
    assert int(dut.q.value) == snap, "q changed while en=0"

    # Re-enable and count a few more cycles
    dut.en.value = 1
    await tick(dut, 2)
    assert int(dut.q.value) == snap + 2, "q did not increment correctly after re-enabling"


