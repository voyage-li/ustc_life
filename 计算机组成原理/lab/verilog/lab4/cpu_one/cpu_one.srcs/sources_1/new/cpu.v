module  cpu (
    input clk, 
    input rst,

    //IO_BUS
    output [7:0] io_addr,           
    output [31:0] io_dout,          
    output io_we,                   
    input [31:0] io_din,            

    //Debug_BUS
    input [7:0] m_rf_addr,         
    output [31:0] rf_data,          
    output [31:0] m_data,           
    output [31:0] pc
    // output [31:0] alu_op1, alu_op2, ALU_result
    
    // output [31:0] iii,next_pc,
    // output Branch, MemRead, MemWrite, RegWrite, ALU_rs1, ALU_rs2, jal, pc_mux,
    // output [31:0] pc_4,Read_data_1,Read_data_2,pc_offset,immediate_num
);


    wire [31:0] pc_next, pc_now, pc_4;
    wire [31:0] ins;
    wire [31:0] Read_data_1, Read_data_2;
    wire [31:0] Register_write;
    wire [31:0] immediate_num;
    wire [31:0] alu_op1, alu_op2, ALU_result;
    wire ALU_ZERO;
    wire [2:0] alu_control;

    wire Branch, MemRead, MemWrite, RegWrite, ALU_rs1, ALU_rs2, jal, pc_mux;
    wire [1:0] ALUop, MemtoReg;

    wire [31:0]  pc_offset,pc_b_type,pc_branch;

    wire [31:0] memory_read_data, Data_memory_read;

    assign pc = pc_now;
    assign io_addr = ALU_result[7:0];
    assign io_dout = Read_data_2;
    assign io_we = MemWrite&&(ALU_result[10]);

    // assign iii = ins;
    // assign next_pc = pc_next;

    add pc_add(
        .a(pc_now),
        .b(32'd4),
        .out(pc_4)
    );

    pc pc_reg(
        .in(pc_next),
        .rst(rst),
        .clk(clk),
        .out(pc_now)
    );

    dist_mem_gen_0 Instruction_memory (
        .clk(clk),
        .we(1'b0),
        .d(0),
        .a(pc_now[9:2]),
        .spo(ins)
    );

    dist_mem_gen_1 Data_memory (
        .a(ALU_result[9:2]),      
        .d(Read_data_2),          
        .dpra(m_rf_addr),         
        .clk(clk),                
        .we(MemWrite&&(~ALU_result[10])), 
        .spo(memory_read_data),   
        .dpo(m_data)         
    );

    reg jal_x0;
    always@(*) begin
        if(jal && ins[11:7] == 5'b00000)
            jal_x0 = 1;
        else
            jal_x0 = 0;
    end
    
    register_file register(
        .clk(clk),
        .ra0(ins[19:15]),
        .rd0(Read_data_1),
        .ra1(ins[24:20]),
        .rd1(Read_data_2),
        .wa(ins[11:7]),
        .we((RegWrite&&(~jal))||(RegWrite&&(~jal_x0))),
        .wd(Register_write),
        .ra2(m_rf_addr[4:0]),
        .reg_debug(rf_data)
    );

    Immgen Immgen(
        .instruction(ins),
        .immediate(immediate_num)
    );

    control control(
        .ins(ins[6:0]),
        .Branch(Branch),
        .MemRead(MemRead),
        .MemtoReg(MemtoReg),
        .MemWrite(MemWrite),
        .ALU_rs1(ALU_rs1),
        .ALU_rs2(ALU_rs2),
        .RegWrite(RegWrite),
        .ALUop(ALUop),
        .pc_mux(pc_mux),
        .jal(jal)
    );

    mux2to1 alu_mux_1(
        .a(Read_data_1),
        .b(pc_now),
        .sel(ALU_rs1),
        .out(alu_op1)
    );

    mux2to1 alu_mux_2(
        .a(Read_data_2),
        .b(immediate_num),
        .sel(ALU_rs2),
        .out(alu_op2)
    );

    alucontrol alucontrol(
        .ALUOp(ALUop),
        .ALUout(alu_control),
        .funct7(ins[31:25])
    );

    alu alu(
        .a(alu_op1),
        .b(alu_op2),
        .f(alu_control),
        .z_r(ALU_ZERO),
        .y_r(ALU_result)
    );

    mux2to1 sw_lw_mux(
        .a(memory_read_data),
        .b(io_din[31:0]),
        .sel(ALU_result[10]),
        .out(Data_memory_read)         
    );

    mux3to1 reg_mux(
        .a(Data_memory_read),
        .b(ALU_result),
        .c(pc_4),
        .sel(MemtoReg),
        .out(Register_write)
    );

    shiftleft shiftleft(
        .in(immediate_num),
        .out(pc_offset)
    );

    add pc_add_offset(
        .a(pc_now),
        .b(pc_offset),
        .out(pc_branch)
    );

    mux2to1 next_pc_branch(
        .a(pc_4),
        .b(pc_branch),
        .sel(jal||(Branch && ALU_ZERO)||(Branch && (~ALU_ZERO) && ins[14])),
        .out(pc_b_type)
    );

    mux2to1 pc_next_mux(
        .a(pc_b_type),
        .b(ALU_result),
        .sel(pc_mux),
        .out(pc_next)
    );

endmodule