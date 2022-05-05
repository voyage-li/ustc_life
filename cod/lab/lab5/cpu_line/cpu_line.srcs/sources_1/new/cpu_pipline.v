module cpu_pipline(
    input clk,rst,
    output [7:0] io_addr,
    output [31:0] io_dout,
    output io_we,
    input [31:0] io_din,

    input [7:0] m_rf_addr,
    output [31:0] rf_data,
    output [31:0] m_data,
    
    output [31:0] pcin, pc, pcd, pce,
    output [31:0] ir, imm, mdr,
    output [31:0] a, b, y, bm, yw,
    output [4:0]  rd, rdm, rdw,
    output [31:0] ctrl, ctrlm, ctrlw
);
    wire [31:0] pc_IF, pc_ID, pc_EX, pc_MEM, pc_WB;
    wire [31:0] pc_4_IF, pc_4_ID, pc_4_EX, pc_4_MEM, pc_4_WB;
    wire [31:0] pc_offset_IF, pc_offset_ID, pc_offset_EX, pc_offset_MEM, pc_offset_WB;
    wire [31:0] ins_IF, ins_ID, ins_EX, ins_MEM, ins_WB;
    wire [31:0] alu_result_IF, alu_result_ID, alu_result_EX, alu_result_MEM, alu_result_WB;
    wire alu_zero_IF, alu_zero_ID, alu_zero_EX, alu_zero_MEM, alu_zero_WB;
    wire [31:0] Read_data_1_IF, Read_data_1_ID, Read_data_1_EX, Read_data_1_MEM, Read_data_1_WB;
    wire [31:0] Read_data_2_IF, Read_data_2_ID, Read_data_2_EX, Read_data_2_MEM, Read_data_2_WB;
    wire [31:0] memory_read_data, memory_read_data_IF, memory_read_data_ID, memory_read_data_EX, memory_read_data_MEM, memory_read_data_WB;
    wire [31:0] Write_data_IF, Write_data_ID, Write_data_EX, Write_data_MEM, Write_data_WB;
    wire [31:0] immediate_num_IF, immediate_num_ID, immediate_num_EX, immediate_num_MEM, immediate_num_WB;
    wire [31:0] alu_op1, alu_op2;
    wire [2:0] alu_control;
    wire [31:0] next_pc;

    wire Branch_ID, MemRead_ID, MemWrite_ID, RegWrite_ID, ALUsrc_ID, jal_ID;
    wire [1:0] ALUop_ID, MemtoReg_ID;
    wire Branch_EX, MemRead_EX, MemWrite_EX, RegWrite_EX, ALUsrc_EX, jal_EX;
    wire [1:0] ALUop_EX, MemtoReg_EX;
    wire Branch_MEM, MemRead_MEM, MemWrite_MEM, RegWrite_MEM, ALUsrc_MEM, jal_MEM;
    wire [1:0] ALUop_MEM, MemtoReg_MEM;
    wire Branch_WB, MemRead_WB, MemWrite_WB, RegWrite_WB, ALUsrc_WB, jal_WB;
    wire [1:0] ALUop_WB, MemtoReg_WB;
    wire [1:0] alu_rs1_mux_signal, alu_rs2_mux_signal;
    wire [31:0] alu_rs1_fw, alu_rs2_fw;

    wire pc_write, IF_ID_write, control_mux;
    wire jump_branch, jump;

    assign pc = pc_IF;
    assign pcd = pc_ID;
    assign ir = ins_ID;
    assign pcin = next_pc;
    assign pce = pc_EX;
    assign a = alu_rs1_fw;
    assign b = alu_rs2_fw;
    assign imm = immediate_num_EX;
    assign rd = ins_EX[11:7];
    assign ctrl = {~IF_ID_write,~control_mux,jump,3'b0,alu_rs1_mux_signal,2'b0,alu_rs2_mux_signal,1'b0,RegWrite_ID,MemtoReg_ID,2'b0,MemRead_ID,MemWrite_ID,2'b0,jal_ID,Branch_ID,2'b0,alu_rs1_mux_signal,alu_rs2_mux_signal,ALUop_ID};
    assign y = alu_result_MEM;
    assign bm = Read_data_2_MEM;
    assign rdm = ins_MEM[11:7];
    assign ctrlm = {~IF_ID_write,~control_mux,jump,3'b0,alu_rs1_mux_signal,2'b0,alu_rs2_mux_signal,1'b0,RegWrite_MEM,MemtoReg_MEM,2'b0,MemRead_MEM,MemWrite_MEM,2'b0,jal_MEM,Branch_MEM,2'b0,alu_rs1_mux_signal,alu_rs2_mux_signal,ALUop_MEM};
    assign yw = alu_result_WB;
    assign mdr = memory_read_data_WB;
    assign rdw = ins_WB[11:7];
    assign ctrlw = {~IF_ID_write,~control_mux,jump,3'b0,alu_rs1_mux_signal,2'b0,alu_rs2_mux_signal,1'b0,RegWrite_WB,MemtoReg_WB,2'b0,MemRead_WB,MemWrite_WB,2'b0,jal_WB,Branch_WB,2'b0,alu_rs1_mux_signal,alu_rs2_mux_signal,ALUop_WB};
    

    // assign temp1 = alu_rs1_mux_signal;
    // assign temp2 = alu_rs2_mux_signal;
    // assign temp0 = {27'b0,ins_EX[11:7]};
    // assign temp = {27'b0,ins_ID[19:15]};
    // assign temp1 = IF_ID_write;
    // assign temp2 = pc_write;
    // assign temp3 = control_mux;

    pc pc_reg(
        .in(next_pc),
        .rst(rst),
        .clk(clk),
        .en(pc_write),
        .out(pc_IF)
    );


    add pc_add(
        .a(pc_IF),
        .b(32'd4),
        .out(pc_4_IF)
    );

    dist_mem_gen_3 Instruction_memory (
        .clk(clk),
        .we(1'b0),
        .d(0),
        .a(pc_IF[9:2]),
        .spo(ins_IF)
    );

    dist_mem_gen_1 Data_memory (
        .a(alu_result_MEM[9:2]),      
        .d(Read_data_2_MEM),          
        .dpra(m_rf_addr),         
        .clk(clk),                
        .we(MemWrite&&(~alu_result_MEM[10])), 
        .spo(memory_read_data),   
        .dpo(m_data)         
    );

    register reg_file(
        .clk(clk),
        .rst(rst),
        .w_en(RegWrite_WB||jal_WB),
        .addr1(ins_ID[19:15]),
        .addr2(ins_ID[24:20]),
        .addr3(ins_WB[11:7]),
        .w_data3(Write_data_WB),
        .rd_data1(Read_data_1_ID),
        .rd_data2(Read_data_2_ID),
        .debug_addr(m_rf_addr),
        .debug_data(rf_data)
    );

    Immgen Immgen(
        .instruction(ins_ID),
        .immediate(immediate_num_ID)
    );

    control control(
        .ins(ins_ID[6:0]),
        .Branch(Branch_ID),
        .MemRead(MemRead_ID),
        .MemtoReg(MemtoReg_ID),
        .MemWrite(MemWrite_ID),
        .ALUsrc(ALUsrc_ID),
        .RegWrite(RegWrite_ID),
        .ALUop(ALUop_ID),
        .jal(jal_ID)
    );

    IF_ID IF_ID(
        .clk(clk),
        .rst(rst),
        .en(IF_ID_write),
        .jump(jump),
        .ins(ins_IF),
        .pc(pc_IF),
        .pc_4(pc_4_IF),
        .ins_o(ins_ID),
        .pc_o(pc_ID),
        .pc_4_o(pc_4_ID)
    );

    ID_EX ID_EX(
        .clk(clk),
        .rst(rst),
        .en(control_mux),
        .ins(ins_ID),
        .immediate(immediate_num_ID),
        .pc(pc_ID),
        .pc_4(pc_4_ID),
        .rd1(Read_data_1_ID),
        .rd2(Read_data_2_ID),
        .ins_o(ins_EX),
        .immediate_o(immediate_num_EX),
        .pc_o(pc_EX),
        .pc_4_o(pc_4_EX),
        .rd1_o(Read_data_1_EX),
        .rd2_o(Read_data_2_EX),
        .Branch(Branch_ID),
        .MemRead(MemRead_ID),
        .MemtoReg(MemtoReg_ID),
        .MemWrite(MemWrite_ID),
        .ALUsrc(ALUsrc_ID),
        .RegWrite(RegWrite_ID),
        .ALUop(ALUop_ID),
        .jal(jal_ID),
        .Branch_o(Branch_EX),
        .MemRead_o(MemRead_EX),
        .MemtoReg_o(MemtoReg_EX),
        .MemWrite_o(MemWrite_EX),
        .ALUsrc_o(ALUsrc_EX),
        .RegWrite_o(RegWrite_EX),
        .ALUop_o(ALUop_EX),
        .jal_o(jal_EX)
    );

    EX_MEM EX_MEM(
        .clk(clk),
        .rst(rst),
        .pc_4(pc_4_EX),
        .pc_offset(pc_offset_EX),
        .alu_result(alu_result_EX),
        .alu_zero(alu_zero_EX),
        .rd2(alu_rs2_fw),
        .ins(ins_EX),
        .pc_4_o(pc_4_MEM),
        .pc_offset_o(pc_offset_MEM),
        .alu_result_o(alu_result_MEM),
        .alu_zero_o(alu_zero_MEM),
        .rd2_o(Read_data_2_MEM),
        .ins_o(ins_MEM),
        .Branch(Branch_EX),
        .MemRead(MemRead_EX),
        .MemtoReg(MemtoReg_EX),
        .MemWrite(MemWrite_EX),
        .RegWrite(RegWrite_EX),
        .jal(jal_EX),
        .Branch_o(Branch_MEM),
        .MemRead_o(MemRead_MEM),
        .MemtoReg_o(MemtoReg_MEM),
        .MemWrite_o(MemWrite_MEM),
        .RegWrite_o(RegWrite_MEM),
        .jal_o(jal_MEM)
    );

    MEM_WB MEM_WB(
        .clk(clk),
        .rst(rst),
        .alu_result(alu_result_MEM),
        .ins(ins_MEM),
        .MemReadData(memory_read_data_MEM),
        .pc_4(pc_4_MEM),
        .alu_result_o(alu_result_WB),
        .ins_o(ins_WB),
        .MemReadData_o(memory_read_data_WB),
        .pc_4_o(pc_4_WB),
        .MemtoReg(MemtoReg_MEM),
        .RegWrite(RegWrite_MEM),
        .MemtoReg_o(MemtoReg_WB),
        .RegWrite_o(RegWrite_WB)
    );
    
    assign alu_op1 = alu_rs1_fw;
    mux3to1 alu_rs1_mux(
        .a(Read_data_1_EX),
        .b(alu_result_MEM),
        .c(Write_data_WB),
        .sel(alu_rs1_mux_signal),
        .out(alu_rs1_fw)
    );

    mux3to1 alu_rs2_mux(
        .a(Read_data_2_EX),
        .b(alu_result_MEM),
        .c(Write_data_WB),
        .sel(alu_rs2_mux_signal),
        .out(alu_rs2_fw)
    );

    Forwarding Forwarding(
        .ins_EX(ins_EX),
        .ins_MEM(ins_MEM),
        .ins_WB(ins_WB),
        .RegWrite_MEM(RegWrite_MEM),
        .RegWrite_WB(RegWrite_WB),
        .alu_rs1_mux_signal(alu_rs1_mux_signal),
        .alu_rs2_mux_signal(alu_rs2_mux_signal)
    );
    
    stall stall(
        .MemRead_EX(MemRead_EX),
        .Branch_ID(Branch_ID),
        .RegWrite_EX(RegWrite_EX),
        .RegWrite_MEM(RegWrite_MEM),
        .RegWrite_WB(RegWrite_WB),
        .ins_EX(ins_EX),
        .ins_ID(ins_ID),
        .ins_MEM(ins_MEM),
        .ins_WB(ins_WB),
        .pc_write(pc_write),
        .IF_ID_write(IF_ID_write),
        .control_mux(control_mux),
        .jump(jump_branch)
    );

    mux2to1 alu_mux(
        .a(alu_rs2_fw),
        .b(immediate_num_EX),
        .sel(ALUsrc_EX),
        .out(alu_op2)
    );

    alucontrol alucontrol(
        .ALUOp(ALUop_EX),
        .ALUout(alu_control),
        .funct7(ins_EX[31:25])
    );

    alu alu(
        .a(alu_op1),
        .b(alu_op2),
        .f(alu_control),
        .z_r(alu_zero_EX),
        .y_r(alu_result_EX)
    );

    mux2to1 sw_lw_mux(
        .a(memory_read_data),
        .b(io_din[31:0]),
        .sel(alu_result_MEM[10]),
        .out(memory_read_data_MEM)         
    );

    mux3to1 reg_mux(
        .a(alu_result_WB),
        .b(memory_read_data_WB),
        .c(pc_4_WB),
        .sel(MemtoReg_WB),
        .out(Write_data_WB)
    );

    wire [31:0] shiftleft_already;
    shiftleft shiftleft(
        .in(immediate_num_ID),
        .out(shiftleft_already)
    );

    add pc_add_offset(
        .a(pc_ID),
        .b(shiftleft_already),
        .out(pc_offset_ID)
    );

    // assign jump = (Branch_ID&&Read_data_1_ID==Read_data_2_ID)||jal_ID;
    // assign IF_ID_write_jump = (jump == 1) ? 0 : 1;
    // assign temp = jump;
    // assign jump_r = jump;
    assign jump = (jump_branch && Read_data_1_ID==Read_data_2_ID)||jal_ID;
    // assign jump_r = jump;
    mux2to1 pc_mux(
        .a(pc_4_IF),
        .b(pc_offset_ID),
        .sel(jump),
        .out(next_pc)
    );

    assign io_addr = alu_result_MEM[7:0];
    assign io_dout = Read_data_2_MEM;
    assign io_we = MemWrite_MEM&&(alu_result_MEM[10]);


endmodule