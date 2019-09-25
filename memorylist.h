#include "scheduler.h"

class MemoryList
{
private:
    MemoryElement *first;
    MemoryElement *last;
    Scheduler *scheduler;
    int sz_max;
public:
    MemoryList(int sz, int scheduler_choice);
    ~MemoryList();
    MemoryElement* fit(int sz);
    MemoryElement* find_prev(MemoryElement *current);
    double memory_allocated_percentage();
    void add_element(int sz);
    int del_element(int num);
    void print_list();
};