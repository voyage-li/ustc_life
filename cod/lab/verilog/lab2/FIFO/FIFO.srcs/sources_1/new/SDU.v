`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/03/26 18:58:53
// Design Name: 
// Module Name: SDU
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


module SDU(
        input rst, clk,
        input [3:0] rd,
        input [7:0] valid,
        output [2:0] ra,
        output [2:0] an,
        output [3:0] seg
    );

    reg [23:0] count;

    assign an = ra;
    assign ra = count[12:10];

    always@(posedge clk)
    begin
        if (rst) begin
            count <= 24'd0;
        end else begin
            count <= count + 1;
        end
    end    

    assign seg = valid[ra] ? rd : 0;
    
    
endmodule
