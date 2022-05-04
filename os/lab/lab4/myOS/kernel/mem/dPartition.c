#include "../../include/myPrintk.h"

// dPartition 是整个动态分区内存的数据结构
typedef struct dPartition
{
    unsigned long size;
    unsigned long firstFreeStart;
} dPartition; //共占8个字节

#define dPartition_size ((unsigned long)0x8)

void showdPartition(struct dPartition *dp)
{
    myPrintk(0x5, "dPartition(start=0x%x, size=0x%x, firstFreeStart=0x%x)\n", dp, dp->size, dp->firstFreeStart);
}

// EMB每一个block的数据结构，userdata可以暂时不用管。
typedef struct EMB
{
    unsigned long size;
    union
    {
        unsigned long nextStart; // if free: pointer to next block
        unsigned long userData;  // if allocated, blongs to user
    };
} EMB; //共占8个字节

#define EMB_size ((unsigned long)0x8)

void showEMB(struct EMB *emb)
{
    myPrintk(0x3, "EMB(start=0x%x, size=0x%x, nextStart=0x%x)\n", emb, emb->size, emb->nextStart);
}

unsigned long dPartitionInit(unsigned long start, unsigned long totalSize)
{
    //本函数需要实现！！！
    /*功能：初始化内存。
    1.在地址start处，首先是要有dPartition结构体表示整个数据结构(也即句柄)。
    2.然后，一整块的EMB被分配（以后使用内存会逐渐拆分），在内存中紧紧跟在dP后面，然后dP的firstFreeStart指向EMB。
    3.返回start首地址(也即句柄)。
    注意有两个地方的大小问题：
        第一个是由于内存肯定要有一个EMB和一个dPartition，totalSize肯定要比这两个加起来大。
        第二个注意EMB的size属性不是totalsize，因为dPartition和EMB自身都需要要占空间。
    */
    if (totalSize <= sizeof(dPartition) + sizeof(EMB))
        return 0;
    dPartition *handler = (dPartition *)start;
    handler->size = totalSize;
    handler->firstFreeStart = start + sizeof(dPartition);

    EMB *block = (EMB *)handler->firstFreeStart;
    block->size = totalSize - sizeof(dPartition);
    block->nextStart = 0;

    return start;
}

void dPartitionWalkByAddr(unsigned long dp)
{
    //本函数需要实现！！！
    /*功能：本函数遍历输出EMB 方便调试
    1.先打印dP的信息，可调用上面的showdPartition。
    2.然后按地址的大小遍历EMB，对于每一个EMB，可以调用上面的showEMB输出其信息
    */
    dPartition *handler = (dPartition *)dp;
    showdPartition(handler);

    unsigned long now_addr = handler->firstFreeStart;
    EMB *temp;
    while (now_addr)
    {
        temp = (EMB *)now_addr;
        showEMB(temp);
        now_addr = temp->nextStart;
    }
}

unsigned long align8(unsigned long size)
{
    unsigned long R = ((int)size) % 8;
    if (R == 0)
        return size;
    else
        return size + 8 - R;
}
//=================firstfit, order: address, low-->high=====================
/**
 * return value: addr (without overhead, can directly used by user)
 **/

unsigned long dPartitionAllocFirstFit(unsigned long dp, unsigned long size)
{
    //本函数需要实现！！！
    /*功能：分配一个空间
    1.使用firstfit的算法分配空间，当然也可以使用其他fit，不限制。
    2.成功分配返回首地址，不成功返回0
    3.从空闲内存块组成的链表中拿出一块供我们来分配空间(如果提供给分配空间的内存块空间大于size，我们还将把剩余部分放回链表中)，并维护相应的空闲链表以及句柄
    注意的地方：
        1.EMB类型的数据的存在本身就占用了一定的空间。
    */
    dPartition *handler = (dPartition *)dp;
    if (handler->firstFreeStart == 0)
        return 0;
    size = align8(size);
    unsigned long now_addr = handler->firstFreeStart;
    unsigned long pre_addr = 0;
    EMB *block_now, *block_pre;
    while (now_addr)
    {
        block_now = (EMB *)now_addr;
        block_pre = (EMB *)pre_addr;
        if (block_now->size >= size + sizeof(unsigned long))
        {
            //直接整个块分配
            if (block_now->size < sizeof(EMB) + size + sizeof(unsigned long))
            {
                if (pre_addr == 0)
                    handler->firstFreeStart = block_now->nextStart;
                else
                    block_pre->nextStart = block_now->nextStart;
                return now_addr + sizeof(unsigned long);
            }
            else
            //切分该空闲块
            {
                unsigned long new_block_addr = now_addr + sizeof(unsigned long) + size;
                EMB *block_new = (EMB *)new_block_addr;
                block_new->size = block_now->size - size - sizeof(unsigned long);
                block_new->nextStart = block_now->nextStart;
                block_now->size -= block_new->size;
                if (pre_addr == 0)
                    handler->firstFreeStart = new_block_addr;
                else
                    block_pre->nextStart = new_block_addr;
                return now_addr + sizeof(unsigned long);
            }
        }
        pre_addr = now_addr;
        now_addr = block_now->nextStart;
    }
    return 0;
}

/*
 *r
 */
unsigned long dPartitionFreeFirstFit(unsigned long dp, unsigned long start)
{
    //本函数需要实现！！！
    /*功能：释放一个空间
    1.按照对应的fit的算法释放空间
    2.注意检查要释放的start~end这个范围是否在dp有效分配范围内
        返回1 没问题
        返回0 error
    3.需要考虑两个空闲且相邻的内存块的合并
    */
    dPartition *handler = (dPartition *)dp;
    start -= sizeof(unsigned long);
    // myPrintk(0x7, "\nstart: %x\n", start);
    if (start < dp + sizeof(dPartition) || start > dp + handler->size)
        return 0;

    unsigned long now_addr = handler->firstFreeStart;
    unsigned long pre_addr = 0;
    unsigned long next_addr = 0;
    EMB *block;

    while (now_addr)
    {
        block = (EMB *)now_addr;
        if (now_addr < start)
            pre_addr = now_addr;
        else
        {
            next_addr = now_addr;
            break;
        }
        now_addr = block->nextStart;
    }

    // myPrintk(0x7, "now_addr: %x\npre_addr: %x\n", now_addr, pre_addr);

    block = (EMB *)start;
    if (next_addr != 0)
    {
        if (start + block->size == next_addr)
        {
            EMB *next_block = (EMB *)next_addr;
            block->size += next_block->size;
            block->nextStart = next_block->nextStart;
        }
        else
            block->nextStart = next_addr;
    }
    else
        block->nextStart = 0;

    if (pre_addr != 0)
    {
        EMB *pre_block = (EMB *)pre_addr;
        if (start == pre_addr + pre_block->size)
        {
            pre_block->size += block->size;
            pre_block->nextStart = block->nextStart;
        }
        else
            pre_block->nextStart = start;
    }
    else
        handler->firstFreeStart = start;
    return 1;
}

// wrap: we select firstFit, you can select another one
// user need not know this
unsigned long dPartitionAlloc(unsigned long dp, unsigned long size)
{
    return dPartitionAllocFirstFit(dp, size);
}

unsigned long dPartitionFree(unsigned long dp, unsigned long start)
{
    return dPartitionFreeFirstFit(dp, start);
}
