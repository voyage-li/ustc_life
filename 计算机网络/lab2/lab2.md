### 计算机网络实验报告-lab2

<p style="text-align:right">李远航</p>
<p style="text-align:right">PB20000137</p>

- **1.Is your browser running HTTP version 1.0 or 1.1? What version of HTTP is the server running?**

  均为 HTTP 1.1

- **2.What languages (if any) does your browser indicate that it can accept to the server?**

  Accept-Language: zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6

- **3.What is the IP address of your computer? Of the gaia.cs.umass.edu server?**

  my computer: 114.214.227.222

  gaia.cs.umass.edu: 128.119.245.12

- **4.What is the status code returned from the server to your browser?**

  200

- **5.When was the HTML file that you are retrieving last modified at the server?**

  Last-Modified: Fri, 16 Sep 2022 05:59:02 GMT

- **6.How many bytes of content are being returned to your browser?**

  128

- **7.By inspecting the raw data in the packet content window, do you see any headers within the data that are not displayed in the packet-listing window? If so, name one**

  没有

- **8.Inspect the contents of the first HTTP GET request from your browser to the server. Do you see an “IF-MODIFIED-SINCE” line in the HTTP GET?**

  没有

- **9.Inspect the contents of the server response. Did the server explicitly return the contents of the file? How can you tell?**

  返回，可以看到返回的文件长度为 371

- **10.Now inspect the contents of the second HTTP GET request from your browser to the server. Do you see an “IF-MODIFIED-SINCE:” line in the HTTP GET? If so, what information follows the “IF-MODIFIED-SINCE:” header?**

  是

  If-Modified-Since: Fri, 16 Sep 2022 05:59:02 GMT\r\n

- **11.What is the HTTP status code and phrase returned from the server in response to this second HTTP GET? Did the server explicitly return the contents of the file? Explain**

  304 Not Modified

  没有，因为内容没有修改，会直接从缓存中获取信息

- **12.How many HTTP GET request messages did your browser send? Which packet number in the trace contains the GET message for the Bill or Rights?**

  1 HTTP GET requst message

  102,103,104,105 都包括

- **13.Which packet number in the trace contains the status code and phrase associated with the response to the HTTP GET request?**

  102

- **14.What is the status code and phrase in the response?**

  200 OK

- **15.How many data-containing TCP segments were needed to carry the single HTTP response and the text of the Bill of Rights**

  4

- **16.How many HTTP GET request messages did your browser send? To which Internet addresses were these GET requests sent?**

  3

  128.119.245.12

  128.119.245.12

  178.79.137.164

- **17.Can you tell whether your browser downloaded the two images serially, or whether they were downloaded from the two web sites in parallel? Explain**

  并行下载

  第一张图片请求返回在 2.58s 而第二张图片请求在 2.54s

- **18.What is the server’s response (status code and phrase) in response to the initial HTTP GET message from your browser?**

  401 Unauthorized

- **19.When your browser’s sends the HTTP GET message for the second time, what new field is included in the HTTP GET message?**

  Authorization: Basic d2lyZXNoYXJrLXN0dWRlbnRzOm5ldHdvcms=\r\n
