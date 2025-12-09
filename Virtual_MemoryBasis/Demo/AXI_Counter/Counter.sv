`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/09/2025 01:27:59 PM
// Design Name: 
// Module Name: Counter
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module updown_counter
(
input logic clk,
input logic rst_n,
input logic enable,
input logic load,
input logic up_down,
input logic [3:0] d_in,         
output logic [3:0] count
);
    
    always  @(posedge clk or negedge rst_n) begin
    if(rst_n == 0)
        count <= 0;
    else
    if(enable)
    begin
        if(load)
         count   <=    d_in;
        else begin
                if(up_down)
                    count   <=    count + 1;
                else
                    count   <=    count - 1;
            end    
    end
    end
    
    
endmodule

























