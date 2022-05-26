module Forwarding(
    input [31:0] ins_EX,
    input [31:0] ins_MEM,
    input [31:0] ins_WB,
    input RegWrite_MEM, RegWrite_WB,
    output reg [1:0] alu_rs1_mux_signal,
    output reg [1:0] alu_rs2_mux_signal
);

    always@(*) begin
        if(RegWrite_MEM && ins_MEM[11:7]==ins_EX[19:15])
            alu_rs1_mux_signal = 2'b01;
        else if(RegWrite_WB && ins_WB[11:7]==ins_EX[19:15])
            alu_rs1_mux_signal = 2'b10;
        else
            alu_rs1_mux_signal = 2'b00;

        if(RegWrite_MEM && ins_MEM[11:7]==ins_EX[24:20])
            alu_rs2_mux_signal = 2'b01;
        else if(RegWrite_WB && ins_WB[11:7]==ins_EX[24:20])
            alu_rs2_mux_signal = 2'b10;
        else 
            alu_rs2_mux_signal = 2'b00;
    end

endmodule
