`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/03/20 21:11:17
// Design Name: 
// Module Name: fls
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


module  fls (
  input  clk, rst, en,
  input  [6:0]  d,
  output [6:0]  f
);

    reg [1:0] cs,ns;
    reg state1;
    reg state2;
    reg [6:0] reg_a, reg_b;
    wire button_edge;
    
    //生成脉冲信号
    reg button_r1,button_r2;    
    always@(posedge clk)
        button_r1 <= en;
    always@(posedge clk)
        button_r2 <= button_r1; 
    assign button_edge = button_r1 & (~button_r2);

    parameter s0 = 2'b00;
    parameter s1 = 2'b01;
    parameter s2 = 2'b10;
    
    //初始化
    initial begin
        state1 = 0;
        state2 = 0;
        cs <= s0;
        reg_a <= 0;
        reg_b = 0;
    end
    //状态机
    always@ (posedge clk)
        if (rst)
            cs <= s0; 
        else
            cs <= ns;

    always @(*) begin
        case (cs)
            s0:
                if(state1 == 1)
                    ns = s1;
                else
                    ns = s0;
            s1: if(state2 == 1)
                    ns = s2;
                else
                    ns = s1;
            s2: ns = s2; 
            default: ns = s0;
        endcase
    end
 
    wire [6:0] sum;
    alu #(7) alu(reg_a,reg_b,0,sum);

    always @(posedge clk) 
    begin
        if(rst) begin
            state1 <= 0;
            state2 <= 0;
            reg_a <= 0;
            reg_b <= 0;
        end
        else if(button_edge) begin
            case(cs)
                s0: begin
                        reg_b <= d ;
                        reg_a <= reg_b;
                        state1 = ~state1;
                    end
                s1 : 
                    begin
                        reg_b <= d ;
                        reg_a <= reg_b;
                        state2 = ~state2;
                    end
                s2: begin
                        reg_b <= sum; 
                        reg_a <= reg_b; 
                    end
            endcase
        end
    end     


    assign f = reg_b;

endmodule
