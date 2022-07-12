`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/03/20 22:03:47
// Design Name: 
// Module Name: testbench
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


module testbench();
    reg clk,rst,en;
    reg [6:0]d;
    wire [6:0]f;
    fls fls(.clk(clk),.rst(rst),.en(en),.d(d),.f(f));
   
    initial begin
    clk=0;
    forever #0.5 clk=~clk;
    end
    
    initial begin
    rst=1;
    #8 rst=0;
    end
    
    initial begin
    d = 7'b0000001;
    #40 d=7'b0000010;
    end
    
    initial begin
    en=0;
    #25 en=1;
    forever #8 en=~en;
    end
    
endmodule
