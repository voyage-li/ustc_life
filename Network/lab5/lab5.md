### 计算机网络实验报告-lab5

<p style="text-align:right">李远航</p>
<p style="text-align:right">PB20000137</p>

1. **Select the first ICMP Echo Request message sent by your computer, and expand  the Internet Protocol part of the packet in the packet details window. What is the IP address of your computer?**

    > ![image-20221102164245511](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221102164245511.png)
    >
    > 192.168.1.102

2. **Within the IP packet header, what is the value in the upper layer protocol field?**

    > 根据上题截图，可以看到Protocol:ICMP(1)

3. **How many bytes are in the IP header? How many bytes are in the payload of the  IP datagram? Explain how you determined the number of payload bytes.**

    > 截图中可以看到，头20bytes，总长度84bytes，所以数据部分长度64bytes

4. **Has this IP datagram been fragmented? Explain how you determined whether or  not the datagram has been fragmented.**

    > 没有分段
    >
    > ![image-20221102164827611](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221102164827611.png)
    >
    > 如图，均为not set

5. **Which fields in the IP datagram always change from one datagram to the next  within this series of ICMP messages sent by your computer?**

    > Identification、Time to live、Header checksum、data

6. **Which fields stay constant? Which of the fields must stay constant? Which fields  must change? Why**

    > 一直不变: Sources、Destination、Protocol、Header Length、Version
    >
    > 必须保持不变: Version、Header Length
    >
    > 必须改变: Identification、Time to live、Header checksum、data
    >
    > 通信双方必须使用相同的版本，Header Length描述ip包头的长度，也不能改变
    >
    > 而随着发送，data会改变，相应的Identification、Time to live、Header checksum都会增加

7. **Describe the pattern you see in the values in the Identification field of the IP  datagram**

    > ![image-20221102170940241](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221102170940241.png)
    >
    > ![image-20221102170947475](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221102170947475.png)

8. **What is the value in the Identification field and the TTL field?**

    > ![image-20221102171306873](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221102171306873.png)

9. **Do these values remain unchanged for all of the ICMP TTL-exceeded replies sent  to your computer by the nearest (first hop) router? Why?**

    > Identification改变、Time to live不改变
    >
    > 每发送一个datagram，Identification的值都会自增，而ttl经过router才会改变

10. **Find the first ICMP Echo Request message that was sent by your computer after  you changed the Packet Size in pingplotter to be 2000. Has that message been  fragmented across more than one IP datagram?**

    > ![image-20221102172515117](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221102172515117.png)
    >
    > 如图所示，分片

11. **Print out the first fragment of the fragmented IP datagram. What information in  the IP header indicates that the datagram been fragmented? What information in  the IP header indicates whether this is the first fragment versus a latter fragment?  How long is this IP datagram?**

     > ![image-20221102172959929](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221102172959929.png)
     >
     > More fragments表示已分片，Fragment Offset说明第一个分片，总长度1500

12. **Print out the second fragment of the fragmented IP datagram. What information in  the IP header indicates that this is not the first datagram fragment? Are the more  fragments? How can you tell?**

     > ![image-20221102173011890](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221102173011890.png)
     >
     > Fragment Offset表明不是第一片，More fragments Not set 说明没有更多分片

13. **What fields change in the IP header between the first and second fragment?**

     > Frame、Flags(More fragments、Fragment Offset)、Total Length、header checksum、data

14. **How many fragments were created from the original datagram?**

     > ![image-20221102173448421](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221102173448421.png)
     >
     > 3个分片

15. **What fields change in the IP header among the fragments**

     > Frame、Flags(More fragments、Fragment Offset)、Total Length、header checksum、data