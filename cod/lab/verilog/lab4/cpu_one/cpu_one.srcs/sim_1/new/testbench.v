`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/04/14 21:55:31
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

module test_bench();
reg run, step, valid, rst, clk;
reg [4:0] in;
wire [1:0] check;
wire [4:0] out0;
wire ready;
wire [2:0] an;
wire [3:0] seg;


// wire [7:0] io_addr;
// wire [31:0] io_dout;
// wire io_we;
// wire [31:0] io_din;
// wire [31:0] instruction,next_pc;
// wire [7:0] io_addr;
// wire [31:0] io_dout;
// wire io_we;
// wire [31:0] io_din, pc, instruction,next_pc,pc_4,Read_data_1,Read_data_2,pc_offset,immediate_num;
// wire Branch, MemRead, MemWrite, RegWrite, ALU_rs1, ALU_rs2, jal, pc_mux;
top top(run, step, valid, rst, clk,in,check,out0,ready,an,seg);//,io_addr,io_dout,io_we,io_din,pc,instruction,next_pc,Branch, MemRead, MemWrite, RegWrite, ALU_rs1, ALU_rs2, jal, pc_mux,pc_4,Read_data_1,Read_data_2,pc_offset,immediate_num

initial begin
    run = 1;
    step = 0;
end

initial begin
    clk = 0;
    forever begin
        #0.01 clk = ~clk;
    end
end

initial begin
    rst = 1;
    #10 rst = 0;
end

initial begin
    valid = 0;
    in = 3;
    #15 valid = 1;
    #10 valid = 0;
    #5 in = 5;
    #10 valid = 1;
    
    forever #5 valid = ~valid;
end

endmodule

