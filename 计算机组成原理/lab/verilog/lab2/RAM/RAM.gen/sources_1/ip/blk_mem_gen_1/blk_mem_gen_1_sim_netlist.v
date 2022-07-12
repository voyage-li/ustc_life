// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.2 (win64) Build 3064766 Wed Nov 18 09:12:45 MST 2020
// Date        : Tue Mar 29 18:38:30 2022
// Host        : LAPTOP-5I742T0T running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim
//               d:/za/cod/lab2/RAM/RAM.gen/sources_1/ip/blk_mem_gen_1/blk_mem_gen_1_sim_netlist.v
// Design      : blk_mem_gen_1
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "blk_mem_gen_1,blk_mem_gen_v8_4_4,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_4,Vivado 2020.2" *) 
(* NotValidForBitStream *)
module blk_mem_gen_1
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
  blk_mem_gen_1_blk_mem_gen_v8_4_4 U0
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
FjoCCz/Nj9ixkXn7mNZS4IblkLiCx6GJBnwCHjqSa/dDi2FwD7xCm39ryAuyv4OJHz2dk6Ab76bk
KiQHeWAOQxLgyw4BuvUCY/6+GLUD2MxedNX6HLOZy/tt8MccA5YBBxx3iBMbeMoDRoTA8yv6rnjO
0PLMibhh8BGGmIRzfMPf3muTs8fdU6D9N/d3DRHk2pPdp34A6BExJVaYXQTCBZgc2z1MrzyO0pe/
EjHWIPWvsc02Jig+PNNtnnknj86E2yZqG13ragAWUT3qKDuiC4hH3blxPLoHuLf4+aygJeucJw5v
HWe0+G9N2wCXOWPs/NgCgjFZ6DHbqcKlQNyhoKcb72EQJhpZi1Vql2oaACixZ1QEAeopy+NTcfbP
Iq4GgR7qAhQS+k+oxAgCV/mgtIp16CI1OAiGSos0t63C5qp6/PEvmvFMswfCqyftm4JBB6kMSi7f
6pdHYAiXdCrmGEyYJJ3zFZNjypELcy79d5qzPewMdxEb/0ann6gY/c270MTP69AZ0bNOMDMfgPjy
mEW+Itb/EYr0F/uabgcN/09B9r8NwjQ79tnAcGOWu3gVU8VxH/vMKhxUwD5jxhMXqY71qYlGvdbk
LBvjBU+NbmndcXwo81uUKWTSNuHPy2kJZQtXhQj8QBwaZguNG9glJdUKZWVMUsKb32OB3ldNfGYD
f/xOjnsgx2DHVDpYKh1oWIsZBENPj3PjdbD6Ep93HzKFoDg9XLkR1m79wDDmEfY4K0M1w5VHdv7u
1aQd5WTjhlqxPopel1xpnJjvOBKT3TLCstJbr9shQN7dlI0CwE8kJXsNrnhgvJ04NfReLLwCjluj
4gjtJvVl9nh77C5Z1rBw7e5+takSytPhrgEHqY6xgxcRdq6qpseOL85Uf9DpYVPxvzXdL4iU3UCY
7lOigq/sPAigljS7O0DSDp/vJ3PNyZ71xGZl0zZOJcwe93NLnGQckTpNEB9VvLVLRnqAH/8ywal/
EkFq71Zdhu9MmCWsKzadxAqmqcEc9NkCdm4DjtJ1Wf8bbTVmEAOox+cU6m8lTGLW8uT20WEXth3i
zS+UaOVqH80GTR9jI+GWGjhIMnYTPdFjVb4SXlstNRkOVC8SN8wray80LroCb182Nt/dAIvRsjOk
z0ccAfehh6El208/EDMe+YR/3DwI1j8sMVihkBtT00RYsv1pxCr0TztFcf7KERddEY5GYQteKcZE
4815CBheMdhHekDpvsz8VqDIQ5MJSNBaEVxfV3u5BWGwUtM+CMaJJdHk8Bcb2fSkKrz/qR+3f4Fc
ScHs0nv4KrnOkswU+NNvN4aPEpht/hfUiNSY02DxyTUMQoJRjpE+KIUOQEQPk8vMZl9EgwG6BP7v
wdTfw4nP8YqPULzGZBHFh1ULcAg4nbxoSRmhcfME68HWiFwCk06Sic+c0p6ysFoqYV/xK25bCAei
HSvVSDBBE2fEzSV0lCUg8NWDBRFQcKD0yIR8RHG9d9DXF6Az9syM0D/p6ZEtP4zfwGm9t7CCefEf
3iMXiRMDzzyuu96rcw+xduOJ8oKed+RJsBPE5YSwTnORaHbL1Fdpt7truazTcpFFhfNDEuqL5yH8
N6lSlFkmqs4C5QrZffgdOPYEhAFKNf6VKdexOQcquynbcyTVnf5J5410xCZq2H2d8VzS4pqKl8RF
0rMfxNz2jxbDSHN3r2JbNnuM1rL5o3edrebRFUjUS1HQmRgaERny+wfniboYcV2YLewxUjnbBOoM
ECW04J9T7PhagUhszaB5XVRY1drsHWNQWSbovcSSfDO/CGGqni1xyV+CYS65ubAfqrAZg5dItksv
EP8Oq/LYmxHX8ze722wkYkJYoxZWGra4VAHDelr6/hK9UQJdgBs5Kdgyl8YxFs37ir1cWDLJd8L9
rMo5DClgjrxZmcbbAYiAJbT2yexjmFww6KFAhD4rEPptzCPLu+2H6gEjYESAxw0QK/QuwS1VXZ9U
hOuj94XezNDja/Di2qQemHHOhPvIYG2hqlxZ4hFhrI2/Ygnfxm6Jvbr6MuIYzJJEDNzE4uI0oVbe
PZNX2bbN6A5k9IAyNnCvSM94pOXwpXmvAZY9wU7WfDg9LMAsgq4lvkBkJvk3NLbB9WqtgAMN4Akl
gYej/afqGuZeUVSzPaNROlJDnnseBWg6M5o4QdShJSH+gYeP5EnC3wTZMuQM/eWFwrNwcFK9IoVG
agCGvI2NDCStJ5WVFlC3S/87v4ZqQ/kTrou/NxK3KuYg+Yz6xs9c3O1NH4COeFUyIkBDVfs1+aBU
fM267mVHqwTylLxvGJVEeq6yEz8K+UB7llZb8zU+YBmEhOs8LSYktfc/rjvM842PVaPsjO3j4Xz1
89ku4fd8XhoG/J5PXciBGkuFt/OSkFMNu903Vl2+zjANvlrXuMX+q+d8SDZZjGYwTgGKpPzWxLT7
h3+gy6YNvMf7v/XfjC/Usbwa+32W27xRCc6IWSgNvSSwcuuP5skEWooC0b0zPNmWV0bnAF/V3GFx
K2Etw7jJpywNaXtrkvIhblms7FkzIfUt5kIhoqD9NbWhTrSXTHfG88wbkZBnx18M6zZcOa3GbEcC
bFxA2Lk5h/tpaWBs7yEf2FDY5Vrc3QBnstbkE2z/RMNH1vScUy1nwJMEeBPK9+iSHersizz4KA6W
4Y1jhXCdK8xeUlSk/TNxtnHT7f/QakHIOOi+7wIgLHbzyHE+VVLkIDtgOCwgXpMyxnZluzpTEo92
HMsnLCwd+XfpbO0eJaXSIMM0BiXU/2Z23q65Wj/fP7f5MtKJaAT+LSjiUgRi8BZyxWSVJkmv4XHu
BUzmtD/cdyCR6Gh4WFdSqZCFoqoRAyeUUIeIFaSkJoYB4H+Z69XW2SgWC4dGWrczQ5VEB2ty2GSd
HuUfVWmMfj91qsJqB0HPuJSHzZTJsxBRxGQglhaOsCqVhbxsWQ9X4F4iN7ZHxXfucqNEZuAP52JZ
NURzKU38ipnlB4KZFhJtJIr+5rD2mrIuLtqXlLCTukSJGd0ukjRI7CrvBCo+sGZD0jnLYfWWGE4J
8OSOySlAC7aIzwPKN/ZLQMfOfn1LlY2qWlwTkYidELyvIPIyYEG2GNA+WVdAolEzJV5BHolKJRaE
gKHlHI+tCfM0dqvd4WwqUe9dveG2KL/08KnveedoaKWdC1HdYJuAYYDyoHPHvXhWnbK9g7JFtrht
PNUwVE0bclFu2MIBplES/U+4m4kHobZfe1HcGkREitQY3Z5bKlugVrXKz6I8xfEwWNk87vETapZu
Whh6mvGy24KIG/HqPbs8YM1SekCoPPCU712G15nWp4xx7cbKsQ/h9gtX2ZKD+zueRvGWohzXmUGo
LnN9Rq+/xmCIrHszBzDbjazU+ctlk8dNHzhnZzhsBK1cVLm7BKmMlALruGWIJ1DtaBAdE9dqZtAa
govubgXOE1r96BBaouNYYokCKGYgI/8RsKKx4ZOYSptTwqEg3cQrKjeTclUENqrFytiAMfjbR+vk
WCbbeB9qdhlOvi+bIyp4LexBIWnWgK+bb4E3cfk9sP0VB2EQJ05OWVIIPzlSfVdpmKfROhwbQ4UM
tqEkfj8M4/TjMryzMo2beQERfWPpYwAqIh2deuIJl/ze2H7HR3Hyl3aRak03Ttx9GifrqygHtldX
YXdFmlsDc90o5RlVnB3cUelBLsFRAXZmltXKEAxBHa9xcmfLT8xWyLQzAwt3p7I6fPVywCdFk6ma
grnDi9fmklZWeIslhn8KAQqOKcU3cZ5zAIA9k1zjuVO5legnw/X95cglnquM2jnhHlg76G/qeP36
2sw1QsbuW6WqIbiTSCvrZ32JqZzkdovczzkDi0IlMRD6tVSdCALn/KYvasPIMQvCRpo2RUV6YuFX
7v0Tukzr+vD39k7jj1w2qFYsSQK8B+m/Tjjq7EfysRReUalqD5RhxXSYaOkpYfNTXpivtXEbjW+E
dY2TiZwz6euTxv+wImbnsxzx71u2L0Dqd8tojiPsbIun7BGAtyt7ouK722LSF5MClCdPmLr3wk4D
NxvfoISmBAlD4sWXeQVHK/kBRO+OW7J6L4eYwhJFOZ5xfTDLzRvtd3kxGz2oNYRF5TWdXN0W8IMB
A9izZ1SRQEa8WminjPcQoAB+DBVXeBw5ZWDr/1HM3skYVDEJCijV5LDUl0IP7DaRt4VRLsOrsmux
XShygelWUNYT59+3pu6C06Y+qjsd6dXgo4xUqQ7gLn7/LBks2+lo6peJdIldMEodtfid1tohefz4
e1wJCqWedybgOuz7ufD16GQTxWI2rpsWK/Aady6+QEFkWhn7UpUR7mtNpczQQQum9CN7wsfTfyQ9
TB1gHghxi47WCMthCTlIlUr4hObsG/YDz2Dwi9Uf7AraUQfBc7/Mo333hhIpF19JVJW6X4Oymixq
xeJqxeTjuEPhWi8XJbF/xJxruaPcgRyttbh4fChWe8FDNv3qlRF1i4NL/VQaDsahqIDCmcIuEKCO
LE7a3NqOTikHuDF4cAT/razoUrzk+NNUZ/KJv2fEqTTW1Gr6UlbRrQJWNu3CsZiWWq/NuebvJck3
qHxcAviH64zJJgdYAbVMHpkkQxrU+zd0iu69Qqo3isJ4WwVclLrYwB9efx6cjEZZMXtuBC/QoGkn
JTeILn+1RNEHXSAZOJ1FaeUXt8IsruvFybhGOyk+xtYlmc5K0JAM6updyMcuE22NflAjePuRLbxv
rWpZeOaUMS11t9U1KEeWPb7BC/lXvvTHf3q8wl7wViVlImVszfDA1Th6aW93K6OgCvimilmkEXqL
kTKzoSlVn92ORerLunjTDn76xPhNF/P33RDA7nfvA6GNfeW+fH7aNrFxzKmDQEupu2hJOjBfvIP0
C+Iinh/FUFiF0vyNLbjiUw+vdU1EsabJSyFvWXTCkNFJj5OkU/jeQhHVh/6fDtyQSjnSsjVCL10K
FVd7El6p3B4Kwn9+T+7RDLImxGMfH4ft1CKzA65jkiXJmzsk/5gjMY/nMDXsNiNmfkDNlvMWJQK7
nsUMavG7+bWilszN9MSFSg8tSVxPpSlkcFu/SzBDMrc+5fnH9ltjwiHKrTW0eOBKDAnBkdgFX3FQ
9x4fPpXDKVlJY+KfENgzbwl761h6hzCO1FLytJBGYm8xIyn+roea6HXqih+RYUj6roQwKg/d2/r+
aaboZcZRKiOp9ZsnBuzf/3rZ+2o3eUUPCLj26++R2FlYEIk5EfzlaGsuJC4WUkUfJehS6ykQVL2O
oYUYSRL6RcA8at5ndQCXXnJUdQ3wmNW9NjJ9yMZDeELUMP63xc73H8SMRi9i0Owfmlw+jsYnGVP5
BdVBjWZoLlxhWscPrkq8P4YH0cBrMg5Ov74g/2WbpkfWO0791XR5V5ZzX1CZuw+xcjYNMlklhF+N
2R9CPo54cMj1q3k4qZOS2pBTqIUF7wCY1i8EBXzrCDoGDfhc1UcvVvP0gM946GygBm6RnMi6vJZf
TYdsk2vDHwx7N9PL4wjy1Kk9OTWXjpQ/E4nSw+CT3gc3v8SRAkG3zM00u90HS5CEGD6h34mfcFxx
5O4Bf5M3STXcH1veicfaP2LPoW/pfNKJkNJEHMEX6Qb8rDeFkMuLOXlABfiCbqjT1wO9pHWqvitQ
nJbZYMsYQrgiT6JAVWGca2Wlfw6UfioknYlY/XxRCCRWFa5O26mk116UMVHH44NbNLXsCwrO4uMR
SbO3e3LgaC55kLtym3WU/tLf13Kj6G4k9TSW5IzrjTQo79FAX1dXXKmFwtD8eDSbUQAYHuoiKWaW
5slnW0OH+zs207nTtod8ug/qEG/d3O5HVpV4vWOVdXkMy+bCdiSMUVpmQ6vQmqPabJDJ/QcWwsww
AxNWZu1M/fPvGreoc7/17VSe92Lox1PjGpmn2MUxUvBhtakx3mkQ7+ZncodrCCGfuxGV1GOjDBys
UDJDYEPnNLlWPo6hGYzGuoTWmZp13B5FVZWBB1ZLVqTBkRLJX9TYAnsfN1u+MTh4+4/9A0vmKBce
0wUYaBVu2MaMchr7PUs0puAkxZs80/W0/LrUD73QH/N8RVMWBEma+kk7HKXOgi7oB3wOHCpzkIgt
i3s/3ZiobauTabMWKqcqvdEwA0KUcFYpEUO0/Dxxo7lw1cdY2eJc6Vw3qI5Fb2DeQ2TddOJYsB/6
xEEZvw0jU4zj7UrCCCZemiXEwtzmQegWyNlTddGun7e73XKuGaugqgucCN+54DS7ZVSnpDDVpuIS
GH6PXbGgViMs9xOGuBLIOM6MCi+FHMVSu5OL/uNAgsy+/dQzFwLHZouYHGb+ggWRwKv87h+nQY9y
lflr4AMuLd2NEM9pTdlDBYZ41QRuw7PltuH0tQIJot4tHyWGy40xU7OBmz5/oYLLpXazlLykj4fH
InMJv+vZUj2QajIIaYB0UXemPHa8sFejigvxWufo5YzdwxvWRARBU/HET/Td1h2Y5NdNYRQYJj0h
izKjuKSQ8wckjzzjl6lQqo353he03NfFwD3wu/f0HgX5+Sthnfss/z+y5T6mGvPumWgY1fE1+Atx
j/0HTJj5IuPdqkVfk/cU+sWP9dC540WFmQu2RHlHI35HknRPu70/R9BPDJ+etQleHbK91H35P+5B
gt01szDIGl5zyfd71FALU4GjdFRS9IaC9eRYlOQhQpcZeFbtwdlUDxiZIwMeIcm8ofGE+T79upnr
l/PMs1/T924MnROm1ieMrY79hqpsQB6jbrc9EzyiMHEp0qk5kmrJ72kHraGbqAefeQBnL70+M44T
47ObhPUWELfd0KmWYATaojhIfGQWxL9PHnUFBUJRUb+x4Cgvqa/i+azIFCYWDGHlrJT9F8zR6aNu
haOMVlI7BbrntTIMa7MmzLPawLLr9kwewA4djJ6DEzCWrzQLpEjzVxbyED6HKFqdLWd/bmnQqYYI
nEFKILRXeeUKJTo1kt5JTe6/8NW5aMnEiUXAZmqOavoIdVo9GjnQqMGSFWL4i7SCJjCOXRr5GFox
bSl1dnP/I4svkefSOBvaneNtoLetR2BkhTd4ChwZVGOAJWMQamC2P5RHjyNaVSEj/M4xwc/wTl25
lI6H/90TZ/rP4/VpD1eHWC5RXaS+34XNEiy7FhqbyqDSirQeVVGFqyoGsdJ+R4GAMxryAIYHIkeM
5Ei8oh0/Pe4MO5j7DyvUeRe8kIpmq3q6BxvgjviM62yr2QozuSFw0PS3C/Li5puoOVKiJhqbP6fT
zb4Okzc9/UjTa646+vwHk1wb34lHLG9ZhJ2nntfmHgBAjajXeJOpouGVnTtmz7J96+Ais4JXvQgV
yH+6QPKt3L01/GUT6J0S8RqqAwoBIij8LKKOv8NiIwaA8qz3o5NWfYjKEmepWiL/VrBTR/Xhghs0
UpuajutcYrA4mWZDSXmSN7Uj/W2U6AqWFHLDPl5LgIfw1E4DApghcj4LEMQ/ncIYmZm2FfnzqTX2
XmUQv+FOUH5v5NhT1Nfbivv8frby3KfJXzBXDaBP8J/LduK+bZ5gvyuujrnFFblH5v+hpKxu4cSO
G2lmquzMazjFoUsGUR0J671xlYTcMEhPvqXhh1CyeQQjF0IQvYEgCMZxwDnDn6OuxVfeDyfMFMa6
YWIvXxBKFrvT8xbkqtr8AtI8oWDCNgmuQFQ4IZLbmDEng+iravNT8BahykKFFROVhda8Y+H4a8gl
yubqkQvwH4Y8NIurpThBhagvtEcwZYt3e1LYfdqT9xozu/aJQfrCkHn7dMgoiB1Hjf1ISB2Ldqvh
IqcG+3/1nWYwTQ8CroPVzYJB+/j6URek/qXztO1RWmSF9jKtmwfAMZQLS9cu7IWkagd1G9QfOdaL
HU3DVKvN9P16weRK0qvbicy1aSizvCn9/SNyc0cCagi1co/7qYSvE+uj5vwr4xdQsX9ReNi9EJCY
gYBW6FkxWZHDhP29og3pUWv0W7AmAiNQTKdcSxcFwcrVf6ML+MlyDj5xOyhwW4HsODRFnvuTQcuX
Yy/NVSGXqes0xbxukCrCnqHLGed/13lRvZI5nl4mn6d/IUn+P1GlzI3CTRptAvQvjj4fF2vFVvD9
USQvNkkuuozFLqIG8EXoheEJj3h2Ch1HEQJ7mSu0swjGLFrzjn50ta8z6lobbnUCCQuWWkAZ0poo
abzM4bRMZiFAQz2pyZ2lD91idcHr2ZWOcDBM4ZVtr4+1AbTSqSEOL6Xk3hEMMvQRk8AYGI/tRUi0
wUR62garg1ZJ9+yvks/Da6EmmMOVb8uy9v9Ny+wVDZNK14x85dX0JdOJeKCm5q+In/9kNWznyd1A
5kO5f7w+JaXd23uT6tfw8oRVtHEQkfd7Zu/yKtvYgZq8h4yDVX84YKDPamingvODBFm/Tb5leZXe
JGP/smj96E48kzk+eaxXZn7AjuoW5/XgV/dWAFyUCLPBu4n7zvyqNqcGCSGOwVjZJIWAr11NbpLY
6naSnZboBfPynjJuRy07UxZFSwUtgEjYjCdAEi9lDD08zSQmMdG+X3JtdF56iBCpsrMnUxD6mcYR
76gqof0lAVen4s5+iilOxIfbg1rSkD9vfE4cRXVYV3Onx6IvEVnQVErILNbc1LhMc9dm3KHD+4tD
b4AYdfGUxspx1rMqCbshEV9SpE9UNN8OcOvBxLto8su+3KMD1YFr2e8ZJwj39ibIZFdrSxWSUefx
cLtHi7smBziJQSjZN5UhMlWnOJRoyH0Fseb8J6yzLtVxnaNVqVN2FqnNp9ao48RyAqbLQD2q2t6F
mWhVJ3gueTArRH4st1Jcfa4A0MIJ4YD/gsmpGoR52Z1dU54tV1ps7iIB5gKYr2IZy0CLK72rYJeM
EyXgHEKbF7IyXHp+urrzgwdK33fFeQD1+p3Uc4et5uFcbnq2VmMnqXzwu3k5uuFs6HInSx3m1C6t
tymiBIgAAzLL/I00aElWxPE79Yf+6b31COTKdRUZzG4KWeEyhSokuARelgletDUjaJGFSdK56k35
sq2su8QGwJh9CKZtL5uLW3x71bWjT2hmpEdUSx7WN2/1BJkWRjaL+REjdVVDpttM5PMHgNDDl3bS
iAskovVAVVM+MfMld/DN2rAAX4xq0Hi+RFBtRl9AVfP+Xxiq4D17X9jtAEuJkTczyA/88kezwEso
B18RRY2y8umqHb1hXXuz2koDo1HS2GKxJ6CFnseqw2ATNN4ngkh5nxGwLwtsGxHdHXrgO+efnmu3
N5oVXhwagtnnhqBCNPGdaUK9Cvxs6EYj92SxIZohOQzJgzsmIwzEYE/ofoqBBZxzJRQf6k0bcggd
AaaI7B9kpTdJdAhDzciVJ+62YPh5Ys4IambMM8B4bu20LcYLtffpw5B/wtshAINNPq+A4u9sz2B2
FMNslfIfev5Wh7HsuYZVfeXfGDy9mmAnGhLHXnh2Z9EaPhTtNweXxUphZZwa4uNgdjDfB7yMiyic
ngQ/2usxmXJGUcE3AY6SRn/+d4py2f0TTEbjr/n3/Ts0LCiZ6AJbNCTyDumrnZX1dwQXo9VuXKlI
hToDGnYBp2CfcXZ1OrsIKhGxdr2mmF9PCfrL2cVPK26eFh6QFSdCkxWkS3hLXY87OHWvlKC5GfZs
bvLc/sitDzxB3wte+JIGv2tNK6ahVsxy1hJjsiNBMk992qtMjOPuPe9VV9mvyIdVv70NCBYqIk9u
Nix3NLLclA1IHBjKByBgGWGkobxZd1B9RJZ5HdBq595n9BkVVpqBZMlZEnBTGLfzzTIccOzca/G5
3IgmkZEs4e0csNl7yXvNUyea72/K5MI+jcICc6gWwtevivRL5CMvXSTdPm6pt6yX51UupJ1yw3wP
3cPZTOAyje9enwOg5c7mbTOZ06Fop34/SHJsjR5bu339HvKvCgxwO6sCFFPPScfe6gGrAbf5Tn+W
c6SQDP7C8ROsfPiLxFgEbtBUqR6iWoAlNfShP8CGjM3Ml7yH6xyXRDgo/icjJrpn5X+cyomQ2ZiI
bCdpjuBuV57tflroSaBg5t5qQiFM24MwYbaZQu6cvmx42OkBBnxB1NYNs9Nbaq7RqWMIxHIEi2jV
YGIB+ydj7M1OxdU3IXljn4xlONRhsBdd9sKwMMRH+J25P2mfLWfIFN2TzXkhVSp0Og/9d8W2N5LD
+CjXk2lONt2e9hK6mVSAh4JP2IABTPCd6pPYXiAqrDdlqBctx++uVK1yCTNOkT8BklTbegh89Osh
oxIl3ZS3c87yZRV9OomsyPx2NINrZUj3njHZS7j6a/shpaHH+Dnn/q9Hl+2gZdgfhfAXjUtX+KSP
Lkql++2iDOVvjIQSYUSWoqYLaFWfoku/z9n0HS0xaG4Q2EExgX2WaRw7clyxhq577KmYk/cXn/Kd
4m3iitTg3cybtcdc9SZ0UjDG5pGhkgfS1AuZ+4cjH0ZzFfVR5iq0A7iVpULBXYlZK2Qnw43A6a2I
YaKSO2inx51A9tXu07ga7ypP2T/YlU4+P2NFxeYK17i7Tw5FtXiMYYEYuK+haWZ7ng9HfS4N6S3q
0Ki+sUOMpFWRpF+DeEPmFc9QLfbB2smo7VVp6mlrwBY4Wjpsi4wL8qSvqHS0VkD0LE7BeX8KdT40
XVQkGLRwx+V1cuEooIASu80o3uWP9r0R4fFr17RjRP0tTGTiiDsxyBxkJ2YV68uQpWlD0Vamjdyi
wHb0qCIr2QyhuzykUkNo5u/1Cvpn0V8lFBVvZRqUMpYIlI11Z4b6FnBkQ/yBKxl4MpfF/vfJLgz4
SbVqW6YMoFyaAuGRIOnHyBeIULIDKwbtfa9x0CoC1TpKQHcbvrjPVO48OomBZUzDB9sS6ZbQTqGI
/yMx2dWEf3I8IUTtRryOBoFR/A25DIiZ2HkkEVQ+P/friH5PlCDOPG2zTAtX2L9CqdDXhVeboPRr
MaoFGqxIgsWA/KHEA3oQNClswcmq3SKVKaRUoZ/7iAE5+wHhxPc9IjUuBFnPRFhT970zkOfSNX/J
OEAw57j7bCAuHmqclBXPrwcEWPEj1ZiHt7s5G/INAhVo8B2WD+VMzfyxDVlRb0xHk5ExIeL3UWsZ
1kYC2SfHqrQ4WyPabPJaImQtgXQY3eVMhNh9nmn8H20hhHc5HbF5JivLlsctapdvNnll9o2EJODt
qHP3hG+JQkHsMqb5tI47gkTeZP2Muvx9MNteCZen+FneAFqVJ99OFC6BEYZ/aEtvuOcsauWgTadw
iN8kt465PL6hci+lXWp0es9weuq/SoOwPz/SsuR2GuZFNdLqptN7x5t8xx5DXoMdnUHls48WWiCY
/CT+dv+Bku0dDJP5McbvldX2pxrLDgo13O4nsMPfdAgT1NTHll6h5Nk0XKvo8AT92TA58n+XuK9U
zpVMknslWaYPi9W+tckY++tY1+h4Cyn8q88guLYiBBjAfENBywA5jUwTTgX7pTZq9XdJgspgUDqv
hI4bwf95ojBwhzrzoxOGss0sOU69ujaWxkVrOfA2F6YGBVtnAbq7Yhlq0PzfMwxYpQusjOhZq90x
w49boDDKMkOCpZaJGifTSv/9wQZjN2LpXXx0aHAG5P37ShWyoxA+fz+lQjwSe3y+VeBm1CC02ZiK
M1Xb/2T4+/AmbvKV0Rhw2CtxDue5dKe2sEaDLLTEa8yBVJIaeMP/Myv7Rq41ZHCvOsVGunCOAEbB
GSKh8zpqRLb12UyoUAvc7J+fgATpLhm3R+R2xl7r8BY0AnA470EUZQGL+XYFhxaji0xA7BTqkZtV
pspcA+g/aj8JTFszDpdziQ+p4pQXwETLjLvykCh/pUFeoNaytbzbt3EuFkOr8ENmovLKlRK8jOEe
RhDD0Dpe4optbjTr8A+G1FXh2qNdA5L9rNQ7yfXsuAcHK8UEDyqz8UKwvwOCYGarmHwLx82ZJMtC
Mm/7gepJs1z5BYL+74zqcIlY1LMsBh2/k1iA8kId9wlnWSTarQ1eCPMlfDJ9sborJ+vy2SeZrbGC
SMFsGZh9c0bu/IQvpMqsNOBS2Bxi88sc6oeUL0Iq0LYxOVI8F30+Er8wPTjHTo3m5TEz+gf74QhW
DcXZWv5QZQZiTnbyY1l+2xFfbwHnIzRhFtTtQDqSCh6GbZH4uJm9SJUqKjAI8pYjYtFpWXld6l06
rCWH1Inp1gb2S7mT1cSS1jtmgbccEkloOcGfM8xGdttiGARwpCIO4WKZC+V/tcMAN8wRPmqcnKgn
QyNXaf578NIsNQBDP5gRDcVafC1ZAOHFVjphmZJf8fdK1qsr3Oa1Ujmyg2PclEF2NP6NVj3mJFg0
tywhPYI9XSm/NQZraYN/ZdZXZBmraJ9+CUYvoL1xIDQ+8mSXXGBCEc3t7Q2whcSsuUPPFqxdG0sU
bJGCV4SDukSYELUWD9by6NQdQWqDLXJGqgjarCuBXQjwsP0mfmVV18RSd227+yWrled1+RQlovLv
kgXsS5QaZnPgaqOxKQC2OIjjmNEEKxGRj4V2YHNjwQXQcNR8DzG1+i/w9oNBoU3TayQ4BxX5YaVo
Tyh1Uu4RDDnnXueSmHWT0zKxWZHep6ffsstWHzD/O42HJP8VcvPVBuuAG8B8aRYBJ35yEgblK6W6
YpvkOzqI15pOK8ZiebzNjfTlkLKbnPFY9Nnj7XQexjUG5lx7HUziRV9mkeuq1Yj9L28luRCJGmKo
fW78Q2AV1UhnZ7XAHR2Vf3ranHkiPeBCzNvAe1oaPCGw3gdSveQC8nleTSoPxrsB+YwtEWZ59Krt
3uyuw3w7igBAy5+Ppuer2d500SCJGsCWAQklxhhtAzH9iYEs02C8++hCMIwLLMTr+RWqfOi3mGIp
ISiE+oI2ds+74ULNl9/WM6n83VFEd792DmMPBHUkB7+nE2GbkSgw3/Id6Io/EwBPcoLfDU9B84fw
4lodesr7LaNKI95KauMO23zNPhMlvzY5OEDkBqjpcB386t0P2MzSu4jQmaZP001HfY70aNJyu6JM
GCiuMrEYVFKZ3J85FusuOerd1IhTOkwcEW9THYYkLuzeF3skYC/0/5ZqsYWNwL5BnMeVyxHXp7Sc
vR4yriTFgaq08VYaLKbpmWbMQ/fxk5VaqAYBKSqED8oXnR18mTCTPh0FJJQxC4YNC3OKpGkWckls
9/lrJfFPtWu2a6D7zGjuOtn7+L+EBMwGpSWqa4zIjeGnGsZdTHUBqtD00yge4k3hlTJE9uFnKxmW
Fg/aoRSiOZAX42d9S8L4SxTTRI7JQkiQrhPudZ0vBfKrhX6EbHRpk+x0CxszTW0c0Ppf3rqE2SC6
HdNOBbGgauSn+WFY2hgH5NIFYx4/VuT8iA5QHqPOkaerCmXtT0YvXh6nqXOojXbcw+kxtMALZkD2
hrbgii4I6g9D7FF520T13bkMk9HbHM98UkawjjfXC5p1TpFwfQhTagXYKG6GgUMOGzsfKOfDuVAw
HrpTQTWc2nfrdeBdFn2rCNWg3KZ9IrnDqIZzZqtf3qKSN0+V+BGtAwAi6E3DVE7MiUKvu0c7Nj++
wu50sXWgMfUE2SRwHt0IHidrl3HAWibp1kWvaj1VTujzapYg0HP+kLhvpsmbTB8aaeOMYallMvVL
tbJJkmZlfyRUkBAQZaSHhCiLvGVdHG4mgQ5NDAgVAvg7GrMfg0ZKCVzIZ0Y+QG96VO3b0g38h7op
9fVQbxhRMFbPp5fscR+lDLpu0WkxjHSYkgCORlOjF6HU6PpOEA7C28hBwpNC5vgJGLcoEnx87z42
712wrpMgpW+X/dE0tONl9VPmlw1G6REdXr+sNmwlbpaPCswKvsMkCPPtx+66tqfQnznaM6pWwD+l
MLiZvZ1lc3BaaHOBTGDgN4Z2qC7iSJDi4KBaoIB91K4Rep+2qeVioDo8HQo83V6yQdXIFJevq2cP
WDW17c3IWeIUL8JKSPiX0TJHJSlSOf1NPjfOVtd0IUSZ8NW+cHodYD8aKrnffnUFItanGCasUe3l
LvuBgND1BwVZpkkbhNthq9XMshUsOkSV3KjG4BmZiNvta/mKsXVbrTpSeshxA0m8zcjPzMcwuoN3
jXXOSkG8ScuSy/ODtuSkGZljn+KJOA387Q+C8JowGscdIIwye/RaoRe7h676lzw5zWGKpCkNmU+P
X0lnL7364P8RCuSdaYQdYZU7fvaWtHp2Sp6X/4fP0c0656V1OTI2yiTkgRuqicfTsQnKtboKRxBy
TabyZK6uLO0QPMYae6en+bQSLQV58wI4nAI6j6xBpaks5XHH7t8kEJsKSmerRg6Zhf4m1FsnBFuu
xiWoK4YT8U4oqDlKIg5H4Qr0PQUA6E8khzXgyFr+TmMhiLzsFGuYWS4J2j8NwXfCKEJ392WGs81H
Xgy0zpc7yzeUFKqkIhC2z2BYD7C9hN8vqyHNe/NCJWxhFsBbXmVzrXxyec1KPdlsQhNLU9QuyEKK
eiKKFDPgrGBOXyexmy7UnAeicJ9sGdvCoPT0ud67/UXOebn1YGlqtE/VuugcBNs3OaT7PJOQYAVg
VXl+c3GoKoUj9ZWqKVOjQM95PoegTFquLNn4G2FPM6X38EKoNvFfhX1S2JaXZSiwREC061oKqSGT
6O6Y5Vs6ly4EjlAVOVm29W1bF4lRXa8pW82DEezRbh6hvPd/8hGRquCtWQSSLCabxQQO2Pi0rPGU
VF726FGFH2BmVAJVC0Xd0byd4fCeN78e4xHEu5rFNv+KR4RaMW9id6hjv800mMX+iIMejIHC6/Qp
X5pFCOc8KvWroj44nZXA7cwUEQ2ABI0YroJ3FCuh8FnaAVrpBM47B6f2z3sEVf5ba4Xo6sDZqGRT
82wOQpsshGJepkNIzQlCLgP9TOs4N0SSF7pcDIpFs6iF3GX0Hqjrpw/jWGS6KMkxn5n3CwmfWk1j
8+sbvyHX4C3gl5gP0mCmnyC+ivbZ0OnB4O0RQY+3FmGz6/HGcc2u4JI00FnVzqW8vZ+WPkaR8VLR
ed5oWyqJJloj0mdqHyQVU7SPbAB5ZfPcfiJ06YXhmHFCCop/w4Zpfg7OLSLPs0CN2KnSGuqZ1kiV
0plT4FxuFRIyp0o/zYFmbzaCwaG7GG0oZxaZRZS11BohwNm/r2lMgDZ0tX+MB71roJd5W7fvgaKW
PdETVi/SOvHPdYYTaHc5UBIc1SsYoGQANdKeb4pfamRf4n4BB/lVtKq6FHEuW5iZWOKJ3CkJMGYy
TysLsHnVAj2e5/nGi6FnG5kJN4yAkqaPqNTcibYSJ5BN8JZIzM8CiPYals/PjPuxhyAmatrU5uun
GykC7wWEL5sZzwTmflrJuxWWvzA7e7Diw9CBjUqWovCu6dYo/1Be4nvmHBtHCrQp5qlLluN+g8iY
ob3PxROQsjO/mnZ7GfPw36OMYEo+WsYVBGRQ1K3DSOw4wtlXSneTCJiM6sbIh0n/QQrMmrJdW3aH
ZtnWwc0puygTs2rOpNa1rN1Tfn1kxMvvtSZFvxkTFoKv0XqNgBKVkitf3Q5VWAkgRM4v2mH4Oyzc
gJ1xoALZJ68VIt+F8BkMpeCZw8e4UFEtsokj8oPSrnVEXrcc7G904rCeueDjXo0AGKkN/tgSieAw
1ZN3qJ6Kik3DF0Vhhtj4lY3ahoFdbIrzCPChTgR/l/8NFi1N184cWhP8QPaLQoX7cq+J59OiCgEk
6u8iF+H0m1wJbqHSjhG9eb/Z3ysI3ca0dWyiJ8KfRuKHm7ucsKcWch+i3DMm/cGSveK5v/qlwKHm
zAdGI6KJtkF9izbJm/ZNaxC5amp6PzRYo3b1yBUcIkOWub+3fiPAI0Hq0fFcz4liv54UTlyvpyHm
2FMQ6C/f3GrxquTXIungVFklQ/tTilx+2l3eEY9uL1dcVGsFkHnUa5vXhpXT0dWXfIHX0Bv18aJ6
AySbzkuf9y8t/+WBZMiDFAQ+KBM3dDtVFD4Ol5uhK7jiLZYfdJtbV3l+OaU8mIgUhjTltSAgCHdr
WgofWv8pqDvp9UDecuraZak3D0MGz03lFKE+Q6LzKZziE0HTqZCOs1UZ4ThoiDqM1KMSnkmp4qW8
hOGrFqVl/LYguflq9bolxsS1vL9EJxi5CSJHHXGyP0H0G4viuFa0uNKIRbogW3IsaPI21lWX7qVG
fJLM4mSQ7Fjyru2asZSlJwe0Nc7RiuwmStELSfonGeesafqbpCgDc3ygp78AKd9PA4HzhCywng3u
L0iXn7ymyKI6bcYUvMpsnljtHxUoiDsNGJUY74X74Q3q1JyDMqKeH5MWyy2gt46ROruFJTH1jRsp
KMyMh2XUwyO0ZXN6uM5muVx4Ebi8V57giFq1tVd1PYxtqrbOH/eC+zhj4FnNQX1WRGndeQZno2z7
fPqlOEMOb00iiY0+s1heklB3jllmHcaCUsQCTgkgLR4qmx0uGHf+vlBlQc14zzfGRYczEqn+hcbX
e0GK92OmhsbUGUu/BAH3vUoksHaVIdwUgj8Qgv2mRa7086a4y2LlBy5y5XRFWmRRU3ycUUiy/tf2
nYEocnqQz5DfbfffTCVo2mlygzCmAV++AeF+brl4rsQo1T6OuzlmKoqHN9NDcWRlhplVCAS+stcK
/aRQPu/zv4zZcShCEyW4JKsuxUqmuWIPC8d0ewCVBksMgwWu+KX2EDFATlDk0hdlVfNwxyKZRtcm
D9Erl76VA+EOjCasKpY7MRmKXVvc/nAE23L20IHCUt0hyXwQ25ux8VOZskky65TcPPFcazIKHqwY
u4e9n4yz7YwE2wIFoo7qTNhgsrLehZGVR7TLUnx2zaUKrW4AgixDkThFVyfM6oCtsT4df2faUr8u
CsEauiG1HPNePFRUDxpUm70HvZcJ6dHcCp0cAGj5RbCqI+xHiKMwaxg4QanoMX80qTO8RsgoJFBK
pt5KTr6GVyAwjkQK7c1g3H8XbQCEHmdWqkAyjCy0u/N6F5HRhufhjkgR+U+2r1D1oyG6iq7ubce2
zr07MV8Pn2xPzrvOUvsdlRlgfDBxrljAfw/eTMDsRzF8i4Mnm1429zMdZPrjmbr/moQvs62RWiSv
B3nXa3LjGAixl1LcVbncSlY0/qyyjVbLv37fHz8BYn2n6glCN2CtVaC06BRRtmMStAg+I/5XqjAx
bbSqlWAB1P+u5Xwh+gmik30gk8GwntkbdBFTEPTB0aocR0ud9szC3qdj1qbH0/7/HZypu20aNRbU
m9mO4j7vd49Oj336a8mdr27zim+63yaiq3sdjPv5l/OqwQG0tIaZD58JfWSxJAKssWNxKYTio8Tw
aEnjvUrTaMAXgoACFF/klB4/PUZ830BtlEVEUYdknDAPKFQZWd9pBYYLn7ohfmwNYW3zIJLlTWXQ
81AeGBt79S1Nq6hTOUVG32ghWXZ6TrR2rXFV87ZNvbXiOa3E485fFHqMldUvKulWdcacSNqoWNDx
8dD6iwDIUrAMioyC/DPFkUJchgVAjpY20seHo6zuV33dauvYvkhQSJXT65Dq04N1NzORsmxvedFN
BgxZlnC2uj//Ae0+tSRuRl5JGziszTCAkdTSsqsTgIDDbio5iu2+jxg2+H+i6oBtKRJu2Km1j6ih
li2pwEoXsvcOoxItD1BYcNpFz9OO4tkyAL/Baiu5u3aXp7jLRcPrbnQONRFan3fwKZdf3ki+AnVs
c8boc6cDCpragGto/kfq+WcZ1n0y7gGKeXPorBoWiAzbE1m9TfZvWto3+02/5l+qdL28i3UCguiZ
dNaO+Hw/3rOCjmth0za77SrV708N2S/mRuB51IXBw3Db0RXZc2frTX6NXjgoI/EqUdLv1ccC/NPh
xE2LCrkM/TAxWyHXVEgP9oY1pmfi4O7z53hJfBgoqVFA8c8BgOkgk0+Rn1b1kZYrHBKSzYYEBkIc
n3QNyTptcGOe6Gs108rL6jlRqDTiS8lA9brEsH7Diq9lvkhm1CuqcAe/hcHdLYm3iWOiFdZdPUvF
bQ0LRqfFhmHkc7GDovv4D8hcVMlD5m+HDa6e+VAQweV0CWI6IgoeSMj9tbqKWY1eEHhH5IlflcMg
O5V+rb9kCi+Nt8P8AUKhNlFm6DzMfA9cw8inZ8ItI9k4kzulpSV1gJlAsnxY3LMslkaKHqIVKh5Q
IYm5NSXcf7ccT1R4qF7DaNCwj11m8LqLG+04pC+yyuVqkNxlXX0bSFqB4+FL0fpN10CQs12Wx/43
VQJI18zwBCIyYrcAeFYWCtdOOPTN1zQgkDEjNoffgw59eLCdw9f8PKjrdNp4n/17J8toioNJYhNY
JHFjLwed7QS1vC81C1KVasomuNM0Jc/QSopiDrfVEK/IJZnpJ3X/YF4oixDFrWWgT8iJpYV/IaKS
wpQ9dnR+9croItfVuEBFjdR1fE2Qh8j1kQjKbf2vujE4xMnk4GJvfvLNYoMvHY7EgzPA2EJqueCt
HrJPlQz/OrlNbaFik2p1oQExreGR4N5NaCjcVdg+OZDnNVsel6BvgJGaRVGsG6l/FacKVNW6U4qI
D1z4wLbJ2Vh22t6W1icmG9zOkamIHYQ7jBYLFZgtgQ86SNd6MD3E6yjTyMwf/uLvQ2eX7N20kPmS
PDq1Y+RB4HM/7TUpO47py5wMSQaen7ik2WPC5D6bg8Ot1ywt9Yuk6XAW9M+DZJkJ/73/mz8NEz/Q
WYb6gV/yMHmHMZna4e1RADQROu3NvvSES9UzjZuyfR8teoWSO6lGGeW3yz4bIdRLOXk96koGMU+v
GJ93DPO9Vi8dkAjMxdTCM8qa8bfUnQe6SK6h2XnjCrkghVyCsk4Wml8YBdjzOmBgZ3oHP3YIZjBN
Z4OAS6SdMVDVXPlriw26MsqX0TkaOHNK8fSVQvg8T2CT0nWQ1CQwwXvoHVlvMQqx8oo7YYeMnpqF
98ncWzdppX5ywo2KDY8YsdiyfqiXMZIOyMWxJ1V6E3+J9lulk11cyv/uxmorZjY22vA0gyD49FtT
Rt/7dPCnh+9VItLOJPwfKMnGkLQAkdxEnJ+FAufSsZO23zwRrDWm1+rII6cTzfXHxbk8P7I5Nqwd
5dXnoYF4+PnJFcE7xd/DerxISpJRxYr0mPUSoVObjPzshtTJFbPKMqsLNytEVkBfw/28PRBjCUOw
eXH08VLV/KcXCIy3sFLyq2Q1q+zOOnfLS81vuW49UTDogUCknNP8COlaAz1PHoNcn3oK7wLakhvs
27L9sUpxRpVi3s7O5rKONP8kBtgcYYwzol7rdnY+bcW2Zdyq0p1uKQ45HXT5yG072DgkWXn7cGBc
l4Ttzmk9cXYzhzzUEANIhk1RZLxFyTmstKHvVx07pZsfLNbcnCYBStBbSfHRb3uT2pduXnz0Roto
bSFtIBtZxdoFxdbprTZKwa6mYMHdn+mhyjIBqnBTOS+rgPSt6VyCAc78SdObXrdSGA5ITb0d45mB
TrCPhJPWaTiGSHuWoEHyBM/DGQ9S+fifH8k6jWFl1+AyGQtvPnwwv5pwA9UqwEPjHlg+daZF1VJJ
c6q56KHPJ3ie0ZxkC7CQQBadaO3TNu5L/ZT109+h4Ce9u0PGbAuRBXvG7Kcs50cEKR0lxqbjjyqj
PU2jmN6zvSIV+1CYsqcTO/yehzyYNrEd2nUfqdsNH8Zgz+3gXAblwd92HGyXNSBTN8HNKWGYw0rw
DWbtUQSCtTw7ZfadNhqBjCu+4MrUB8nnEURPJqMVkqbxk89tmVvmK4H9WLAlfxCl/NnYH7orEhoP
93g1S1zzFT9J6wEdgHNfAM+jFl8MW3+tempiUKCPCcSWr9s40MK+TAPuNtbmch4IMSqNm9xbyDqu
C12WY/ioTEAZnTDOuIDMI3JpFocq+YnQR8+I6/qwQMWpsJSauoFixoz48zi+C1SG/guDI7EZpFYJ
nTZIHmOj9stYDNt8UdEjBjPe8Ohbq5Q85mGWm9rE3fT5Ul6g/grN61DuV+6Gku10Uv4m8OeIAt5G
27tgtWSzD67tp9ySNN0wh2cs8GI7npVGBFO+6oZArScK3kjASAo0YTNa21gBC9DrJCRJg5KPoV1q
Eqz20ATlv0oNUbaKpD9YKNYjsmYHTCF7I9yt13wfb8B6AKLEK6H9myW+whmjKtvxBHCf4B7e3QYy
58DudAZ4TwcfPwJ2tEeAHZBHC45I/T+uAjwRTsi7lD3VxjzDqtj+x4h/v+AYtCtlHbm1ExElHeFa
WUjgo5zSeYJZoyK5/NaoiL8RMMVuhvE49vmKGCerl5/7odsQkDVQ9zj4nVbE4n5GVth2iakPl4Ut
1w3KqmW1glYIP8Xvi6YXhJdoBcBKknPaqQNLBOKUmXPPT9VHPm1JFsNn6b29JldF5H15uIlaEb8S
wGm1xRLZmeU2lDoidqnAjL2Aw5ackIBdtUIjgXKnN0PABzF6ZcN5QleEXjfWPi8M092PjUjdvAa3
1+DQcTgq155ramAyg9LSRmP9B/DoMChVQ+d1Z72D4D31fE4apjh8FdKFbbFKpOuOR5S4TCcrbCH5
qAs66AxATVct8pqHqC4mW+4q3I8FvXdRR/fGovS+IMk2zw2So5GIpjSV8advQD/tjQ8gVC3sfRI9
F29uZBfRvjBHFh4N+67gTf/vbT6EwToCk1VSWLNLA7eJvg1PiCmqG1v0kQ7jjthTfodhLqcsdREi
tWg1PnOZ03z5fYYbB4sK+vDcGZkDzTh0WLNAIyKc999MDq0fsiSasi18+updGM5JaDZKioTJz/c4
xge0CotqaN2eypG9K/6f+4NE1YPbQWVTf8TKvDPlkfcVxqQCAJpnXL8ctLUTn4EmaFO3UqcnTQ75
ZNFEtnIvgptbGbKUDo4irpEZkHDg4QKjQq3EzMegGhdB4qHVzBv+euVe7KDr5ke3AUixanE0tGzZ
oTHb4TTsKotJ8XOXZynL662BmembLFE96Gpp7pYcL3QvNXl68/16fpeb4g+pVGYcvn/kD207GF0q
9GLoe98Qlq0u77MAooHerSLDHuU9p7+/sOIyee9C2IHiDjPI2WSEfVwW4ti6LEq3Elm5iZ9OuXaK
1y8elepLwFojSRwi8r7u8D8VXn6t07QTpFlKhoDo8HiLEA7M5DJxRnMrCH10n40N/TR9JwU+BVKW
DhC1dFIIpaF15bPW0ajVjD9LOLAZeahJxkQSNjmivh4a2tAUnqheFOcJ9Mf4IAGLv6TSFIUrkg8y
1oy6YZ+bUkOnnbJpR3ZkJDMWIByQL3Rp1DPXoFBDIHncOhdyfFmJkVNOKc34FMp/u0f5XGH7fAle
US5AF437pXFgJK4O3sXKYa0PsxoafuHqqQ544fy3+7XKLu6LuKaJmBtI3b+r3zRPUGKLdBR1Fo13
WAsZr7SldxO4t07eEUbUvFurdJtv5VYZsDUBAxZOk97bdvEmjlUsBIc7rhm5UJ2mkCoDC+o6pX7U
GvpLZHFEzhX/WwnPCUb7oLKGHQ2IDjAXrXRgnERNn6Dp0Xgv6/XWYvZHy3xw7PKgg6ROUtMCC2YY
E/wepQLyesY/JoQpTCq0J3pykRoe0SITVOjkK5TOiuYDimgQtgU/TRhYzpukGh5Sfwiq3u+wbuq5
+5EUdd9SJnQE4lP1JzhnP5yWybqm5h7yDKPLx6y2yMp/iz+ga/xyM6zi6FHBSiT6tjd9zZRyUOFa
fbIhZZ+ec8WqGR7TWiLOvJvTmIXPZvcMJUd52uGcTIagFEnQ1b8eDhIaFKdxR+nqmnViDvWijg0r
sXX1kLuStSnOoAorsgUZQ8ELhxHY/w/k+0SquX9alnrVbK4cEzz866ekIXmIIpQZaJPsP47c5TKU
gP7+KDvW/eoZdmjB4olxVAELSV0XpcGQG0//vPh6/jVO18eOPmXZk6/MzhL9kANi9Afq2Kxjlzgz
HGi6DI7SslLWsBQV1FbqRPzCcb9OUEyK6VZROfBuKZO67KeKZDb+JNgvmlb/R/vGsWfwOwmwAC24
mdODJuZ5VJ/Ms/uQGjOLfGzpJo6cIWxdRnqGVmT8wkIk92FFp6OVbYSnJT0eTuzyfie/49pCaToH
vrC+D3jE+pOwu4zco4EToUgaQg9KSNVuNfR2Cgh8KJZRpmN6bJEAb6GQ2lsoCh2BmEkZWymGYRk0
dtae3iQ/NeBgtACy04/AyPcr824LOZaZNzau1PRVz6ar/QJv6UzwBDWXj82PMHUJDjRM1A1c30sE
i3nmybvTVRRtWHwu+PgZxvipRny6Xa9zmL2ltNWX9c+dbnIqWx6JVgX7c0Vecpog/+HhGvv7F3Io
dhQkkjTUP5lDHvD60hTzMAP/FBQd3Ek2IrS5ltE8fLxsUw46ydiajivgQbsLeqdqr0JgI/Zhzvj4
yWp/7QpHfBHLRZM85j9vZpuZpG/axAnAnqQVx86dn/+HmwX1NyJXds6IycdumxnCbbw20uF6XZqh
ve6wZB26bgdp9DtkD3+SPAOJ0fjayuCmEk42BvcRsKyAzKb8WLz1nS6rBAd2EzAFwVRwEZW74LzY
GKMKvx26PHi1CGV7ASqjBG4+sJHf9Ke0EFfTEu40B7ViB0dkx9FjrSRdGRJy3NMLSCUajBMhdLfm
4v0rbj4/BxA6/3g3ubKbZfGPVjEFVDhYdIZd0sremgmJyUW8YaPq8+72npLb1Ckt9zzY8D3JscC7
JCvr7wao5ey+OVwEz9x3M2/ffGNFN0mlBD8RCOMrxuMh5WYxcuxfXe5uTsaqzHO9iawEU5GwP/PK
d1kZABVqkPzREWj48A4YlvLEzF/NEKlI8HuuejAFOr08Dx37p5f6FNyENhzft+79ba6+LnytFOgk
rSvQLCeGMfr2IUNZz/ZrZSoojCxQ9Rh1guMpXkSLyPPdUtInfQoaXlofjo9gh/4TaOn0Vs95l4kN
iDMN8UMVZcIQu2PBf4SF4KPgJ33txQavvah5+4jafBgSzRyd405jtY199U6cQ/Yf5QAcpudOzDxu
2oVFbT3UvxbCyoQ5c/FzhBk7dG4QUZDH3fzM3XQBd+N/xsiZ8YeK49vfAhHMY7P4su9Vwa0rUmF7
gAINUWWW81LnErbaD+f3GgbA4PWK1QsY0a4ZN7VwOFYLfRppJ1WR8qEqAq4oFAyARdx9dRTpcd3m
v2BqXE5Xi3XbLCyWRpGkhn5fqksJiW7K7YbVIYqoTsj/DQKH2VoC9V+ZscMsDwHi6rOBbR50Pies
NsUNrA17qcWUawnHhJon4XUlOiLFcJHFDbIgGqo5tSzE9sjDe1ELl5Lisz9jH382+9c2or1J85PH
mXGHI5mlNSpmQh3Tf9rgvySJw8qunNAm7dKyECx3kD78LAis0QMlDr0EnEJzS03j262kLQP10soq
tSBvWVQ3gvCzn4MA605viaAVlO1TUsx43M7bpsK8+fcSxO+XLxH/qxm6q5NqqB+lCGqctxZYoNls
b07Gu8YLoT67cqu4aebRtZzUdBoP26MFR4RhxPsmxls0AG88oXlOZsYTNKAO7yzDevn4kkuD/U0c
DtGu6DjXni2gVODMBqcJYcdUDq4BEL1+DKOPRYMvTN33SaVWoX/lS6TQoe8n6h6aFXvYrXaqpSEe
R0MlR1xXiiZkF5MkFXP3W/8FWBrIPJo8gz2e97fMeIQLw5uXohUA1wcs6IEGsxLBQprEHGsAwndG
9WwvXJ/wUn2WwRArfjeDga9C9JNrfO4/7aUlC6qF5HInp4VRvLofNdiBFMWTkSCkKPXmV8qnAUBh
9ja/GPesOaQyKl9XvDTRZ92Qr1BnDZ2OvYeKPYeKh0jCTtZ+lfeyDn9xw28BgSj0CXknCEDrmpl1
tz/BQBx5lBex2Zww5mjpfqwaJLQBZ7kmAgFx2gVgEyKNvT+HWhsFnhs/oWUnamXVyuVXnTcRLI1y
E1xLJZE6rVYWNBap5CGwIPWOP+vzIFNmPnG/Y/iHUDh5IKEtB8tk6mK3subLC8nbfI81ba1qceYg
Gr+3gmZipu/MEHB5OK2X5itFTYdolW9wqCkKf2Gtaa3YQcCLC6P3y04Dy3pCbUQ+GIbDqAxc/mq4
yQVRXi1KohjqroFc1opPtzy1ApsqVfFRhK/X1hla10ghq6YAhZmTrwZNP9oN9f8DufekoBMJajAQ
tIoAm7yAv1oXeoLr52fLjMsW1hc7HOBYGc6RyelaJSFIdi5CGH+rX5MtO0DxBj9G2EfcZGsCwMs4
L1pOhFHadb7EKsAD2dEa/JYaccknBxD+lohTnYcjGqK/5nJZBYle/upk5dyfDaf8GTGjFgz/A8G0
djv7K8Yvpsplm3pbExbTGZ2Ko1tLIDRNSmXgEM0Eh4A0eXTohaILq/cWFSfzAqbmMRhOyPLRGJrJ
ldUWe7RPYHvKHVP7Qrtp1GiZckHipVdkov1psNKM3d1LMuKbMYUd64orj4FeNYZt3c76e3pojsHq
W5eYu0olgzb7vUQcxpQqA7OMNWQOZDVtH8FeGuygHadB/ckT3OBucZ5jOjCfLhR1U4eYlw7e7SEk
jsWEkDBehwGzZX7+9/9eY3bAdA/r3RlG5r7dL+C3o2jtNoaQIow3z5n5KE5T3bZSItEURBQ4HDgk
l6FOrB27AGCaKb6/In1VofTEUoFsT/EIceO3T1T+ppFf6Q+7QEv6+k+deWX0p4PcryTGQwjid9z8
wrJnKgHKM+x2WSL1+Ppt0buhAoLVDMsJX7ahpxYW7aFXkJQiwAhaMpTis+M7gvwVHPoD9n+CYhRI
tXP1FAZ5ok56lCSbb/HvgCyLmBb53ircMGRgrHIBqx4yCqkCCt9gCFi+UjbxrjNGcsD3D4VWJ0Yy
MYOcfZMwvtfb1CTv/em+FYdYGHuI3FB7opeWDcJbEEGXUIDu6BJSimCg5oPRKt+qzEXd4K8pTI0K
J9snLB5H4mIWjc8RHXXjyDDBDs2RJpUYz/EpNE4j37vCRdkEZjyQbxgCw+8IrrddxGRXJgds0omt
ITbxlA2T8UGi99q+oWadZBMCE9eqzLaklcwSFisOTrCx5trjTEOSigqUkfv74Kt/ifhCBikLCkim
/vBtWZ+wPFzQ5hjsJxOyS3sIe8rdFTSISFdOPwlVFcypzK/7AbQDP2BO65F5fuTSUWWFymIQ6fN9
sjL6Xq9CU+ijg2rXd4QJRUUkCnFuvE3tNX/ex/Wg/VCTzYhxXEDkIcp2138f/DycB6P7JKRInw0a
+xajSkvvcKrwgk6qf40Lj8g3ilVUHUqdj8PCH/3DFqGcSGAD0TGEO1SUyegdj3jvg5mAwXSBjZxe
r5YVZFJGjX/VnU7bwTLZQqN5Es0hMlx2dowfZEFplSzQdQkZv3B9M2VKwo3LihDJ8YgYQJ/cEuMM
E2bdkYRpX3l4TrJerVYkDr5UWwpPoYVYAgscVMc2uGMy3FRXCjVup7ybPT6im/L+HTrj+RSAhBiV
qmnOQRongCef4yybMKqksDn0/yBLDFgq9OiBefzuU6gztE8fWuWBs9F9/x71bksmJTORi//uAxCQ
12fdqfM46tsk/vSIGeUj7UJo3ad12aqe3E7n1dWodjrKQKHYhkHtsx/adQOEZcOFEHT4lp1Wp9wd
DDhfyL25p2ZqKIB1bZgGmJEgFuv5xFUVX8tLgm59NHgTR3AClfYwIjtmtfBkIxYfEhMqreuR74Eq
CoKHCF6ST+eybFjCr6lWyZHawcIJnTo5yQLlNGE6WEbLqEsY/L8tCx9ebmZX8X7IuW6qt7+YVvhc
3EE334untDcsVBmx2Kt7ASuteib2Osfv852vrWDclOuOWGkLyDHdVTNvIM5qcDgO1HjRg18ZzuZl
1o3ptNwc+1ks5NP7j2OfVo5pnfFZX6J3RNLqMjkTNqh6gILVzR8bD0HuRyx9YX+7uEwGZwpuJjqP
tVCBaXJEqbolRdzsfKPtbEh2jrjLdLXy91gjA8nLMRmfe+pAPErScS5R6fS2ql8qFGKlbThOY0Xl
ZCzs0tYP/TwO680tm4s0WkcHh4zKUdswfhO2W5Ry6DbWGAuraDHGNbVszCYHBWWq6RfEcUcXgPAc
rYCrz8GKIlzf7wInsFcFbjM/s9yJixjSefg0jzuYUr7hkGlsYO6Vvkcza7YVxwWWqbai9MUocRiY
KbqQB8nDC4nIg5RbFuGqY5psbv7e0GkdkYUyvJ3IU2LMXE8mDSGnAj3gnuM5OXCPXK+R1NTXSUMH
fWSSGVWaJJJXeIDUvztgScIVeGTZoQs848jtWa4XJaWUqfHLzwDCJkiq9K5Y5yLe0oDneTqJ4NQK
QQ43zGJ//JPoI2cMYq/PIBK8twcrQxd4NnfdeoDPCIkb4JhzqEsh0TRLW6Wjn/K28r7a3OniQ9rB
pZIlSGR2r0+3uIOysl961GoG38b+BxZ40CiorYeuarwuzeq21TNTbBt0Vzb7HUqv8tgm9Uz/F/n2
ijLMe2Krf16ZysdWn8gf1HNyNloumQ9pVCx3lfr0Gtk4MJK2HLCuwpBRPzeFXLLdd0wE/zZSoQqv
ZBvpfPnqFnbPWY4mU9tnyTD7PPgt2s0c1SfNhBRmqwEIzXX2TPaNASm0eqwo6fMyjlzDyOR3UXzQ
3bKXGCiQT2wx3hJOIaw8xGsAhgXrHzlj2jxS9TY35HN5jEF7mwuJMXRtTCHj/TPHkvJucPBMZYSi
NS0FBBbw6mjzrf+bMwqIhdQyxnAxWqcxJPmb1zj6De+wRVG3WveXDkoI3TGDwrj9VR98Vrvzh3Oh
vv2NerDWEtwCyikvAnG6WClodXMAUHLP/L93suUtV8TGppcbnhD3Aesahn/BJ0z3vjRM86LSw3OO
8klHpxUBb5TCTDnk81TQaJqZ16ABoghrEwM0ujw7GNfFZ+B0V14I1xYfI+7KvqPbN2kUlo6f/GSC
RkhDutCugHL0jVDeTjWcHk9ZGN8zbIij5qQ/LwQTPyjfXH2XofXkaGoE57FUD0bGMBHQky887T2M
7nvmZ7QJ5oCVEoM/M+A3T6s9E4tyFI12C3HlfRBxSUSoTofG1N71OBQ2eY2grf76MNfFjYOnLj+U
z9SkYl9QHjTILwopuZ/sO5OmgL9FFt2Mu/NGejCGjQDcR39AgnP1yqXcGBGPbvSweONbqCx8Wo6j
IMV/G4Iz9hxNQy2S3AjtIMqFSdfWm5FIunv3OXgdLg6wD/LVspAAD2adAZeZyQy3ik2z5HJLlSSv
WCaY1aJPgbx3jfBm87N0m61+JetMUBPoI8T6AYjMzbNcV0ssn8JcR5DU+GWnkySzc5DVyuiULcoH
QRwjEj6tOR+JUnjX/I2qR29Af+5QbUUuCBd7A/pE9dz2NDcoiCa6Fh58PVe2/7bxWB5QM0B9onlj
ZZmO6K/fn4tEV4Ss3T29Qt3syyAH2n1h87V662fhoLZrXsOum59AYIkDYbwJMY1IWjRfTHIl80ke
BZC3aFQjQaFpFZuBCqm2j38flMd5+kwEVQ0YaO1+EaRM7sKZLX+Nc9vOAlQvOhS6Lrn+rBH/ng7F
WT6x56Jb90IEXFnhiDNCNwqf7tkPYQfmN83fHjh61OlPpKZibs88uTjQy56IMV0zkTquOfrjCPyS
VH8NFhCQFDE+I7Dvn9qGhJKE1TsumTNDF8awnp6t3sR5+1pFmfqMfpoxbKaqPuYv+70TsQgW7/zr
hiGh6vwINAvROabfhTRJ
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
