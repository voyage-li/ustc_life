# -*- coding: utf-8 -*-
# 用于演示信息隐藏的LSB方法。软件作者：曾凡平博士。时间：2022年3月23日
# Python 3.6.8: pip install -i https://pypi.mirrors.ustc.edu.cn/simple/ opencv-python==3.4.2.16
# pip install -i https://pypi.mirrors.ustc.edu.cn/simple/ matplotlib==3.3.0
# pip install -i https://pypi.mirrors.ustc.edu.cn/simple/ numpy
# pip install -i https://pypi.mirrors.ustc.edu.cn/simple/ matplotlib


import random
import cv2
import numpy as np
import matplotlib.pyplot as plt


def read_file(path):
    fp = open(path, "rb")
    stream = ""
    s = fp.read()

    for i in range(len(s)):
        tmp = (bin(s[i]).replace("0b", "")).zfill(8)
        # print(s[i], type(s[i]), tmp, type(tmp), len(tmp))
        stream = stream + tmp

    fp.close()
    return stream


def lsb_embed(image, stream, random_index):
    count = len(stream)
    for i in range(len(stream)):
        x = random_index[i] % image.shape[0]  # 嵌入隐藏信息图像的垂直尺寸
        y = int(random_index[i] / image.shape[1])  # 嵌入隐藏信息图像的水平尺寸

        value = image[x, y] & 254
        image[x, y] = value + (0 if stream[i] == "0" else 1)

    return [image, count]  # 返回嵌入信息后的图像，以及嵌入的比特数


def lsb_extract(image, count, random_index):
    stream = list(range(count))
    for i in range(count):
        x = random_index[i] % image.shape[0]
        y = int(random_index[i] / image.shape[1])
        value = image[x, y]
        stream[i] = "0" if value & 1 == 0 else 1

    mystr = ""
    for i in range(len(stream)):
        mystr += str(stream[i])

    return stream, mystr


def test_lsb():
    text_path = "abc.txt"
    img_path = "original.png"
    out_path = "steg.png"

    stream = read_file(text_path)
    img = cv2.imread(img_path, 0)

    pixel_len = img.shape[0] * img.shape[1]
    rate = len(stream) / pixel_len
    if rate <= 1:
        random_ls = random.sample(range(0, pixel_len), len(stream))
        random_ls.sort()
        new_img, count = lsb_embed(img, stream, random_ls)
        cv2.imwrite(out_path, new_img)
        print("success")
    else:
        print("数据过大")

    [msg, extracted_str] = lsb_extract(new_img, count, random_ls)

    print("原始比特流: ", stream)
    print(type(stream[0]), type(stream), len(stream))
    stream_bits = list(range(len(stream)))
    for i in stream_bits:
        stream_bits[i] = np.uint8(stream[i])
    print(bitseq2str(stream_bits))

    print("提取出来的比特流", extracted_str)
    print(type(msg[0]), type(msg), len(msg))

    bits = list(range(len(msg)))
    for i in bits:
        bits[i] = np.uint8(msg[i])
    msgstr = bitseq2str(bits)
    print(msgstr)

    plt.figure(figsize=(4, 3))
    plt.subplot(121), plt.imshow(img, cmap="gray"), plt.title("original")
    plt.subplot(122), plt.imshow(new_img, cmap="gray"), plt.title("Marked")
    plt.tight_layout()
    plt.show()

    return [msg, msgstr]

    # cv2.imshow('original image', img)
    # cv2.imshow('Steganography image', new_img)
    # cv2.waitKey(0)
    # cv2.destroyAllWindows()


def str2bitseq(s, width=8):
    # 将s中的字符转换为字节型(byte)
    bitstr = "".join(
        [(bin(c).replace("0b", "")).zfill(width) for c in s.encode(encoding="utf-8")]
    )
    bitseq = [np.uint8(c) for c in bitstr]
    return bitseq


def bitseq2str(msgbits):
    binstr = "".join([bin(b & 1).strip("0b").zfill(1) for b in msgbits])
    mystr = np.zeros(int(len(msgbits) / 8)).astype(int)
    for i in range(0, len(mystr)):
        mystr[i] = int("0b" + binstr[(8 * i) : (8 * (i + 1))], 2)

    return bytes(mystr.astype(np.int8)).decode()


if __name__ == "__main__":
    test_lsb()
