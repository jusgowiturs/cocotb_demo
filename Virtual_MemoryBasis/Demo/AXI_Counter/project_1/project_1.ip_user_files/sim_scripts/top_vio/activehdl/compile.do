vlib work
vlib activehdl

vlib activehdl/xil_defaultlib

vmap xil_defaultlib activehdl/xil_defaultlib

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../project_1.gen/sources_1/ip/top_vio/hdl/verilog" "+incdir+../../../../project_1.gen/sources_1/ip/top_vio/hdl" \
"../../../../project_1.gen/sources_1/ip/top_vio/sim/top_vio.v" \


vlog -work xil_defaultlib \
"glbl.v"

