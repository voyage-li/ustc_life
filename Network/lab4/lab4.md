### 计算机网络实验报告-lab4

<p style="text-align:right">李远航</p>
<p style="text-align:right">PB20000137</p>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*实验使用文档中的数据包*

1. **What is the IP address and TCP port number used by the client computer (source) 
    that is transferring the file to gaia.cs.umass.edu? To answer this question, it’s 
    probably easiest to select an HTTP message and explore the details of the TCP 
    packet used to carry this HTTP message, using the “details of the selected packet 
    header window” (refer to Figure 2 in the “Getting Started with Wireshark” Lab if 
    you’re uncertain about the Wireshark windows.**
	> ![image-20221017214433523](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221017214433523.png)
    >
    > **IP:192.168.1.102**
    > **port:1161**
    
2.  **What is the IP address of gaia.cs.umass.edu? On what port number is it sending  and receiving TCP segments for this connection**
	> **IP:128.119.245.12**
	> **port:80**
	
3. **What is the IP address and TCP port number used by your client computer  (source) to transfer the file to gaia.cs.umass.edu? **

  > ![image-20221017214513277](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221017214513277.png)
  >
  > **IP:114.214.218.114**
  > **port:53944**

4. **What is the sequence number of the TCP SYN segment that is used to initiate the  TCP connection between the client computer and gaia.cs.umass.edu? What is it  in the segment that identifies the segment as a SYN segment?**

    > ![image-20221017214731505](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221017214731505.png)
    >
    > **Sequence Number: 0    (relative sequence number)**
    > **Sequence Number (raw): 232129012**
    > **syn为1(flags为0x2)**

5. **What is the sequence number of the SYNACK segment sent by gaia.cs.umass.edu  to the client computer in reply to the SYN? What is the value of the  Acknowledgement field in the SYNACK segment? How did gaia.cs.umass.edu  determine that value? What is it in the segment that identifies the segment as a  SYNACK segment?**

  > ![image-20221017220006205](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221017220006205.png)
  >
  > **Sequence Number: 0    (relative sequence number)**
  > **Sequence Number (raw): 883061785**
  > **Acknowledgement Number: 1**
  > **Acknowledgement number(raw): 23129013**
  > 通过握手 ACK = seq + 1
  > Flags中0x012

6. **What is the sequence number of the TCP segment containing the HTTP POST  command? Note that in order to find the POST command, you’ll need to dig into  the packet content field at the bottom of the Wireshark window, looking for a  segment with a “POST” within its DATA field**

    > ![image-20221017221340882](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221017221340882.png)
    >
    > **Sequence Number: 1    (relative sequence number)**
    >
    > **Sequence Number (raw): 232129013**

7. **Consider the TCP segment containing the HTTP POST as the first segment in the  TCP connection. What are the sequence numbers of the first six segments in the  TCP connection (including the segment containing the HTTP POST)? At what  time was each segment sent? When was the ACK for each segment received?  Given the difference between when each TCP segment was sent, and when its  acknowledgement was received, what is the RTT value for each of the six  segments? What is the EstimatedRTT value (see Section 3.5.3, page 242 in  text) after the receipt of each ACK? Assume that the value of the  EstimatedRTT is equal to the measured RTT for the first segment, and then is  computed using the EstimatedRTT equation on page 242 for all subsequent  segments.**

    >**使用官方文档数据包，$\alpha$取0.125**
    >
    >![image-20221017224313210](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221017224313210.png)
    >
    >> Sequence Number: 1 (relative sequence number)
    >> 发送时间[Time since first frame in this TCP stream: 0.026477 seconds]
    >> Acknowledgment Number: 566 (relative ack number)
    >> ACK:[Time since first frame in this TCP stream: 0.053937 seconds]
    >> RTT:0.02746s
    >> EstimatedRTT:0.02746s
    >
    >> Sequence Number: 566 (relative sequence number)
    >> 发送时间[Time since first frame in this TCP stream: 0.041737 seconds]
    >> Acknowledgment Number: 2026 (relative ack number)
    >> ACK:[Time since first frame in this TCP stream: 0.077294 seconds]
    >> RTT:0.035557s
    >> EstimatedRTT:0.028472s
    >
    >> Sequence Number: 2026 (relative sequence number)
    >> 发送时间[Time since first frame in this TCP stream: 0.054026 seconds]
    >> Acknowledgment Number: 3486 (relative ack number)
    >> ACK:[Time since first frame in this TCP stream: 0.124085 seconds]
    >> RTT:0.070059s
    >> EstimatedRTT:0.033670s
    >
    >> Sequence Number: 3486 (relative sequence number)
    >> 发送时间[Time since first frame in this TCP stream:0.054690 seconds]
    >> Acknowledgment Number: 4946 (relative ack number)
    >> ACK:[Time since first frame in this TCP stream: 0.169118 seconds]
    >> RTT:0.114428 s
    >> EstimatedRTT:0.043765s
    >
    >> Sequence Number: 4946 (relative sequence number)
    >> 发送时间[Time since first frame in this TCP stream:0.077405 seconds]
    >> Acknowledgment Number: 6406 (relative ack number)
    >> ACK:[Time since first frame in this TCP stream:0.217299 seconds]
    >> RTT: 0.139894s
    >> EstimatedRTT:0.055781s
    >
    >> Sequence Number: 6406 (relative sequence number)
    >> 发送时间[Time since first frame in this TCP stream:0.078157 seconds]
    >> Acknowledgment Number: 7866 (relative ack number)
    >> ACK:[Time since first frame in this TCP stream:0.2678029 seconds]
    >> RTT: 0.189645s
    >> EstimatedRTT:0.072514s

8. **What is the length of each of the first six TCP segments?**

    > 见上截图: 565 1460 1460 1460 1460 1460

9. **What is the minimum amount of available buffer space advertised at the received  for the entire trace? Does the lack of receiver buffer space ever throttle the  sender?**

    > ![image-20221017225842391](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221017225842391.png)
    >
    > 如图所示: 5840
    >
    > 没有

10. **Are there any retransmitted segments in the trace file? What did you check for (in  the trace) in order to answer this question?**

    > 没有重传，通过观察seq一直增大
    >
    > ![image-20221017230627623](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221017230627623.png)

11. **How much data does the receiver typically acknowledge in an ACK? Can you  identify cases where the receiver is ACKing every other received segment (see  Table 3.2 on page 250 in the text).**

     > 1460 比较ACK差
     >
     > ![image-20221017230900361](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221017230900361.png)

12. **What is the throughput (bytes transferred per unit time) for the TCP connection?  Explain how you calculated this value.**

     > ![image-20221018210119279](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221018210119279.png)
     >
     > $\frac{164041 \times 8}{5.297341-0.000084}=247737.2723bps$
    
13. **Use the Time-Sequence-Graph(Stevens) plotting tool to view the sequence  number versus time plot of segments being sent from the client to the  gaia.cs.umass.edu server. Can you identify where TCP’s slowstart phase begins  and ends, and where congestion avoidance takes over? Comment on ways in  which the measured data differs from the idealized behavior of TCP that we’ve  studied in the text.**

     > ![image-20221018000919975](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221018000919975.png)
     >
     > 感觉基本看不出来
     >
     > 文件太小，发送速度非常快，且不存在理想的线性和指数曲线

14. **Answer each of two questions above for the trace that you have gathered when  you transferred a file from your computer to gaia.cs.umass.edu**

     > ![image-20221018211045863](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221018211045863.png)
     >
     > 自己发的文件完全看不出来慢启动