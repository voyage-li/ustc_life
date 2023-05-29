## 实验四 用 Windows2003 实现网关-网关 VPN

<p style = "text-align:right">李远航 PB20000137</p>

#### 一、实验目的

用 IPsec 隧道方式配置网关-网关 VPN，连接被 Internet 隔开的两个局域网(VMnet1 和 VMnet3)，使之进行安全通信，实现信息的保密和完整。

#### 二、实验内容

将路由器、Client A 及 ClientB 的 IPv4 地址的第 4 个点分十进制数（如 192.168.86.202 的第 4 个点分十进制数为 202）改成学号的最后 3 位数字%60（进行“模 60”运算），其 他部分的 IP 地址也可能需要修改以避免虚拟机的 IP 地址重复。

#### 三、实验过程

1. 设置VirtualBox网络配置

    ![image-20230527223943659](../AppData/Roaming/Typora/typora-user-images/image-20230527223943659.png)

2. 手动配置路由器，客户端，服务器ip地址

    ![image-20230527224141352](../AppData/Roaming/Typora/typora-user-images/image-20230527224141352.png)

3. 配置IPSec策略

    ![image-20230527224212740](../AppData/Roaming/Typora/typora-user-images/image-20230527224212740.png)

4. 配置远程访问

    ![image-20230527224248015](../AppData/Roaming/Typora/typora-user-images/image-20230527224248015.png)

5. ping测试

    ![image-20230527224337024](../AppData/Roaming/Typora/typora-user-images/image-20230527224337024.png)

#### 四、实验收获

- 对路由器的工作原理有了更清晰的认识
- 对vpn网关有了更深的理解