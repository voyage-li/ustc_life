// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.2 (win64) Build 3064766 Wed Nov 18 09:12:45 MST 2020
// Date        : Sat Mar 26 12:04:01 2022
// Host        : LAPTOP-5I742T0T running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ dist_mem_gen_0_sim_netlist.v
// Design      : dist_mem_gen_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "dist_mem_gen_0,dist_mem_gen_v8_0_13,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "dist_mem_gen_v8_0_13,Vivado 2020.2" *) 
(* NotValidForBitStream *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix
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
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_dist_mem_gen_v8_0_13 U0
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
tl4FlsxRGcgakJJQe164u/P5g+8VwXxfCRU=
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
