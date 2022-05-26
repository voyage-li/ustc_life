`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/03/26 18:16:41
// Design Name: 
// Module Name: LCU
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


module LCU(
    input clk, rst,
    input [3:0] in, rd0,
    input enq, deq,
    output reg [3:0] out,
    output full, emp, we,
    output [2:0] ra0, wa,
    output [3:0] wd,
    output reg [7:0] valid
);

    assign wa = tail;
    assign wd = in;
    assign we = enq;
    assign ra0 = head;

    parameter IDLE = 2'b00;
    parameter ENQU = 2'b01;
    parameter DEQU = 2'b10;

    reg [1:0] cs, ns;
    reg [2:0] head, tail;
    reg [3:0] count;

    always@(posedge clk) begin
        if (rst == 1)
            cs <= IDLE;
        else
            cs <= ns;
    end

    always @(*) begin
        case (cs)
            IDLE: begin
                if (enq & !full)
                    ns <= ENQU;
                else if (deq & !emp)
                    ns <= DEQU;
                else
                    ns <= IDLE;
            end
            ENQU: ns <= IDLE;
            DEQU: ns <= IDLE;
        endcase
    end

    always@(posedge clk)begin
        if (rst == 1) begin
            tail <= 0;
            head <= 0;
            valid <= 0;
            count <= 0;
            out <= 0;
        end
        else if (cs == ENQU) begin
            valid[tail] <= 1;
            tail <= tail + 1;
            count <= count + 1;
        end
        else if (cs == DEQU) begin
            valid[head] <= 0;
            head <= head + 1;
            count <= count - 1;
            out <= rd0;
        end
    end
    
    assign full = (count == 4'd8) ? 1 : 0;
    assign emp = (count == 4'd0) ? 1 : 0;
    
    
endmodule
