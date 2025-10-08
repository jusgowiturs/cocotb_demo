# TOPLEVEL_LANG = verilog
# PWD = $(shell pwd)
# VERILOG_SOURCES = $(PWD)/axi_MMIO.v
# TOPLEVEL = simple_axil_slave
# MODULE = axi_mmio_tb  # just the test filename without .py

# $(info VERILOG_SOURCES is $(VERILOG_SOURCES))

# SIM = icarus

# include $(shell cocotb-config --makefiles)/Makefile.sim
# export COCOTB_REDUCED_LOG_FMT = 1

# all: sim

# sim:
# 	$(MAKE) -C $(shell cocotb-config --makefiles) VERILOG_SOURCES=$(VERILOG_SOURCES) TOPLEVEL=$(TOPLEVEL) MODULE=$(MODULE) SIM=$(SIM) all

# clean:
# 	rm -rf sim_build


TOPLEVEL_LANG = verilog
PWD = $(shell pwd)
VERILOG_SOURCES = $(PWD)/axi_MMIO.v
TOPLEVEL = simple_axil_slave
MODULE = axi_mmio_tb
SIM = icarus

export COCOTB_REDUCED_LOG_FMT = 1

include $(shell cocotb-config --makefiles)/Makefile.sim
