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
    int del_element(int num);
    string mem_status();
    void add_element(int sz);
    void print_list();
};