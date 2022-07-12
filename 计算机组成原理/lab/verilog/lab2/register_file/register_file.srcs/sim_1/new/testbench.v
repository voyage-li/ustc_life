`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/03/26 11:37:34
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
    parameter WIDTH = 5;
    reg clk;
    reg [4:0] ra0;
    wire [WIDTH-1:0] rd0;
    reg [4:0] ra1;
    wire[WIDTH-1:0] rd1;
    reg [4:0] wa;
    reg we;
    reg [WIDTH-1:0] wd;
    
    register_file #(5) register_file(clk,ra0,rd0,ra1,rd1,wa,we,wd);
    
    initial begin
        clk = 0;
        forever #1 clk = ~clk;
    end
    
    initial begin
        ra0 = 5'b00001;
        forever #10 ra0 = ra0 + 1;
    end
    
    initial begin
        ra1 = 5'b11111;
        forever #10 ra1 = ra1 - 1;
    end
    
    initial begin
        we = 0;
        forever #25 we = ~we;
    end
    
    initial begin
        wd = 32'd200;
        forever #10 wd = wd - 1;
    end
    
    initial begin
        wa = 5'b00000;
        forever #10 wa = wa + 1;
    end
    
endmodule
