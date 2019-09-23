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
    void add_element(int sz);
    void del_element(int num);
    MemoryElement* fit(int sz);
    MemoryElement* find_prev(MemoryElement *current);
    void print_list();
};