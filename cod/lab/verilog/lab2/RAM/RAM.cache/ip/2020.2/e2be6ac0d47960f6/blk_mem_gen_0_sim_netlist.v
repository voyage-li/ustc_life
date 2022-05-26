// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.2 (win64) Build 3064766 Wed Nov 18 09:12:45 MST 2020
// Date        : Sat Mar 26 12:06:27 2022
// Host        : LAPTOP-5I742T0T running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ blk_mem_gen_0_sim_netlist.v
// Design      : blk_mem_gen_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "blk_mem_gen_0,blk_mem_gen_v8_4_4,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_4,Vivado 2020.2" *) 
(* NotValidForBitStream *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix
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
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_v8_4_4 U0
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
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 20608)
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
