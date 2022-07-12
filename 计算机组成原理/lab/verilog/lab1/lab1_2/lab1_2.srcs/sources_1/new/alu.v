`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/03/16 22:30:11
// Design Name: 
// Module Name: alu
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


module alu(
    input clk,
    input  en,
    input  [1:0] sel,
    input  [5:0] x,		
    output  reg [5:0] y, 	
    output  reg z 
);
    reg ena,enb,ef;
    reg [5:0] a;
    reg [5:0] b;
    reg [2:0] f;
    always@(*)
    begin
        if(en==0) begin
            ena=0;
            enb=0;
            ef=0;
        end
        else if(sel==2'b00) begin
            ena=1;
            enb=0;
            ef=0;
        end
        else if(sel==2'b01) begin
            ena=0;
            enb=1;
            ef=0;
        end
        else if(sel==2'b10) begin
            ena=0;
            enb=0;
            ef=1;
        end
        else begin
            ena=0;
            enb=0;
            ef=0;
        end
    end
    
    always@(posedge clk) begin
        if(ef==1)
            f=x[2:0];
        else if (ena==1)
            a=x;
        else if (enb==1)
            b=x;                
    end
    
    reg [5:0] y_ans;
    reg z_ans;
    always@(*)
    begin
        case(f)
            3'b000: y_ans=a+b;
            3'b001: y_ans=a-b;
            3'b010: y_ans=a&b;
            3'b011: y_ans=a|b;
            3'b100: y_ans=a^b;
            default: y_ans=1'b0;
        endcase
        if(y_ans==1'b0)
            z_ans=1;
        else
            z_ans=0;
    end
    
    always@(posedge clk) begin
        y<=y_ans;
        z<=z_ans;
    end
endmodule

