module IF_ID(
    input clk,rst,
    input [31:0] ins,
    input [31:0] pc,
    input [31:0] pc_4,
    input en,
    input jump,
    output reg [31:0] ins_o,
    output reg [31:0] pc_o,
    output reg [31:0] pc_4_o
);

    reg [31:0] ins_t, pc_t, pc_4_t;

    always@(posedge clk or posedge rst) begin
        if(rst || jump) begin
            // ins_t <= 32'b0;
            // pc_t <= 32'b0;
            // pc_4_t <= 32'b0;

            ins_o <= 0;
            pc_o <= 0;
            pc_4_o <= 0;
        end
        else if (en) begin
            // ins_t <= ins;
            // pc_t <= pc;
            // pc_4_t <= pc_4;

            ins_o <= ins;
            pc_o <= pc;
            pc_4_o <= pc_4;
        end  
    end
endmodule