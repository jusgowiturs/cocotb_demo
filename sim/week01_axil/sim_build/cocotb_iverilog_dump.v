module cocotb_iverilog_dump();
initial begin
    $dumpfile("sim_build/axil_regbank.fst");
    $dumpvars(0, axil_regbank);
end
endmodule
