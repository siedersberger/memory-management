#include "scheduler.h"

Scheduler* Scheduler::make_scheduler(int choice)
{
    if(choice == 1)
        return new FirstFit();
    else if (choice == 2)
        return new BestFit();

    return NULL;
}


MemoryElement* FirstFit::memory_fit(MemoryElement *head, int size)
{
    while (head)
    {
        if(head->getStatus() == 'L' && head->getSz() >= size)
        {
            return head;
        }
        else
        {
            head = head->getNext();
        } 
    }
    return NULL;
}

MemoryElement* BestFit::memory_fit(MemoryElement *head, int size)
{
    int small_diff = 999;
    int diff;
    MemoryElement *current = head;
    MemoryElement *bf_element = NULL;
    while (current)
    {
        if(current->getStatus() == 'L' && current->getSz() >= size)
        {
            diff = current->getSz() - size;
            if(diff < small_diff)
            {
                bf_element = current;
                small_diff = diff;
            }
        }
        current = current->getNext();
    }
    return bf_element;
}