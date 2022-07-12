`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/03/22 18:42:25
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
reg clk;
reg en;
reg [1:0] sel;
reg [5:0] x;	
wire [5:0] y; 	
wire z ;

alu alu(clk,en,sel,x,y,z);

initial begin
    clk=0;
    forever #5 clk=~clk;
end

initial begin
    en=0;
    #10 en=1;
end

initial begin
    sel = 2'b00;;
    #20 sel = 2'b01;
    #20 sel = 2'b10;
end

initial begin
     x = 6'b000011;
     #20 x = 6'b000010;
     #20 x = 6'b000000;
     #20 x = 6'b000000;
     #20 x = 6'b000001;
     #20 x = 6'b000010;
     #20 x = 6'b000011;
     #20 x = 6'b000100;
end

endmodule
