import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
from cocotbext.axi import AxiLiteBus, AxiLiteMaster
import cocotb.result
CLK_PERIOD = 10  # ns

async def reset_dut(dut):
    dut.ARESETn.value = 0
    for _ in range(5):
        await RisingEdge(dut.ACLK)
    dut.ARESETn.value = 1
    for _ in range(2):
        await RisingEdge(dut.ACLK)

@cocotb.test
async def test_mem_mapped_regs(dut):
    """Test writing and reading 4 memory-mapped registers via AXI4-Lite"""

    cocotb.start_soon(Clock(dut.ACLK, CLK_PERIOD, units="ns").start())
    await reset_dut(dut)

    axil_master = AxiLiteMaster(
        AxiLiteBus.from_prefix(dut, "saxi"),
        dut.ACLK,
        dut.ARESETn,
        reset_active_level=False
    )

    test_values = [0x11111111, 0x22222222, 0x33333333, 0x44444444]

    # Write to registers
    for i, val in enumerate(test_values):
        addr = i * 4
        await axil_master.write(addr, val.to_bytes(4, "little"))
        dut._log.info(f"Wrote 0x{val:08X} to register at offset 0x{addr:02X}")

    # Read back and check
    for i, expected in enumerate(test_values):
        addr = i * 4
        resp = await axil_master.read(addr, 4)
        read_val = int.from_bytes(resp.data, "little")
        dut._log.info(f"Read  0x{read_val:08X} from register at offset 0x{addr:02X}")
        assert read_val == expected, f"Register {i} read {read_val:#x}, expected {expected:#x}"

    # Explicitly end simulation
    dut._log.info("Test completed successfully. Ending simulation.")
    raise cocotb.result.TestSuccess()

    