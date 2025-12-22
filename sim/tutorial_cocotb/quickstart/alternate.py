# This program is an alternative to the Makefile is to use the Python Test Runners, or “runner” for short
import os
from pathlib import Path
import cocotb
#from cocotb_tools.runner import get_runner
from cocotb.runner import get_runner
import logging

logging.basicConfig(filename='mytest_bench.log',filemode='w',level=logging.DEBUG,format='%(asctime)s| %(levelname)s %(message)s')
    
def test_run():
    # Create a logger for this testbench
    logging.debug(f'Running Test bench')
    sim = os.getenv("SIM","icarus")
    proj_path = Path(__file__).resolve().parent
    sources = [proj_path / "adder.v"]
    
    runner = get_runner(sim)
    runner.build(
        sources=sources,
        hdl_toplevel="adder",
    )
    #logging.info()

    runner.test(hdl_toplevel="adder", test_module="test_adder")


if __name__ == "__main__":
    test_run()
