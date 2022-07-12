#ifndef __TICK_H_
#define __TICK_H_

void tick(void);

void append2HookList(void (*func)(void));
unsigned int get_tick_times();

#endif