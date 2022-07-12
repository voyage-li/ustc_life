// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.2 (win64) Build 3064766 Wed Nov 18 09:12:45 MST 2020
// Date        : Sat Mar 26 12:04:01 2022
// Host        : LAPTOP-5I742T0T running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim
//               d:/za/cod/lab2/RAM/RAM.gen/sources_1/ip/dist_mem_gen_0/dist_mem_gen_0_sim_netlist.v
// Design      : dist_mem_gen_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "dist_mem_gen_0,dist_mem_gen_v8_0_13,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "dist_mem_gen_v8_0_13,Vivado 2020.2" *) 
(* NotValidForBitStream *)
module dist_mem_gen_0
   (a,
    d,
    clk,
    we,
    spo);
  input [3:0]a;
  input [7:0]d;
  input clk;
  input we;
  output [7:0]spo;

  wire [3:0]a;
  wire clk;
  wire [7:0]d;
  wire [7:0]spo;
  wire we;
  wire [7:0]NLW_U0_dpo_UNCONNECTED;
  wire [7:0]NLW_U0_qdpo_UNCONNECTED;
  wire [7:0]NLW_U0_qspo_UNCONNECTED;

  (* C_FAMILY = "artix7" *) 
  (* C_HAS_CLK = "1" *) 
  (* C_HAS_D = "1" *) 
  (* C_HAS_DPO = "0" *) 
  (* C_HAS_DPRA = "0" *) 
  (* C_HAS_QDPO = "0" *) 
  (* C_HAS_QDPO_CE = "0" *) 
  (* C_HAS_QDPO_CLK = "0" *) 
  (* C_HAS_QDPO_RST = "0" *) 
  (* C_HAS_QDPO_SRST = "0" *) 
  (* C_HAS_WE = "1" *) 
  (* C_MEM_TYPE = "1" *) 
  (* C_QCE_JOINED = "0" *) 
  (* C_REG_DPRA_INPUT = "0" *) 
  (* c_addr_width = "4" *) 
  (* c_default_data = "0" *) 
  (* c_depth = "16" *) 
  (* c_elaboration_dir = "./" *) 
  (* c_has_i_ce = "0" *) 
  (* c_has_qspo = "0" *) 
  (* c_has_qspo_ce = "0" *) 
  (* c_has_qspo_rst = "0" *) 
  (* c_has_qspo_srst = "0" *) 
  (* c_has_spo = "1" *) 
  (* c_mem_init_file = "dist_mem_gen_0.mif" *) 
  (* c_parser_type = "1" *) 
  (* c_pipeline_stages = "0" *) 
  (* c_qualify_we = "0" *) 
  (* c_read_mif = "1" *) 
  (* c_reg_a_d_inputs = "0" *) 
  (* c_sync_enable = "1" *) 
  (* c_width = "8" *) 
  (* is_du_within_envelope = "true" *) 
  dist_mem_gen_0_dist_mem_gen_v8_0_13 U0
       (.a(a),
        .clk(clk),
        .d(d),
        .dpo(NLW_U0_dpo_UNCONNECTED[7:0]),
        .dpra({1'b0,1'b0,1'b0,1'b0}),
        .i_ce(1'b1),
        .qdpo(NLW_U0_qdpo_UNCONNECTED[7:0]),
        .qdpo_ce(1'b1),
        .qdpo_clk(1'b0),
        .qdpo_rst(1'b0),
        .qdpo_srst(1'b0),
        .qspo(NLW_U0_qspo_UNCONNECTED[7:0]),
        .qspo_ce(1'b1),
        .qspo_rst(1'b0),
        .qspo_srst(1'b0),
        .spo(spo),
        .we(we));
endmodule
`pragma protect begin_protected
`pragma protect version = 1
`pragma protect encrypt_agent = "XILINX"
`pragma protect encrypt_agent_info = "Xilinx Encryption Tool 2020.2"
`pragma protect key_keyowner="Cadence Design Systems.", key_keyname="cds_rsa_key", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=64)
`pragma protect key_block
AWk2+F/LLIwJ/3H70MT+p73z+MaZAUnylB9xu/zfH66xX8dAaOizqpslZkE4MXrWhxdHpghP7sIj
kwvWqhJ3gA==

`pragma protect key_keyowner="Synopsys", key_keyname="SNPS-VCS-RSA-2", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
f3tnX2YCmmij/BT714m5fPTuG3pr/Sp1bWD1FpCFiwTkcUFmqMNcr7abCn+qa2HUp1VAs9a1kY1i
yU68W3C4ARAx1rnlow3CtMBZ+4vG1QDA+Ciu5T+MSJsiWTAoMU3jJunULwD6zEC9h/Y3bBf+ZNGj
RvbKgHQFYSq+EYUzleQ=

`pragma protect key_keyowner="Aldec", key_keyname="ALDEC15_001", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
C6xRmzJVnvguMc3Lt5tkoyg5+/u1VuxRooNBOmgUvD6c148xX9CV/zz4fw53vbCzqUg3WYMPAs5M
/tMrhPMrX5cqjMMHbC20NaFxsFGCfdbN+1Jiu6Ffu0obXLvBu7UGBCEaDTCY0wST3S+7NZ+HnAat
RIt5cVRmnWtLEj9MP8SxAk019LKc3+2AUY0eWFhWbTGvNoTLcRFak8vqIx8KBuqhc16O50jjNmM3
PJltfibMKzAmWpsf6xiOkaD+BvARuccAoYGgANLBAEQdJUza98//SuTN0KLZKbFSmy2WI5iAzkxJ
bhH9hPn6Ks1JkH9+j61hMSpdxSh8rM8X8Dppxw==

`pragma protect key_keyowner="ATRENTA", key_keyname="ATR-SG-2015-RSA-3", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
pefxdCU7VwYHa7diZaenheQOVCFpIvDlVp0qUtYsCnfw3IK+d5+k4O7xc5MWvQPeJpwUWNg+c9U8
PcbHo1enWoVg9o1V4U5fg7wxYqKmubBjgGF3yJ5FYGt6FeiD7zcnIJcaP2puAYDdVnxtiJnNmFz2
OQ7UQsleDpBQo3E4NEsbtqgSaopjHREMjI4yjJ9l5XZYNPCWUzUV/mSGX/kF+vuSOZclwPm6w72e
TE0MyJZA2HPDY3HIy260pYSHuDTUpe8gTxi0s8JmpFjaMaibBcPzq2gqPSQe1d6pDE8cv0OxNYKL
gFy+uh/H5gpNjfWVBhRmUo/kFf8fs680z0B0IQ==

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-VELOCE-RSA", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
q8meW/DFYsK3R2jTQ13P/a1BVQyF0Eb3aLhqxNSrqINAq7gQ0DvJ6JFuxd6Ce7TIpxqKUYX9026h
UujOPWt7f1brVrSWmt8cW5Um2Yy8tv+YSNv9Ig592u4GssTU6dF978RK/7L4ZuQObLOKvWLJqo3F
6gzw0VbqYS3g5aaGu+Y=

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-VERIF-SIM-RSA-2", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
GVM7UoBz9uTOdnKd0CVM0lBuJK2N20FwcoiRGregMBQMsQuevbc7y03ZehM7mfGvEdERp1TciWoI
1b6cDAZYb0YBfSuch0bItCwhdftV3A4/R0nUF0HROsZ/rm/HV7DKDXxItqK0qcdOwqf7ju85NMa4
FJRP/Nuq/ya9IvX9BCpmUlT7tLkICG8cEL8/iJrJY3jRIBtKw85mL5OM+r22LQeYg1/3rb9Rk9BT
RZCTbDcVSUq2Awr+6f0L2NXlRwhFraBy+h9iSZKZ/U7uolyF0nB1+/BSgOl+rttZ2KxfLXe6g81N
FbxtrlpK7FNc9fx2jrKWh5bczyW6p0ATPX0ZbA==

`pragma protect key_keyowner="Real Intent", key_keyname="RI-RSA-KEY-1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
rYkJ9a3QzTBGC5CITub5Su2Qs6nnM1m+OFLf4ykZkZGIsp11NQi6h5t8dsi/rX/MeEof1XLVJGEU
N+qLOHuLrttRAipPNBsj7yqH3Amnleqy/rjy8UcckD0gxIYzuIlc+2VKoAoyrEFgofTH5bKzBaaQ
q0JSt8PES8xuld4SvsKwr+0Q23qJIUpeNL3HvzxZDmYf5OhTkwlZPi/aLwSMoPZHKwetLUg5SdBm
7K4UmxvUPD3GNxo6GW6dkG2tFW/N9+ju7i//O1A74VUrDPo1OwQfEJazwHFFpHGjCJkv2CiPU3+I
TIVvzssQcs8IphMJulwZguc7fFiYv6aZyj/GrA==

`pragma protect key_keyowner="Xilinx", key_keyname="xilinxt_2020_08", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
PqIVM68d++A6qxRgSePlX8JOoCfHcFLdhzsYr1BDYvLE5JJ5WKFO0Bie6pyEiAbsH8z6oUFGm/Qy
BLXAyWfv1fmbVAwztezaMaxBF0Lw4epvQlAFVdMGJVKgvxfU7ssvLc1KfpF6R/c1o5+4Vf7zn3X+
R8k67LVYgJoxhrPoY3XYr88CjSITfNW0jLDjh0jtDWf7H7nM6QYSXVbRYczQPcepXW2MOFcCZsbi
tdla+UNJ4NeKTUK5bdE9tNZx/8BYKrJtLhyvNdwHi7EdonKLjQu63ExIHoriUmiZScMNbtr2LUBc
YYGUTIENquQ/OhU+DAVXmKbIZcQhwGaqjYeaag==

`pragma protect key_keyowner="Metrics Technologies Inc.", key_keyname="DSim", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
YMvD1GHkklhDlN9yur11SqhNZTItCRHxHobZtty993SsbvXTWJBbLeIJ+nQ/sv57gpjV5RswiJYh
Vu7QPlLUy2DbVjjcqxaxXlPvYaWV1eKD7BVBOV6HDzPAaAIaFvNjeRurYX0a9Dz1qkgkmttneZxB
s04mTyRdVOc7jIs5wjgXiF+iA0W50/g9JmIYyP6mMLkgEy0MbGyVfpbRfDMcrB3ACnucHTo8A0nT
V/rBUOGbTCYPmQ01tbuE2nqoEfTlmqHVKO6BZ93tQUEjrYoJdteva6yHUfH3dbV1vwwBtsdolICY
7x8cMlorxb6y2ZD7vQEYz6Q6iVnG/PmdaCkLSg==

`pragma protect data_method = "AES128-CBC"
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 9488)
`pragma protect data_block
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
Y0Qe16+FyB6RRdeFmPzgtwuoRYxIhzat7xs=
`pragma protect end_protected
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;
    parameter GRES_WIDTH = 10000;
    parameter GRES_START = 10000;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    wire GRESTORE;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;
    reg GRESTORE_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;
    assign (strong1, weak0) GRESTORE = GRESTORE_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

    initial begin 
	GRESTORE_int = 1'b0;
	#(GRES_START);
	GRESTORE_int = 1'b1;
	#(GRES_WIDTH);
	GRESTORE_int = 1'b0;
    end

endmodule
`endif
