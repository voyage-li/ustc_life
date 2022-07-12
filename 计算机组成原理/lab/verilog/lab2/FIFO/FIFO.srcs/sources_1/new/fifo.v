`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/03/26 17:38:28
// Design Name: 
// Module Name: fifo
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


module fifo(
    input clk, rst,     //时钟（上升沿有效）、同步复位（高电平有效）
    input enq, 		    //入队列使能，高电平有效
    input [3:0] in,	    //入队列数据
    input deq,		    //出队列使能，高电平有效
    output [3:0] out, 	//出队列数据
    output [2:0] an,	//数码管选择
    output [3:0] seg,	//数码管数据
    output full,emp
);
    wire [2:0]ra0, ra1, wa;
    wire [3:0]rd0, rd1, wd;
    wire we_0,we;
    wire enq_edge;
    wire deq_edge;
    wire [7:0] valid;
    wire [3:0] out_;
    
    SEDG edg_enq(enq, clk, enq_edge);
    SEDG edg_deq(deq, clk, deq_edge);
    
    LCU LCU(clk, rst, in, rd0, enq_edge, deq_edge, out_, full, emp, we_0, ra0, wa, wd, valid);
    
    register_file regfile(clk, ra0, rd0, ra1, rd1, wa, we, wd);
    
    SDU SDU(rst, clk, rd1, valid, ra1, an, seg);
    
    assign we = (full == 1) ? 0 : we_0;
    assign out = (emp == 1) ? 0 : out_;

endmodule

