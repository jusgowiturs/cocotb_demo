vlib questa_lib/work
vlib questa_lib/msim

vlib questa_lib/msim/xil_defaultlib

vmap xil_defaultlib questa_lib/msim/xil_defaultlib

vlog -work xil_defaultlib  -incr -mfcu  "+incdir+../../../../project_1.gen/sources_1/ip/top_vio/hdl/verilog" "+incdir+../../../../project_1.gen/sources_1/ip/top_vio/hdl" \
"../../../../project_1.gen/sources_1/ip/top_vio/sim/top_vio.v" \


vlog -work xil_defaultlib \
"glbl.v"

