import os
os.system("g++ main.cpp -o main")
sel = input("请选择横向滚动(r)/竖向滚动(c)/闪烁(l):")
data = input("请输入不超过四千个汉字:")
if sel == "r":
    os.system("main r "+data)
elif sel == "c":
    os.system("main c "+data)
elif sel == "l":
    os.system("main l "+data)
print("已完成生成，正在打开文件")
os.system("D:\\za\\logisim.exe output.circ")
os.system("del main.exe")
