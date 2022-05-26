module ID_EX(
    input clk,rst,
    input en,
    input [31:0] ins,
    input [31:0] immediate,
    input [31:0] pc,
    input [31:0] pc_4,
    input [31:0] rd1,rd2,
    output reg [31:0] ins_o,
    output reg [31:0] pc_o,
    output reg [31:0] pc_4_o,
    output reg [31:0] immediate_o,
    output reg [31:0] rd1_o,rd2_o,
    input Branch, MemRead, MemWrite, RegWrite, ALUsrc, jal, auipc_mux,
    input [1:0] MemtoReg,
    input [2:0] ALUop,
    output reg Branch_o, MemRead_o, MemWrite_o, RegWrite_o, ALUsrc_o, jal_o, auipc_mux_o,
    output reg [1:0] MemtoReg_o,
    output reg [2:0] ALUop_o
);

    reg [31:0] ins_t, pc_t, pc_4_t,immediate_t,rd1_t,rd2_t;
    reg Branch_t, MemRead_t, MemWrite_t, RegWrite_t, ALUsrc_t, jal_t;
    reg [1:0]  MemtoReg_t;
    reg [2:0] ALUop_t;

    always@(posedge clk or posedge rst) begin
        if(rst || en) begin
            // ins_t <= 32'b0;
            // pc_t <= 32'b0;
            // pc_4_t <= 32'b0;
            // immediate_t <= 32'b0;
            // rd1_t <= 32'b0;
            // rd2_t <= 32'b0;
            // Branch_t <= 0;
            // MemRead_t <= 0;
            // MemWrite_t <= 0;
            // RegWrite_t <= 0;
            // ALUsrc_t <= 0;
            // jal_t <= 0;
            // ALUop_t <= 2'b00;
            // MemtoReg_t <= 2'b00;

            ins_o <= 0;
            pc_o <= 0;
            pc_4_o <= 0;
            immediate_o <= 0;
            rd1_o <= 0;
            rd2_o <= 0;
            Branch_o <= 0;
            MemRead_o <= 0;
            MemWrite_o <= 0;
            RegWrite_o <= 0;
            ALUsrc_o <= 0;
            jal_o <= 0;
            ALUop_o <= 0;
            MemtoReg_o <= 0;
            auipc_mux_o <= 0;
        end
        else begin
            // ins_t <= ins;
            // pc_t <= pc;
            // pc_4_t <= pc_4;
            // immediate_t <= immediate;
            // rd1_t <= rd1;
            // rd2_t <= rd2;
            // Branch_t <= Branch;
            // MemRead_t <= MemRead;
            // MemWrite_t <= MemWrite;
            // RegWrite_t <= RegWrite;
            // ALUsrc_t <= ALUsrc;
            // jal_t <= jal;
            // ALUop_t <= ALUop;
            // MemtoReg_t <= MemtoReg;

            ins_o <= ins;
            pc_o <= pc;
            pc_4_o <= pc_4;
            immediate_o <= immediate;
            rd1_o <= rd1;
            rd2_o <= rd2;
            Branch_o <= Branch;
            MemRead_o <= MemRead;
            MemWrite_o <= MemWrite;
            RegWrite_o <= RegWrite;
            ALUsrc_o <= ALUsrc;
            jal_o <= jal;
            ALUop_o <= ALUop;
            MemtoReg_o <= MemtoReg;

            auipc_mux_o <= auipc_mux;
        end
    end
endmodule