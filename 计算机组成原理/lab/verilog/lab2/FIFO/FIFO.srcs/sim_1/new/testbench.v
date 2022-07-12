`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/03/26 19:26:04
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
    reg clk, rst;
    reg enq;	    
    reg [3:0] in;	    
    reg deq;	    
    wire [3:0] out; 	
    wire [2:0] an;	
    wire [3:0] seg;	
    wire full,emp;
    fifo fifo(clk, rst, enq, in, deq, out, an, seg, full, emp);

    initial begin
        clk = 0;
        forever #0.001 clk = ~clk;
    end
    
    initial begin
        enq = 0;
        #15 enq = ~enq;
        #15 enq = ~enq;
        #13 enq = ~enq;
        #15 enq = ~enq;
        #15 enq = ~enq;
        #15 enq = ~enq;
        #15 enq = ~enq;
        #15 enq = ~enq;
        #15 enq = ~enq;
        #15 enq = ~enq;
        #15 enq = ~enq;
        #15 enq = ~enq;
    end

    initial begin
        deq = 0;
        #210 deq = ~deq;
        #15 deq = ~deq;
        #15 deq = ~deq;
        #15 deq = ~deq;
        #15 deq = ~deq;
        #15 deq = ~deq;
        #15 deq = ~deq;
        #15 deq = ~deq;
    end

    initial begin
        rst = 1;
        #10 rst = 0;
    end

    initial begin
        in = 1;
        forever #20 in = in + 1;
    end
endmodule
