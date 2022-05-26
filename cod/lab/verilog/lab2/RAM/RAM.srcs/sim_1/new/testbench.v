`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/03/26 13:35:45
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
    
    reg clk = 0 ;
    reg we1 = 0 ;
    reg [7:0] d1 = 0 ;
    reg [3:0] a1 = 0 ;
    wire [7:0] spo1 ;
    
    reg ena = 0;
    reg wea =0;
    wire [7:0] dout_w,dout_r,dout;
    
    dist_mem_gen_0 test_dis1 (
      .a(a1),
      .d(d1),
      .clk(clk),
      .we(we1),
      .spo(spo1)
    );
    
    blk_mem_gen_0 your_instance_name (
      .clka(clk),
      .ena(ena),
      .wea(wea),
      .addra(a1), 
      .dina(d1),
      .douta(dout_r)
    );
    
    blk_mem_gen_1 your_instance_name_1 (
      .clka(clk),
      .ena(ena),
      .wea(wea),
      .addra(a1), 
      .dina(d1),
      .douta(dout_w)
    );
    
    blk_mem_gen_2 your_instance_name_2 (
      .clka(clk),
      .ena(ena),
      .wea(wea),
      .addra(a1), 
      .dina(d1),
      .douta(dout)
    );
     
    initial ena = 1;
    initial begin
        wea = 0;
        forever #15 wea = ~wea;
    end
     
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end
    
    initial begin
        we1 = 0;
        #20 we1 = 1;
        #20 we1 = 0;
    end
    
    initial begin
        #20 d1 = 8'd21;
        #20 d1 = 8'd32;
        forever #20 d1 = d1 + 1;
    end
    
    initial begin
        a1 = 0;
        forever #10 a1 = a1 + 1;
    end
    

endmodule
