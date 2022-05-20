#include "../../include/mem.h"
#include "../../include/myPrintk.h"
unsigned long pMemStart; //可用的内存的起始地址
unsigned long pMemSize;  //可用的大小

void memTest(unsigned long start, unsigned long grainSize)
{
    /*本函数需要实现！！！*/
    /*功能：检测算法
        这一个函数对应实验讲解ppt中的第一大功能-内存检测。
        本函数的功能是检测从某一个地址开始的内存是否可用，具体算法就可以用ppt上说的写了读看是否一致。
    注意点两个：
    1、开始的地址要大于1M，需要做一个if判断。
    2、grainsize不能太小，也要做一个if判断
    */
    if (start < 0x100000)
        start = 0x100000;
    if (grainSize < 2)
        grainSize = 2;

    pMemSize = 0;
    pMemStart = start;

    unsigned long addr = start;
    unsigned short *addr_head, *addr_tail;
    unsigned short temp_data;
    unsigned short test1 = 0x55AA;
    unsigned short test2 = 0xAA55;

    while (1)
    {
        addr_head = (unsigned short *)addr;
        addr_tail = (unsigned short *)(addr + grainSize - 2);

        temp_data = *addr_head;
        *addr_head = test1;
        if (*addr_head != test1)
        {
            *addr_head = temp_data;
            break;
        }
        *addr_head = test2;
        if (*addr_head != test2)
        {
            *addr_head = temp_data;
            break;
        }
        *addr_head = temp_data;

        temp_data = *addr_tail;
        *addr_tail = test1;
        if (*addr_tail != test1)
        {
            *addr_tail = temp_data;
            break;
        }
        *addr_tail = test2;
        if (*addr_tail != test2)
        {
            *addr_tail = temp_data;
            break;
        }
        *addr_tail = temp_data;

        pMemSize += grainSize;
        addr += grainSize;
    }

    myPrintk(0x7, "MemStart: %x  \n", pMemStart);
    myPrintk(0x7, "MemSize:  %x  \n", pMemSize);
}

extern unsigned long _end;
void pMemInit(void)
{
    unsigned long _end_addr = (unsigned long)&_end;
    memTest(0x100000, 0x1000);
    myPrintk(0x7, "_end:  %x  \n", _end_addr);
    if (pMemStart <= _end_addr)
    {
        pMemSize -= _end_addr - pMemStart;
        pMemStart = _end_addr;
    }

    pMemHandler_k = dPartitionInit(pMemStart, pMemSize / 2);
    pMemHandler = dPartitionInit(pMemStart + pMemSize / 2, pMemSize - pMemSize / 2);
}
