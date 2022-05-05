module testbench();

reg run, step, valid, rst, clk;
reg [4:0] in;
wire [1:0] check;
wire [4:0] out0;
wire ready;
wire [2:0] an;
wire [3:0] seg;
wire jump;
wire [31:0] pcin, pc, pcd, pce;
wire [31:0] ir, imm, mdr;
wire [31:0] a, b, y, bm, yw;
wire [4:0] rd, rdm, rdw;
wire [31:0] ctrl, ctrlm, ctrlw;

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
    .seg(seg),
    .pcin(pcin),
    .pc(pc),
    .pcd(pcd),
    .pce(pce),
    .ir(ir),
    .imm(imm),
    .mdr(mdr),
    .a(a),
    .b(b),
    .y(y),
    .bm(bm),
    .yw(yw),
    .rd(rd),
    .rdm(rdm),
    .rdw(rdw),
    .ctrl(ctrl),
    .ctrlm(ctrlm),
    .ctrlw(ctrlw),
    .jump(jump)
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

endmodule
