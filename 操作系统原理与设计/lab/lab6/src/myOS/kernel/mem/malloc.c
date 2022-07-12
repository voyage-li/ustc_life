#include "../../include/mem.h"

unsigned long malloc(unsigned long size)
{
    return dPartitionAlloc(uMemHandler, size);
}

unsigned long free(unsigned long start)
{
    return dPartitionFree(uMemHandler, start);
}
