#include "../../include/mem.h"

unsigned long malloc(unsigned long size)
{
    //本函数需要实现！！！

    //调用实现的dPartition或者是ePartition的alloc
    return dPartitionAlloc(pMemHandler, size);
}

unsigned long free(unsigned long start)
{
    //本函数需要实现！！！

    //调用实现的dPartition或者是ePartition的free
    return dPartitionFree(pMemHandler, start);
}
unsigned long kmalloc(unsigned long size)
{
    return dPartitionAlloc(pMemHandler_k, size);
}

unsigned long kfree(unsigned long start)
{
    return dPartitionFree(pMemHandler_k, start);
}