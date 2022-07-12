#include "../../include/kmalloc.h"

unsigned long kmalloc(unsigned long size)
{
    return dPartitionAlloc(kMemHandler, size);
}

unsigned long kfree(unsigned long start)
{
    return dPartitionFree(kMemHandler, start);
}