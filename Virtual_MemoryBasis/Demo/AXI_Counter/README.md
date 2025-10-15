- Try to implement in hardware using AXI interface of verilog IP 
  - How to test
  - How to extract data
  - General idea of what you can do
- Step By Step
  - Create a New Vivado Project
  - Give Project Name and define or modify if required change your directory
  - Select your part name
    - xc7z020clg400-1
    - Finish
  - Create Block Design 
    - Under IP Integrator
      - Add ZYNQ ip core 
        - Click Run Automation make fixed io and DDR
    - Create and Package IP under Tools
      - Create AXI4 lite for peripherals
        - Give name of it
        - For me It is located at D:/BS_ES/EL_FPGA/Demo/AXI_Counter/project_1/../ip_repo
        - I picked number of register as 7 each 32 bit wide
      - Click EDIT IP 
        - Since there is noting designer required things inside
          - It makes to create an another project by itself
        - Output wire should be properly configued and instateate
          - ```verilog
          	// Add user logic here
Counter mycounter(
.clk(S_AXI_ACLK),
.rst(S_AXI_ARESETN),
.enable(slv_reg0[0]),
.load(slv_reg1[0]),
.din(slv_reg2),
.count(count_out));
	// User logic ends
always @(posedge S_AXI_ACLK) begin
    if (~S_AXI_ARESETN)
        slv_reg6 <= 0;
    else
        slv_reg6 <= count_out;
end
            ```



- [Custom IP with Memory Mapped IO](https://www.youtube.com/watch?v=MbteffkRi8Y)