module control(
    input [6:0] ins,
    output reg Branch, MemRead, MemWrite, RegWrite, ALUsrc, jal,
    output reg [1:0] ALUop, MemtoReg
);    
    always @(*) begin
        case(ins)
            7'b0110011: begin   //add
                Branch = 0;
                MemRead = 0;
                MemWrite = 0;
                RegWrite = 1;
                ALUsrc = 0;
                ALUop = 2'b10;
                jal = 0;
                MemtoReg = 2'b0;
            end
            7'b0010011: begin   //addi
                Branch = 0;
                MemRead = 0;
                MemWrite = 0;
                RegWrite = 1;
                ALUsrc = 1;
                ALUop = 2'b10;
                jal = 0;
                MemtoReg = 2'b0;
            end
            7'b0000011: begin   //lw
                Branch = 0;
                MemRead = 1;
                MemWrite = 0;
                RegWrite = 1;
                ALUsrc = 1;
                ALUop = 2'b00;
                jal = 0;
                MemtoReg = 2'b01;
            end
            7'b0100011: begin   //sw
                Branch = 0;
                MemRead = 0;
                MemWrite = 1;
                RegWrite = 0;
                ALUsrc = 1;
                ALUop = 2'b00;
                jal = 0;
                MemtoReg = 2'b0;
            end
            7'b1100011: begin   //beq
                Branch = 1;
                MemRead = 0;
                MemWrite = 0;
                RegWrite = 0;
                ALUsrc = 0;
                ALUop = 2'b01;
                jal = 0;
                MemtoReg = 2'b0;
            end
            7'b1101111: begin   //jal
                Branch = 0;
                MemRead = 0;
                MemWrite = 0;
                RegWrite = 1;
                ALUsrc = 0;
                ALUop = 2'b00;
                jal = 1;
                MemtoReg = 2'b10;
            end
            default: begin
                Branch = 0;
                MemRead = 0;
                MemWrite = 0;
                RegWrite = 0;
                ALUsrc = 0;
                ALUop = 2'b00;
                jal = 0;
                MemtoReg = 2'b0;
            end
        endcase
    end
endmodule