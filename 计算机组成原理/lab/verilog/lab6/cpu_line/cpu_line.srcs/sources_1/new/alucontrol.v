module alucontrol (
    input [2:0] ALUOp,
    input [6:0] funct7,
    input [2:0] funct3,
    output reg [2:0] ALUout
);
    always@(*) begin
        case(ALUOp)
            3'b000: ALUout=3'b000;
            3'b001: ALUout=3'b001;
            3'b010: ALUout=3'b010;
            3'b011: ALUout=3'b011;
            3'b100: ALUout=3'b100;
            3'b101: ALUout=3'b101;
            3'b110: ALUout=3'b110;
            3'b111: begin
                if(funct3 == 3'b000)// add
                    ALUout = 3'b000;
                else if(funct3 == 3'b000)// sub
                    ALUout = 3'b001;
                else if(funct3 == 3'b111)// and
                    ALUout = 3'b010;
                else if(funct3 == 3'b110)// or
                    ALUout = 3'b011;
                else if(funct3 == 3'b100)// xor
                    ALUout = 3'b100;
                else if(funct3 == 3'b001)// sll
                    ALUout = 3'b101;
                else if(funct3 == 3'b101)// srl
                    ALUout = 3'b110;
                else if(funct3 == 3'b010)// slt
                    ALUout = 3'b111;
                else
                    ALUout = 3'b111;
            end
            default: ALUout = 3'b000;
        endcase
    end
endmodule