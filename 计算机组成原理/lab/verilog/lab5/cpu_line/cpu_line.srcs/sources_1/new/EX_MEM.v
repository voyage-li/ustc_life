module EX_MEM(
    input clk,rst,
    input [31:0] pc_4,
    input [31:0] pc_offset,
    input [31:0] alu_result,
    input alu_zero,
    input [31:0] rd2,
    input [31:0] ins, 
    output reg [31:0] pc_4_o,
    output reg [31:0] pc_offset_o,
    output reg [31:0] alu_result_o,
    output reg alu_zero_o,
    output reg [31:0] rd2_o,
    output reg [31:0] ins_o,

    input Branch, MemRead, MemWrite, RegWrite, jal,
    input [1:0]  MemtoReg,
    output reg Branch_o, MemRead_o, MemWrite_o, RegWrite_o, jal_o,
    output reg [1:0]  MemtoReg_o
);

    reg [31:0] pc_4_t, pc_offset_t, alu_result_t, rd2_t, ins_t;
    reg alu_zero_t;
    reg Branch_t, MemRead_t, MemWrite_t, RegWrite_t, jal_t;
    reg [1:0] MemtoReg_t;

    always@(posedge clk or posedge rst) begin
        if(rst) begin
            // pc_4_t <= 32'b0;
            // pc_offset_t <= 32'b0;
            // alu_result_t <= 32'b0;
            // rd2_t <= 32'b0;
            // ins_t <= 32'b0;
            // alu_zero_t <= 0;

            // Branch_t <= 0;
            // MemRead_t <= 0;
            // MemWrite_t <= 0;
            // RegWrite_t <= 0;
            // jal_t <= 0;
            // MemtoReg_t <= 2'b00;

            pc_4_o <= 0;
            pc_offset_o <= 0;
            alu_result_o <= 0;
            rd2_o <= 0;
            ins_o <= 0;
            alu_zero_o <= 0;

            Branch_o <= 0;
            MemRead_o <= 0;
            MemWrite_o <= 0;
            RegWrite_o <= 0;
            jal_o <= 0;
            MemtoReg_o <= 0;
        end
        else begin
            // pc_4_t <= pc_4;
            // pc_offset_t <= pc_offset;
            // alu_result_t <= alu_result;
            // rd2_t <= rd2;
            // ins_t <= ins;
            // alu_zero_t <= alu_zero;

            // Branch_t <= Branch;
            // MemRead_t <= MemRead;
            // MemWrite_t <= MemWrite;
            // RegWrite_t <= RegWrite;
            // jal_t <= jal;
            // MemtoReg_t <= MemtoReg;

            pc_4_o <= pc_4;
            pc_offset_o <= pc_offset;
            alu_result_o <= alu_result;
            rd2_o <= rd2;
            ins_o <= ins;
            alu_zero_o <= alu_zero;

            Branch_o <= Branch;
            MemRead_o <= MemRead;
            MemWrite_o <= MemWrite;
            RegWrite_o <= RegWrite;
            jal_o <= jal;
            MemtoReg_o <= MemtoReg;
        end
    end
endmodule