#ifndef __MALLOC_H__
#define __MALLOC_H__

unsigned long malloc(unsigned long size);
unsigned long free(unsigned long start);
unsigned long kmalloc(unsigned long size);
unsigned long kfree(unsigned long start);

#endif