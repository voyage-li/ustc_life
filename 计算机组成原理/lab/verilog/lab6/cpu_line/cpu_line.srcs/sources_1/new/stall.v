module stall(
    input MemRead_EX, Branch_ID, RegWrite_EX, RegWrite_MEM, RegWrite_WB,
    input [31:0] ins_EX,
    input [31:0] ins_ID,
    input [31:0] ins_MEM,
    input [31:0] ins_WB,
    output reg pc_write, IF_ID_write, control_mux, jump
);
    always@(*) begin
        if(MemRead_EX && (ins_EX[11:7]==ins_ID[19:15]||ins_EX[11:7]==ins_ID[24:20])) begin
            pc_write = 0;
            IF_ID_write = 0;
            control_mux = 1;
            jump = 0;
        end
        else if(Branch_ID && RegWrite_EX && (ins_EX[11:7]==ins_ID[19:15]||ins_EX[11:7]==ins_ID[24:20])) begin
            pc_write = 0;
            IF_ID_write = 0;
            control_mux = 1;
            jump = 0;
        end
        else if(Branch_ID && RegWrite_MEM && (ins_MEM[11:7]==ins_ID[19:15]||ins_MEM[11:7]==ins_ID[24:20])) begin
            pc_write = 0;
            IF_ID_write = 0;
            control_mux = 1;
            jump = 0;
        end
        // else if(Branch_ID && RegWrite_WB && (ins_WB[11:7]==ins_ID[19:15]||ins_WB[11:7]==ins_ID[24:20])) begin
        //     pc_write = 0;
        //     IF_ID_write = 0;
        //     control_mux = 1;
        //     jump = 0;
        // end
        else if(Branch_ID) begin
            pc_write = 1;
            IF_ID_write = 1;
            control_mux = 0;
            jump = 1;
        end
        else begin
            pc_write = 1;
            IF_ID_write = 1;
            control_mux = 0;
            jump = 0;
        end
    end
endmodule