module MEM_WB(
    input clk,rst,
    input [31:0] alu_result,
    input [31:0] ins,
    input [31:0] MemReadData,
    input [31:0] pc_4,
    output reg [31:0] alu_result_o,
    output reg [31:0] ins_o,
    output reg [31:0] MemReadData_o,
    output reg [31:0] pc_4_o,

    input RegWrite,
    input [1:0]  MemtoReg,
    output reg RegWrite_o,
    output reg [1:0]  MemtoReg_o
);

    reg [31:0] alu_result_t, ins_t, MemReadData_t, pc_4_t;

    reg RegWrite_t;
    reg [1:0] MemtoReg_t;

    always@(posedge clk or posedge rst) begin
        if(rst) begin
            // alu_result_t <= 32'b0;
            // ins_t <= 32'b0;
            // MemReadData_t <= 32'b0;
            // pc_4_t <= 32'b0;

            // RegWrite_t <= 0;
            // MemtoReg_t <= 2'b00;

            alu_result_o <= 0;
            ins_o <= 0;
            MemReadData_o <= 0;
            pc_4_o <= 0;
            RegWrite_o <= 0;
            MemtoReg_o <= 0;
        end
        else begin
            // alu_result_t <= alu_result;
            // ins_t <= ins;
            // MemReadData_t <= MemReadData;
            // pc_4_t <= pc_4;
            // RegWrite_t <= RegWrite;
            // MemtoReg_t <= MemtoReg;

            alu_result_o <= alu_result;
            ins_o <= ins;
            MemReadData_o <= MemReadData;
            pc_4_o <= pc_4;
            RegWrite_o <= RegWrite;
            MemtoReg_o <= MemtoReg;
        end
    end

endmodule