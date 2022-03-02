module test (input clk,
             rst,
             output led;);
    reg [1:0] curr_state;
    reg [1:0] next_state;
    parameter C_0 = 2'b00;
    parameter C_1 = 2'b01;
    parameter C_2 = 2'b10;
    parameter C_3 = 2'b11;
    always @(*) begin
        case (curr_state)
            C_0 : next_state    = C_1;
            C_1 : next_state    = C_2;
            C_2 : next_state    = C_3;
            C_3 : next_state    = C_0;
            default: next_state = C_0;
        endcase
    end
    always @(posedge clk or posedge rst)
    begin
        if (rst)
            curr_state <= C_0;
        else
            curr_state <= next_state;
    end
    assign led = (curr_state == 2'b11)?1'b1:1'b0;
endmodule
