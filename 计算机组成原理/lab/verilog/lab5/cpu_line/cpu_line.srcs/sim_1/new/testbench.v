module testbench();

reg run, step, valid, rst, clk;
reg [4:0] in;
wire [1:0] check;
wire [4:0] out0;
wire ready;
wire [2:0] an;
wire [3:0] seg;

top top(
    .run(run),
    .step(step),
    .valid(valid),
    .rst(rst),
    .clk(clk),
    .in(in),
    .check(check),
    .out0(out0),
    .ready(ready),
    .an(an),
    .seg(seg)
);


initial begin
    clk = 0;
    forever #0.1 clk = ~clk;
end

initial begin
    rst = 1;
    #20 rst = 0;
end

initial begin
    run = 0;
    valid = 0;
    step = 0;
    forever #15 begin
        step = 0;
        #3 step = 1;
        #3 step = 0;
    end
end

initial begin
    in = 5'd10;
end

// initial begin
//     step = 0;
//     run = 0;
//     #30 run = 1;
// end

// initial begin
//     valid = 0;
//     #30 valid = 1;
//     forever #15 valid = ~valid;
// end

// initial begin
//     in = 5'd2;
//     #40 in =5 'd3;
// end

endmodule
