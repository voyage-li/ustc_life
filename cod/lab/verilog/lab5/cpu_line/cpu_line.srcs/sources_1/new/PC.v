module pc(
    input [31:0] in,
    input rst,
    input clk,
    input en,
    output reg [31:0] out
);
    always @(posedge clk or posedge rst) begin
        if (rst)
            out <= 32'h3000;
        else if (en)
            out <= in;
    end
endmodule
