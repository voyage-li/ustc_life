// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.2 (win64) Build 3064766 Wed Nov 18 09:12:45 MST 2020
// Date        : Tue Mar 29 18:38:30 2022
// Host        : LAPTOP-5I742T0T running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ blk_mem_gen_1_sim_netlist.v
// Design      : blk_mem_gen_1
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "blk_mem_gen_1,blk_mem_gen_v8_4_4,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_4,Vivado 2020.2" *) 
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
  (* C_EST_POWER_SUMMARY = "Estimated Power for IP     :     2.64555 mW" *) 
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
  (* C_INIT_FILE = "blk_mem_gen_1.mem" *) 
  (* C_INIT_FILE_NAME = "blk_mem_gen_1.mif" *) 
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
  (* C_WRITE_MODE_A = "READ_FIRST" *) 
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
