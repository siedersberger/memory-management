#include "fitalgorithm.h"

class MemoryList
{
private:
    MemoryElement *head;
    MemoryElement *tail;
    FitAlgorithm *fit_algorithm;
    int sz_max;
    int len;
public:
    MemoryList(int sz, int fit_choice);
    ~MemoryList();
    MemoryElement* fit(int sz);
    MemoryElement* find_prev(MemoryElement *current);
    double memory_allocated_percentage();
    int del_element(int num);
    string mem_status();
    int add_element(int sz);
    void print_list();
    int getLen();
};