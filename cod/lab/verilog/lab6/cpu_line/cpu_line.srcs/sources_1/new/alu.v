module alu(
    input  [31:0] a, b,
    input  [2:0] f,
    output reg z_r,
    output reg [31:0] y_r
);
    always@(*)begin
        case(f)
            3'b000: y_r = a + b;
            3'b001: y_r = a - b;
            3'b010: y_r = a & b;
            3'b011: y_r = a | b;
            3'b100: y_r = a ^ b;
            3'b101: y_r = a << b;
            3'b110: y_r = a >> b;
            3'b111: begin
                if (a<b)
                    y_r = 1;
                else
                    y_r = 0;
            end
            default: y_r = 0;
        endcase
        if (y_r == 0)
            z_r = 1;
        else
            z_r = 0;
    end

endmodule
