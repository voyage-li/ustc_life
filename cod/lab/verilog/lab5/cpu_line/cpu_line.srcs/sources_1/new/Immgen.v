module Immgen(
    input [31:0] instruction,
    output reg [31:0] immediate
);
    always @(*) begin
        if(instruction[6:0]==7'b0010011)    //addi  
            immediate = {{20{instruction[31]}},instruction[31:20]};
        else if(instruction[6:0]==7'b0000011)    //lw
            immediate = {{20{instruction[31]}},instruction[31:20]};
        else if(instruction[6:0]==7'b0100011)    //sw
            immediate = {{20{instruction[31]}},instruction[31:25],instruction[11:7]};
        else if(instruction[6:0]==7'b1100011)    //beq,blt
            immediate = {{20{instruction[31]}},instruction[31],instruction[7],instruction[30:25],instruction[11:8]};
        else if(instruction[6:0]==7'b1101111)    //jal
            immediate = {{12{instruction[31]}},instruction[31],instruction[19:12],instruction[20],instruction[30:21]};
        else if(instruction[6:0]==7'b1100111)    //jalr
            immediate = {{20{instruction[31]}},instruction[31:20]};
        else if(instruction[6:0]==7'b0010111)    //auipc
            immediate = {instruction[31:12],12'b0};
        else
            immediate = instruction;
    end
endmodule
