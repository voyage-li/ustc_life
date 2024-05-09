// cryptoDemo.cpp : Defines the entry point for the console application.
// Windows: cl cryptoDemo.cpp
// Linux: gcc -o cryptoDemo cryptoDemo.cpp -lcrypto

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "openssl\aes.h"

#pragma comment(lib, "libeay32.lib")

void enc(char file[], char passwd[], int pwdLen)
{
    FILE *fp = fopen(file, "rb");
    FILE *fp2 = fopen("out.txt", "wb");
    if (!fp || !fp2)
    {
        printf("FILE COULD NOT OPEN\n");
        return;
    }
    fseek(fp, 0, 2);
    int filelen = ftell(fp);
    fwrite((void *)&filelen, sizeof(int), 1, fp2);
    fseek(fp, 0, 0);
    printf("%d\n", filelen);
    int i, j, len, nLoop, nRes;
    unsigned char buf[16];
    unsigned char buf2[16];
    unsigned char aes_keybuf[32];
    AES_KEY aeskey;

    // 准备32字节(256位)的AES密码字节
    memset(aes_keybuf, 0x90, 32);
    if (pwdLen < 32)
        len = pwdLen;
    else
        len = 32;
    for (i = 0; i < len; i++)
        aes_keybuf[i] = passwd[i];

    // 输入字节串分组成16字节的块
    nLoop = filelen / 16;
    nRes = filelen % 16;
    // 加密输入的字节串

    AES_set_encrypt_key(aes_keybuf, 256, &aeskey);
    for (i = 0; i < nLoop; i++)
    {
        memset(buf, 0, 16);
        fread(buf, sizeof(char), 16, fp);
        AES_encrypt(buf, buf2, &aeskey);
        fwrite(buf2, sizeof(char), 16, fp2);
    }
    if (nRes > 0)
    {
        memset(buf, 0, 16);
        fread(buf, sizeof(unsigned char), 16, fp);
        AES_encrypt(buf, buf2, &aeskey);
        fwrite(buf2, sizeof(unsigned char), 16, fp2);
    }
    fclose(fp);
    fclose(fp2);
}

void dec(char file[], char passwd[], int pwdLen)
{
    FILE *fp = fopen(file, "rb");
    FILE *fp2 = fopen("ans.txt", "wb");
    if (!fp || !fp2)
    {
        printf("FILE COULD NOT OPEN\n");
        return;
    }

    int filelen;
    fread((void *)&filelen, sizeof(int), 1, fp);
    printf("%d\n", filelen);

    int i, j, len, nLoop, nRes;
    unsigned char buf[16];
    unsigned char buf2[16];
    unsigned char aes_keybuf[32];
    AES_KEY aeskey;

    // 准备32字节(256位)的AES密码字节
    memset(aes_keybuf, 0x90, 32);
    if (pwdLen < 32)
        len = pwdLen;
    else
        len = 32;
    for (i = 0; i < len; i++)
        aes_keybuf[i] = passwd[i];
    // 输入字节串分组成16字节的块
    nLoop = filelen / 16;
    nRes = filelen % 16;

    // 密文串的解密
    AES_set_decrypt_key(aes_keybuf, 256, &aeskey);
    for (i = 0; i < nLoop; i++)
    {
        memset(buf, 0, 16);
        fread(buf, sizeof(unsigned char), 16, fp);
        AES_decrypt(buf, buf2, &aeskey);
        fwrite(buf2, sizeof(unsigned char), 16, fp2);
    }
    if (nRes > 0)
    {
        memset(buf, 0, 16);
        fread(buf, sizeof(unsigned char), 16, fp);
        AES_decrypt(buf, buf2, &aeskey);
        fwrite(buf2, sizeof(unsigned char), nRes, fp2);
    }

    fclose(fp);
    fclose(fp2);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("error");
        return 0;
    }

    if (strcmp(argv[1], "enc") == 0)
    {
        char *passwd = argv[3];
        enc(argv[2], passwd, strlen(passwd));
    }
    else if (strcmp(argv[1], "dec") == 0)
    {
        char *passwd = argv[3];
        dec(argv[2], passwd, strlen(passwd));
    }

    return 0;
}
