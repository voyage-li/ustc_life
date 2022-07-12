// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.2 (win64) Build 3064766 Wed Nov 18 09:12:45 MST 2020
// Date        : Tue Mar 29 18:39:09 2022
// Host        : LAPTOP-5I742T0T running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ blk_mem_gen_2_sim_netlist.v
// Design      : blk_mem_gen_2
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "blk_mem_gen_2,blk_mem_gen_v8_4_4,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_4,Vivado 2020.2" *) 
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
