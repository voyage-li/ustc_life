module top(
    input run, step, valid, rst, clk,
    input [4:0] in,
    output [1:0] check,
    output [4:0] out0,
    output ready,
    output [2:0] an,
    output [3:0] seg

    // output [7:0] io_addr,
    // output [31:0] io_dout,
    // output io_we,
    // output [31:0] io_din


        //IO_BUS
    // output [7:0] io_addr,
    // output [31:0] io_dout,
    // output io_we,
    // output [31:0] io_din,
    // output [31:0] pc,
    // output [31:0] instruction,next_pc,
    // output Branch, MemRead, MemWrite, RegWrite, ALU_rs1, ALU_rs2, jal, pc_mux,
    // output [31:0] pc_4,Read_data_1,Read_data_2,pc_offset,immediate_num
);
    
    wire clk_cpu;

    //IO_BUS
    wire [7:0] io_addr;
    wire [31:0] io_dout;
    wire io_we;
    wire [31:0] io_din;

    //Debug_BUS
    wire [7:0] m_rf_addr;
    wire [31:0] rf_data;
    wire [31:0] m_data;
    wire [31:0] pc;

    pdu_1cycle pdu(
        .clk(clk),
        .rst(rst),
        .run(run),
        .step(step),
        .clk_cpu(clk_cpu),
        .valid(valid),
        .in(in),
        .check(check),
        .out0(out0),
        .an(an),
        .seg(seg),
        .ready(ready),
        .io_addr(io_addr),
        .io_dout(io_dout),
        .io_we(io_we),
        .io_din(io_din),
        .m_rf_addr(m_rf_addr),
        .rf_data(rf_data),
        .m_data(m_data),
        .pc(pc)
    );

    cpu cpu(
        .clk(clk_cpu),
        .rst(rst),
        .io_addr(io_addr),
        .io_dout(io_dout),
        .io_we(io_we),
        .io_din(io_din),
        .m_rf_addr(m_rf_addr),
        .rf_data(rf_data),
        .m_data(m_data),
        .pc(pc)
    );
        //     .pc(pc),
        // .iii(instruction),
        // .next_pc(next_pc),
        // .Branch(Branch),
        // .MemRead(MemRead),
        // .MemWrite(MemWrite),
        // .ALU_rs1(ALU_rs1),
        // .ALU_rs2(ALU_rs2),
        // .RegWrite(RegWrite),
        // .pc_mux(pc_mux),
        // .jal(jal),
        // .pc_4(pc_4),
        // .Read_data_1(Read_data_1),
        // .Read_data_2(Read_data_2),
        // .pc_offset(pc_offset),
        // .immediate_num(immediate_num)

endmodule