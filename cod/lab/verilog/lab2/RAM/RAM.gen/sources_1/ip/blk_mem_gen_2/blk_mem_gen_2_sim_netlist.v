// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.2 (win64) Build 3064766 Wed Nov 18 09:12:45 MST 2020
// Date        : Tue Mar 29 18:39:10 2022
// Host        : LAPTOP-5I742T0T running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim
//               d:/za/cod/lab2/RAM/RAM.gen/sources_1/ip/blk_mem_gen_2/blk_mem_gen_2_sim_netlist.v
// Design      : blk_mem_gen_2
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "blk_mem_gen_2,blk_mem_gen_v8_4_4,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_4,Vivado 2020.2" *) 
(* NotValidForBitStream *)
module blk_mem_gen_2
   (clka,
    ena,
    wea,
    addra,
    dina,
    douta);
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA CLK" *) (* x_interface_parameter = "XIL_INTERFACENAME BRAM_PORTA, MEM_SIZE 8192, MEM_WIDTH 32, MEM_ECC NONE, MASTER_TYPE OTHER, READ_LATENCY 1" *) input clka;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA EN" *) input ena;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA WE" *) input [0:0]wea;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA ADDR" *) input [3:0]addra;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA DIN" *) input [7:0]dina;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA DOUT" *) output [7:0]douta;

  wire [3:0]addra;
  wire clka;
  wire [7:0]dina;
  wire [7:0]douta;
  wire ena;
  wire [0:0]wea;
  wire NLW_U0_dbiterr_UNCONNECTED;
  wire NLW_U0_rsta_busy_UNCONNECTED;
  wire NLW_U0_rstb_busy_UNCONNECTED;
  wire NLW_U0_s_axi_arready_UNCONNECTED;
  wire NLW_U0_s_axi_awready_UNCONNECTED;
  wire NLW_U0_s_axi_bvalid_UNCONNECTED;
  wire NLW_U0_s_axi_dbiterr_UNCONNECTED;
  wire NLW_U0_s_axi_rlast_UNCONNECTED;
  wire NLW_U0_s_axi_rvalid_UNCONNECTED;
  wire NLW_U0_s_axi_sbiterr_UNCONNECTED;
  wire NLW_U0_s_axi_wready_UNCONNECTED;
  wire NLW_U0_sbiterr_UNCONNECTED;
  wire [7:0]NLW_U0_doutb_UNCONNECTED;
  wire [3:0]NLW_U0_rdaddrecc_UNCONNECTED;
  wire [3:0]NLW_U0_s_axi_bid_UNCONNECTED;
  wire [1:0]NLW_U0_s_axi_bresp_UNCONNECTED;
  wire [3:0]NLW_U0_s_axi_rdaddrecc_UNCONNECTED;
  wire [7:0]NLW_U0_s_axi_rdata_UNCONNECTED;
  wire [3:0]NLW_U0_s_axi_rid_UNCONNECTED;
  wire [1:0]NLW_U0_s_axi_rresp_UNCONNECTED;

  (* C_ADDRA_WIDTH = "4" *) 
  (* C_ADDRB_WIDTH = "4" *) 
  (* C_ALGORITHM = "1" *) 
  (* C_AXI_ID_WIDTH = "4" *) 
  (* C_AXI_SLAVE_TYPE = "0" *) 
  (* C_AXI_TYPE = "1" *) 
  (* C_BYTE_SIZE = "9" *) 
  (* C_COMMON_CLK = "0" *) 
  (* C_COUNT_18K_BRAM = "1" *) 
  (* C_COUNT_36K_BRAM = "0" *) 
  (* C_CTRL_ECC_ALGO = "NONE" *) 
  (* C_DEFAULT_DATA = "0" *) 
  (* C_DISABLE_WARN_BHV_COLL = "0" *) 
  (* C_DISABLE_WARN_BHV_RANGE = "0" *) 
  (* C_ELABORATION_DIR = "./" *) 
  (* C_ENABLE_32BIT_ADDRESS = "0" *) 
  (* C_EN_DEEPSLEEP_PIN = "0" *) 
  (* C_EN_ECC_PIPE = "0" *) 
  (* C_EN_RDADDRA_CHG = "0" *) 
  (* C_EN_RDADDRB_CHG = "0" *) 
  (* C_EN_SAFETY_CKT = "0" *) 
  (* C_EN_SHUTDOWN_PIN = "0" *) 
  (* C_EN_SLEEP_PIN = "0" *) 
  (* C_EST_POWER_SUMMARY = "Estimated Power for IP     :     2.3883 mW" *) 
  (* C_FAMILY = "artix7" *) 
  (* C_HAS_AXI_ID = "0" *) 
  (* C_HAS_ENA = "1" *) 
  (* C_HAS_ENB = "0" *) 
  (* C_HAS_INJECTERR = "0" *) 
  (* C_HAS_MEM_OUTPUT_REGS_A = "1" *) 
  (* C_HAS_MEM_OUTPUT_REGS_B = "0" *) 
  (* C_HAS_MUX_OUTPUT_REGS_A = "0" *) 
  (* C_HAS_MUX_OUTPUT_REGS_B = "0" *) 
  (* C_HAS_REGCEA = "0" *) 
  (* C_HAS_REGCEB = "0" *) 
  (* C_HAS_RSTA = "0" *) 
  (* C_HAS_RSTB = "0" *) 
  (* C_HAS_SOFTECC_INPUT_REGS_A = "0" *) 
  (* C_HAS_SOFTECC_OUTPUT_REGS_B = "0" *) 
  (* C_INITA_VAL = "0" *) 
  (* C_INITB_VAL = "0" *) 
  (* C_INIT_FILE = "blk_mem_gen_2.mem" *) 
  (* C_INIT_FILE_NAME = "no_coe_file_loaded" *) 
  (* C_INTERFACE_TYPE = "0" *) 
  (* C_LOAD_INIT_FILE = "0" *) 
  (* C_MEM_TYPE = "0" *) 
  (* C_MUX_PIPELINE_STAGES = "0" *) 
  (* C_PRIM_TYPE = "1" *) 
  (* C_READ_DEPTH_A = "16" *) 
  (* C_READ_DEPTH_B = "16" *) 
  (* C_READ_LATENCY_A = "1" *) 
  (* C_READ_LATENCY_B = "1" *) 
  (* C_READ_WIDTH_A = "8" *) 
  (* C_READ_WIDTH_B = "8" *) 
  (* C_RSTRAM_A = "0" *) 
  (* C_RSTRAM_B = "0" *) 
  (* C_RST_PRIORITY_A = "CE" *) 
  (* C_RST_PRIORITY_B = "CE" *) 
  (* C_SIM_COLLISION_CHECK = "ALL" *) 
  (* C_USE_BRAM_BLOCK = "0" *) 
  (* C_USE_BYTE_WEA = "0" *) 
  (* C_USE_BYTE_WEB = "0" *) 
  (* C_USE_DEFAULT_DATA = "0" *) 
  (* C_USE_ECC = "0" *) 
  (* C_USE_SOFTECC = "0" *) 
  (* C_USE_URAM = "0" *) 
  (* C_WEA_WIDTH = "1" *) 
  (* C_WEB_WIDTH = "1" *) 
  (* C_WRITE_DEPTH_A = "16" *) 
  (* C_WRITE_DEPTH_B = "16" *) 
  (* C_WRITE_MODE_A = "NO_CHANGE" *) 
  (* C_WRITE_MODE_B = "WRITE_FIRST" *) 
  (* C_WRITE_WIDTH_A = "8" *) 
  (* C_WRITE_WIDTH_B = "8" *) 
  (* C_XDEVICEFAMILY = "artix7" *) 
  (* downgradeipidentifiedwarnings = "yes" *) 
  (* is_du_within_envelope = "true" *) 
  blk_mem_gen_2_blk_mem_gen_v8_4_4 U0
       (.addra(addra),
        .addrb({1'b0,1'b0,1'b0,1'b0}),
        .clka(clka),
        .clkb(1'b0),
        .dbiterr(NLW_U0_dbiterr_UNCONNECTED),
        .deepsleep(1'b0),
        .dina(dina),
        .dinb({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .douta(douta),
        .doutb(NLW_U0_doutb_UNCONNECTED[7:0]),
        .eccpipece(1'b0),
        .ena(ena),
        .enb(1'b0),
        .injectdbiterr(1'b0),
        .injectsbiterr(1'b0),
        .rdaddrecc(NLW_U0_rdaddrecc_UNCONNECTED[3:0]),
        .regcea(1'b0),
        .regceb(1'b0),
        .rsta(1'b0),
        .rsta_busy(NLW_U0_rsta_busy_UNCONNECTED),
        .rstb(1'b0),
        .rstb_busy(NLW_U0_rstb_busy_UNCONNECTED),
        .s_aclk(1'b0),
        .s_aresetn(1'b0),
        .s_axi_araddr({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arburst({1'b0,1'b0}),
        .s_axi_arid({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arlen({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arready(NLW_U0_s_axi_arready_UNCONNECTED),
        .s_axi_arsize({1'b0,1'b0,1'b0}),
        .s_axi_arvalid(1'b0),
        .s_axi_awaddr({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awburst({1'b0,1'b0}),
        .s_axi_awid({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awlen({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awready(NLW_U0_s_axi_awready_UNCONNECTED),
        .s_axi_awsize({1'b0,1'b0,1'b0}),
        .s_axi_awvalid(1'b0),
        .s_axi_bid(NLW_U0_s_axi_bid_UNCONNECTED[3:0]),
        .s_axi_bready(1'b0),
        .s_axi_bresp(NLW_U0_s_axi_bresp_UNCONNECTED[1:0]),
        .s_axi_bvalid(NLW_U0_s_axi_bvalid_UNCONNECTED),
        .s_axi_dbiterr(NLW_U0_s_axi_dbiterr_UNCONNECTED),
        .s_axi_injectdbiterr(1'b0),
        .s_axi_injectsbiterr(1'b0),
        .s_axi_rdaddrecc(NLW_U0_s_axi_rdaddrecc_UNCONNECTED[3:0]),
        .s_axi_rdata(NLW_U0_s_axi_rdata_UNCONNECTED[7:0]),
        .s_axi_rid(NLW_U0_s_axi_rid_UNCONNECTED[3:0]),
        .s_axi_rlast(NLW_U0_s_axi_rlast_UNCONNECTED),
        .s_axi_rready(1'b0),
        .s_axi_rresp(NLW_U0_s_axi_rresp_UNCONNECTED[1:0]),
        .s_axi_rvalid(NLW_U0_s_axi_rvalid_UNCONNECTED),
        .s_axi_sbiterr(NLW_U0_s_axi_sbiterr_UNCONNECTED),
        .s_axi_wdata({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_wlast(1'b0),
        .s_axi_wready(NLW_U0_s_axi_wready_UNCONNECTED),
        .s_axi_wstrb(1'b0),
        .s_axi_wvalid(1'b0),
        .sbiterr(NLW_U0_sbiterr_UNCONNECTED),
        .shutdown(1'b0),
        .sleep(1'b0),
        .wea(wea),
        .web(1'b0));
endmodule
`pragma protect begin_protected
`pragma protect version = 1
`pragma protect encrypt_agent = "XILINX"
`pragma protect encrypt_agent_info = "Xilinx Encryption Tool 2020.2"
`pragma protect key_keyowner="Cadence Design Systems.", key_keyname="cds_rsa_key", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=64)
`pragma protect key_block
QGLtnqZzRetDH6gCWT4Js6wuLlZfrNx/VJp3sfR2NF+cxypO5AxN0oDKLJJtmdrtE/ueNDg+Qf7Z
TqBNRojORA==

`pragma protect key_keyowner="Synopsys", key_keyname="SNPS-VCS-RSA-2", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
B6Ger3hRvfjHkaJ+W8639Kl3TzC9TogLuklOXEiMNdc4Im+DjEUzxb3DKlzu0VW3zxZqjJ3+wsW/
LnRmPCESi5Y9eRJaLFXg79EMfoj4X+nTdHAP6yCfltBADKegZ12gpnB/8ey5yn2KA74LUtPC7jna
iyjqSfsWLGnz6UdXzwk=

`pragma protect key_keyowner="Aldec", key_keyname="ALDEC15_001", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
BX+DxgMPRyZbYojCUR9Sk8Lq+3ZigBz4yMFHQkmurfdfDzyTPJCE827eGiPyTenK1QPVhEtf9g06
0BFXq/0COPuU1BWJwdkz1c4dE6/exDwhvEh+hPx3vRY6z8fDEf6aGVIXrHDvrmddehe7yMSIpo+k
aXHR06EEdfHCFY4TggYwhcJVXjkE+ApsVuyfmEfPmYjo8hCWyQyBsUWIOY03q1+MvUjjsmTwgs9g
fh5MY9ToaLfoJxPKdCpsqrBX4LJ+VDGFlAqIcqHTE2jCmPiToZAFXB7fzf1wDjFCBlJyFVDBGi0i
m+CouLSb7X1mvVhdDZgNrZDJMV688Bu3o54vew==

`pragma protect key_keyowner="ATRENTA", key_keyname="ATR-SG-2015-RSA-3", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
DaIU/Ddc8USbZ2mURzujJDWDH1JbHl5tFVOOQ2aVaUPIA71yyE38OXVLEtF8rNmujYH30nEeQ+FV
LVJ16aaHw+iiuaqorTM3K5KLohVlN+WlcEtSXHuPNHjw8ddqtzpaX7pH1zqZH+YmfCL5oaNLqDH4
rkBnUl0/Gm/hzSwKjYhXGQFYQ+gGP99OjXakzrAqZzp/Iq4gt+Z5902/JV9thd/isHQImJ0QyK8M
EKM579iPAfXGes2mbiNYHcvDmSPYmW1zlhOE++N1EKeea7j/msnKeyhlC+hGE4Xfn4TVvqgQexCT
rp/wS/MosY6WH1aKFQlFH2hEppA7KXUaQlvG+w==

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-VELOCE-RSA", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
XmWoAt4X8hrCJ5yTyug4ajJW5UhfkLNibzjihWzZ4Cr9hQSvWZoTc8rjGsLPbz6Le+/9iI5KxecS
eR0wiAO+G2IkwhZgVBeZdKoFnlnTVAyLjk9wMAFXNyJZM6b1NDbfXlPcUsC6JePvPlwwdWknkSsC
r3KvgkWAS+O3xvRmaNw=

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-VERIF-SIM-RSA-2", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
Hw3Y+rShKrXiUViyNU1/O2qv6TgheLHBnFMj1i9MUGrHYqh9pLfLYUgWR7S2vj4jv4S+Ks0BpP4p
dKEqVAFmTCfQNEUHaVcFPkOHgig6L4mhLY6HUUKJoRgiQepgLi/W3V+ZZPQSQFkB3CU4MsJzhXvR
yLcpDriZy8cnAHD87Zi5DrNGBzj3kigJeM0du6lCQbxtF5aEdoaNP+YTnIFtcqYhoYnswQlYt0sV
HKgFA8VzqzL5WYnpH7+1IKmFkJBHkyqHCa9wPK0qCKnxkuDj70YzPVqQ+cocdKU+/gNdpCOdZlci
F2HTxrgfrXndJru3TiDqu4UavqAe0MNuFp3t0w==

`pragma protect key_keyowner="Real Intent", key_keyname="RI-RSA-KEY-1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
XPVggoWL6aXz+MpODTOZhEUQDa0vfEnUDaYeEHXm2vGyqKJujN2c/FFAFBeBYdJATLsIsQ+BqoPc
pBbcFYXDBfOtFIW2dH6Y1OoD65KyJ/hAq8coa21kFgq4hFat5vzZ2iIfkCpTUr4vDZO7Xne8cZO9
WsHffoTCt5rS59wWm2b8I5R8Eh2TUbQg3RCyrcnD66cvcEnlXe1CNMQ4/loVJpA4IBinBf820Wjc
vw2fZbGI0jXC+ACSHOviH63Xwmn+aRV5Ppkup7IYoon/ieKapRQeASu3TTY37xSBXiInSdtMTzJ6
+4GfO4eSHVriCk/sWbuTBzfRzoSShrnHjzz5LA==

`pragma protect key_keyowner="Xilinx", key_keyname="xilinxt_2020_08", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
L78XuiswVcgO2gtebzL7SA9BC/jJGAM0v6S9pzmyqL+QYzRneiYeGyDmsW33jEVVSTuNjTXkBLY7
yTOKQruatwe4V0OLi6174saSAmPgerSV1GyLP7KhmusLV/N61avC9TPam+tekhKeE0tds4EnJ3et
4JdLh+SE4Z4pcuqCjB5MFneIYKKWDx7siU6oesAQtoSJOesfMchX63MhOjOHFP/ch+1gHv3T45hg
IGF7V7TrdREVE4f9631tlVJ1o2Dypsmo/76Itz5WCGlTMjAnWXN8IXxKN+PZ3dyt1wjrZm2P/td+
xiGszFnSLrRvw/HferwtSmRx8q0fiHZ88roGTw==

`pragma protect key_keyowner="Metrics Technologies Inc.", key_keyname="DSim", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
kDX5kq2QEe25429T6vQqBCFvV1McKTJRYfK99ymVNK2GGvGLXSzgwJHwB2fj9rM0wme3zYYY0vQR
x+9F4L7KLlOVY6qY3LB59uDzyXBI3mMZaS905HXHJkdZHWtQWpfHhl27LqL+8FSluaD6F+KFfYOV
CwIOVuCIp/XjxFXpNBik7YiPt4kHOlDA97IXNLnYUn/g1csGqeNWce4UTne50ggWvLYGbTFGmTjT
N67TpUiGRVRCSv8Tax72GWFIMFZk3Tlp68ZUSQEybZMWX1U9XdMdtxfvNGhf8mi5jQJ2SupSzKu4
T/+53IN9T8aLePAiGBKKG1ZBj4y1ZyYA7XYvjw==

`pragma protect data_method = "AES128-CBC"
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 20576)
`pragma protect data_block
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
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
