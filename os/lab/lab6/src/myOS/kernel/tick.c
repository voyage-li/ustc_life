extern void oneTickUpdateWallClock(void); // TODO: to be generalized

//#ifndef __TICK_HOOK__
//#define __TICK_HOOK__
// void (*tick_hook)(void) = 0; //{};
//#endif
void (*hook_list[30])(void);

int hook_func_num = 0;
void append2HookList(void (*func)(void))
{
    hook_list[hook_func_num++] = func;
}

int tick_number = 0;
void tick(void)
{
    int temp_col, temp_row;
    tick_number++;

    oneTickUpdateWallClock();

    for (int i = 0; i < hook_func_num; i++)
        hook_list[i]();
}

unsigned int get_tick_times()
{
    return tick_number;
}
