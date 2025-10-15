vlib modelsim_lib/work
vlib modelsim_lib/msim

vlib modelsim_lib/msim/xil_defaultlib

vmap xil_defaultlib modelsim_lib/msim/xil_defaultlib

vlog -work xil_defaultlib  -incr -mfcu  "+incdir+../../../../project_1.gen/sources_1/ip/top_vio/hdl/verilog" "+incdir+../../../../project_1.gen/sources_1/ip/top_vio/hdl" \
"../../../../project_1.gen/sources_1/ip/top_vio/sim/top_vio.v" \


vlog -work xil_defaultlib \
"glbl.v"

