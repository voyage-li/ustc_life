`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/03/26 18:38:13
// Design Name: 
// Module Name: SEDG
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

module SEDG(
        input a,
        input clk,
        output p    //
    );
    reg st, pt, s;
    always@(posedge clk)
        st <= a;
    always@(posedge clk)
        s <= st;
    always@(posedge clk)
        pt <= s;
    assign p = (~pt) & s;
endmodule
