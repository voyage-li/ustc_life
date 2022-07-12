module control(
    input [6:0] opcode,
    input [2:0] funct3,
    output reg Branch, MemRead, MemWrite, RegWrite, ALUsrc, jal, auipc_mux,jalr,
    output reg [1:0] MemtoReg,
    output reg [2:0] ALUop
);    
    always @(*) begin
        case(opcode)
            7'b0010111: begin
                Branch = 0;
                MemRead = 0;
                MemWrite = 0;
                RegWrite = 1;
                ALUsrc = 0;
                ALUop = 3'b000;
                jal = 0;
                MemtoReg = 2'b0;
                auipc_mux = 1;
                jalr=0;
            end
            7'b0110011: begin   //add, sub, and, or, xor, sll, srl, slt
                Branch = 0;
                MemRead = 0;
                MemWrite = 0;
                RegWrite = 1;
                ALUsrc = 0;
                ALUop = 3'b111;
                jal = 0;
                MemtoReg = 2'b0;
                auipc_mux = 0;
                jalr=0;
            end
            7'b0010011: begin   //addi, andi, ori, xori, slli, srli
                Branch = 0;
                MemRead = 0;
                MemWrite = 0;
                RegWrite = 1;
                ALUsrc = 1;
                if(funct3 == 3'b000)
                    ALUop = 3'b000;
                else if (funct3 == 3'b111)
                    ALUop = 3'b010;
                else if (funct3 == 3'b110)
                    ALUop = 3'b011;
                else if (funct3 == 3'b100)
                    ALUop = 3'b100;
                else if (funct3 == 3'b001)
                    ALUop = 3'b101;
                else if (funct3 == 3'b101)
                    ALUop = 3'b110;
                else if(funct3 == 3'b010)
                    ALUop = 3'b111;
                jal = 0;
                MemtoReg = 2'b0;
                auipc_mux = 0;
                jalr=0;
            end
            7'b0000011: begin   //lw
                Branch = 0;
                MemRead = 1;
                MemWrite = 0;
                RegWrite = 1;
                ALUsrc = 1;
                ALUop = 3'b00;
                jal = 0;
                MemtoReg = 2'b01;
                auipc_mux = 0;
                jalr=0;
            end
            7'b0100011: begin   //sw
                Branch = 0;
                MemRead = 0;
                MemWrite = 1;
                RegWrite = 0;
                ALUsrc = 1;
                ALUop = 3'b00;
                jal = 0;
                MemtoReg = 2'b0;
                auipc_mux = 0;
                jalr=0;
            end
            7'b1100011: begin   //beq,blt
                Branch = 1;
                MemRead = 0;
                MemWrite = 0;
                RegWrite = 0;
                ALUsrc = 0;
                ALUop = 3'b01;
                jal = 0;
                MemtoReg = 2'b0;
                auipc_mux = 0;
                jalr=0;
            end
            7'b1101111: begin   //jal
                Branch = 0;
                MemRead = 0;
                MemWrite = 0;
                RegWrite = 1;
                ALUsrc = 0;
                ALUop = 3'b00;
                jal = 1;
                MemtoReg = 2'b10;
                auipc_mux = 0;
                jalr=0;
            end
            7'b1100111: begin   //jal
                Branch = 0;
                MemRead = 0;
                MemWrite = 0;
                RegWrite = 1;
                ALUsrc = 0;
                ALUop = 3'b00;
                jal = 0;
                MemtoReg = 2'b10;
                auipc_mux = 0;
                jalr = 1;
            end
            default: begin
                Branch = 0;
                MemRead = 0;
                MemWrite = 0;
                RegWrite = 0;
                ALUsrc = 0;
                ALUop = 3'b00;
                jal = 0;
                MemtoReg = 2'b0;
                auipc_mux = 0;
                jalr=0;
            end
        endcase
    end
endmodule