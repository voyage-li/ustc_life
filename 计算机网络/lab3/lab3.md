### 计算机网络实验报告-lab3

<p style="text-align:right">李远航</p>
<p style="text-align:right">PB20000137</p>

> 部分本地网络存在问题的实验使用vlab平台完成

- **Run nslookup to obtain the IP address of a Web server in Asia. What is the IP  address of that server?**

    ![image-20221001213207648](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001213207648.png)

    ```bash
    Address: 202.38.64.246
    Address: 2001:da8:d800:642::248
    ```

- **Run nslookup to determine the authoritative DNS servers for a university in  Europe.**

    ![image-20221001213244164](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001213244164.png)

- **Run nslookup so that one of the DNS servers obtained in Question 2 is queried for  the mail servers for Yahoo! mail. What is its IP address?**

  ![image-20221001213400719](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001213400719.png)
  
    ```bash
    Address: 119.161.8.12
    Address: 119.161.8.11
    Address: 2406:2000:a8:800::e6
    Address: 2406:2000:a8:800::e7
    ```
  
- **Locate the DNS query and response messages. Are then sent over UDP or TCP? **

    UDP

- **What is the destination port for the DNS query message? What is the source port  of DNS response message?**

    53&nbsp; 53

    ![image-20221001221153614](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001221153614.png)

    ![image-20221001221203474](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001221203474.png)

- **To what IP address is the DNS query message sent? Use ipconfig to determine the  IP address of your local DNS server. Are these two IP addresses the same? **

    ![image-20221001225026905](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001225026905.png)

    192.168.0.104 本地查询相同

    ![image-20221001220406072](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001220406072.png)

- **Examine the DNS query message. What “Type” of DNS query is it? Does the  query message contain any “answers”?**

    ![image-20221001221122204](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001221122204.png)

    typeA

    no

- **Examine the DNS response message. How many “answers” are provided? What  do each of these answers contain?**

    3

    ![image-20221001220716691](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001220716691.png)

- **Consider the subsequent TCP SYN packet sent by your host. Does the destination  IP address of the SYN packet correspond to any of the IP addresses provided in  the DNS response message?**

    ![image-20221001221028655](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001221028655.png)

    一样

- **This web page contains images. Before retrieving each image, does your host  issue new DNS queries?**

    没有

- **What is the destination port for the DNS query message? What is the source port  of DNS response message?**

    ![image-20221001221804422](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001221804422.png)

    ![image-20221001221811982](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001221811982.png)

    53 53

- **To what IP address is the DNS query message sent? Is this the IP address of your  default local DNS server?**

    ![image-20221001221907673](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001221907673.png)

    和本机一样 192.168.0.104

- **Examine the DNS query message. What “Type” of DNS query is it? Does the  query message contain any “answers”?**

    ![image-20221001221948783](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001221948783.png)

    typeA 

    no answers

- **Examine the DNS response message. How many “answers” are provided? What  do each of these answers contain?**

    3

    ![image-20221001222027920](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001222027920.png)

- **Provide a screenshot.**

    ![image-20221001222055688](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001222055688.png)

-  **To what IP address is the DNS query message sent? Is this the IP address of your  default local DNS server?**

    ![image-20221001222358681](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001222358681.png)

    相同 192.168.0.104

- **Examine the DNS query message. What “Type” of DNS query is it? Does the  query message contain any “answers”**

    ![image-20221001222428923](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001222428923.png)

    type NS

    no answers

- **Examine the DNS response message. What MIT nameservers does the response  message provide? Does this response message also provide the IP addresses of the  MIT namesers?**

    ![image-20221001222550676](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001222550676.png)

    如图所示的域名服务器，提供了ip地址，如图在Additional records中展示

- **Provide a screenshot**

    ![image-20221001222739350](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001222739350.png)

-  **To what IP address is the DNS query message sent? Is this the IP address of your  default local DNS server? If not, what does the IP address correspond to?**

    ![image-20221001225429616](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001225429616.png)

    ![image-20221001224153764](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001224153764.png)

    18.0.72.3

    不是
    
    是`bitsy.mit.edu`域名服务器的ip地址
    
- **Examine the DNS query message. What “Type” of DNS query is it? Does the  query message contain any “answers”?**

    ![image-20221001224431599](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001224431599.png)

    typeA

    no anwers

- **Examine the DNS response message. How many “answers” are provided? What  does each of these answers contain?**

    1 如图所示

    ![image-20221001224604293](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001224604293.png)

- **Provide a screenshot**

    ![image-20221001224647283](C:/Users/voyage/AppData/Roaming/Typora/typora-user-images/image-20221001224647283.png)
