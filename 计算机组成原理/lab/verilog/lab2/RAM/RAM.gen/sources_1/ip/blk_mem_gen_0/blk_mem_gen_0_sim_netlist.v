// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.2 (win64) Build 3064766 Wed Nov 18 09:12:45 MST 2020
// Date        : Sat Mar 26 12:06:27 2022
// Host        : LAPTOP-5I742T0T running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim
//               d:/za/cod/lab2/RAM/RAM.gen/sources_1/ip/blk_mem_gen_0/blk_mem_gen_0_sim_netlist.v
// Design      : blk_mem_gen_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "blk_mem_gen_0,blk_mem_gen_v8_4_4,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_4,Vivado 2020.2" *) 
(* NotValidForBitStream *)
module blk_mem_gen_0
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
  (* C_EST_POWER_SUMMARY = "Estimated Power for IP     :     2.54005 mW" *) 
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
  (* C_INIT_FILE = "blk_mem_gen_0.mem" *) 
  (* C_INIT_FILE_NAME = "blk_mem_gen_0.mif" *) 
  (* C_INTERFACE_TYPE = "0" *) 
  (* C_LOAD_INIT_FILE = "1" *) 
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
  (* C_WRITE_MODE_A = "WRITE_FIRST" *) 
  (* C_WRITE_MODE_B = "WRITE_FIRST" *) 
  (* C_WRITE_WIDTH_A = "8" *) 
  (* C_WRITE_WIDTH_B = "8" *) 
  (* C_XDEVICEFAMILY = "artix7" *) 
  (* downgradeipidentifiedwarnings = "yes" *) 
  (* is_du_within_envelope = "true" *) 
  blk_mem_gen_0_blk_mem_gen_v8_4_4 U0
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
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 20592)
`pragma protect data_block
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
0a76o2TCsFwef/hiKbDG
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
