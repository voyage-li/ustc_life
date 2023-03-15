### 计算机网络实验报告-lab6

<p style="text-align:right">李远航</p>
<p style="text-align:right">PB20000137</p>

1. **What is the 48-bit Ethernet address of your computer?**

    > ![image-20221128215435513](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221128215435513.png)
    >
    > 如图所示：00:d0:59:a9:3d:68

2. **What is the 48-bit destination address in the Ethernet frame? Is this the Ethernet  address of gaia.cs.umass.edu? (Hint: the answer is no). What device has this as its  Ethernet address? [Note: this is an important question, and one that students  sometimes get wrong. Re-read pages 468-469 in the text and make sure you  understand the answer here.]**

    > ![image-20221128215633975](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221128215633975.png)
    >
    > 如图所示：00:06:25:da:af:73
    >
    > 不是
    >
    > 是本地路由器或交换机的地址

3. **Give the hexadecimal value for the two-byte Frame type field. What upper layer  protocol does this correspond to?**

    > 0x0800 IPv4协议

4. **How many bytes from the very start of the Ethernet frame does the ASCII “G” in  “GET” appear in the Ethernet frame?**

    > ![image-20221128220840179](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221128220840179.png)
    >
    > 如图所示 55个字节

5. **What is the value of the Ethernet source address? Is this the address of your  computer, or of gaia.cs.umass.edu (Hint: the answer is no). What device has this  as its Ethernet address?**

    > 00:06:25:da:af:73
    >
    > 不是
    >
    > 是本地路由或交换机的地址

6. **What is the destination address in the Ethernet frame? Is this the Ethernet address  of your computer? **

    > 00:d0:59:a9:3d:68
    >
    > 是的

7. **Give the hexadecimal value for the two-byte Frame type field. What upper layer  protocol does this correspond to?**

    > 0x0800 IPv4

8. **How many bytes from the very start of the Ethernet frame does the ASCII “O” in  “OK” (i.e., the HTTP response code) appear in the Ethernet frame?**

    > ![image-20221128222121414](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221128222121414.png)
    >
    > 如图所示，68个字节

![image-20221128222512876](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221128222512876.png)


9. **Write down the contents of your computer’s ARP cache. What is the meaning of  each column value?**

    > 图中已给出: Internet地址、物理地址、类型

10. **What are the hexadecimal values for the source and destination addresses in the  Ethernet frame containing the ARP request message?**

    > ![image-20221128223617360](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221128223617360.png)

11. **Give the hexadecimal value for the two-byte Ethernet Frame type field. What  upper layer protocol does this correspond to?**

     > 0x0806 ARP

12. **Download the ARP specification from ftp://ftp.rfc-editor.org/in-notes/std/std37.txt. A readable, detailed discussion of  ARP is also at http://www.erg.abdn.ac.uk/users/gorry/course/inet-pages/arp.html. **

     - **How many bytes from the very beginning of the Ethernet frame does the  ARP opcode field begin? **

         > ![image-20221128223848630](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221128223848630.png)
         >
         > 如图所示，21个字节

     - **What is the value of the opcode field within the ARP-payload part of the  Ethernet frame in which an ARP request is made?**

         > ![image-20221128223914223](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221128223914223.png)
         >
         > 如图所示：1

     - **Does the ARP message contain the IP address of the sender?**

         > 可以从上题截图中看出：包含

     - **Where in the ARP request does the “question” appear – the Ethernet  address of the machine whose corresponding IP address is being queried?**

         > 当操作码为1时，表示ARP请求，查询相应的IP地址

13. **Now find the ARP reply that was sent in response to the ARP request. **

     - **How many bytes from the very beginning of the Ethernet frame does the  ARP opcode field begin? **

         > ![image-20221128231425143](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221128231425143.png)
         >
         > 如图所示，21个字节

     - **What is the value of the opcode field within the ARP-payload part of the  Ethernet frame in which an ARP response is made?**

         > ![image-20221128231449529](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221128231449529.png)
         >
         > 如图所示：2

     - **Where in the ARP message does the “answer” to the earlier ARP request  appear – the IP address of the machine having the Ethernet address whose  corresponding IP address is being queried?**

         > 操作码为2时表示ARP回显，可见上两题截图

14. **What are the hexadecimal values for the source and destination addresses in the  Ethernet frame containing the ARP reply message?**

     > ![image-20221128231800307](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221128231800307.png)

15. **Open the ethernet-ethereal-trace-1 trace file in  http://gaia.cs.umass.edu/wireshark-labs/wireshark-traces.zip. The first and second  ARP packets in this trace correspond to an ARP request sent by the computer  running Wireshark, and the ARP reply sent to the computer running Wireshark by  the computer with the ARP-requested Ethernet address. But there is yet another  computer on this network, as indicated by packet 6 – another ARP request. Why  is there no ARP reply (sent in response to the ARP request in packet 6) in the  packet trace? **

     > 因为 ARP 广播信息是广播的，所有该网段内的电脑均可收到，而 ARP 广播回复是单播的，只有请求的那台电脑才能收到

- **EX-1**

    > 如果arp添加了正确的IP地址，但该远程接口的以太网地址错误，会提示ARP项添加失败：拒绝访问，同时访问该IP也会返回404错误

- **EX-2**

    > 条目分为静态条目和动态条目。静态条目是写死的，没有老化时间，不会刷新；动态条目是临时储存的，有老化时间，会刷新。
    >  每个动态ARP缓存条目默认的生命周期是两分钟。当超过两分钟，该条目会被删掉。所以，生命周期也被称为超时值。
    >  延长规则：当ARP条目已存在，使用该条目后，将会重设超时值为两分钟