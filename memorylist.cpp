#include <iostream>
#include "memorylist.h"

using namespace std;

MemoryList::MemoryList(int sz, int scheduler_choice)
{
    scheduler = Scheduler::make_scheduler(scheduler_choice);
    MemoryElement *new_p = new MemoryElement('L', 0, sz);
    first = new_p;
    last = new_p;
    sz_max = sz;
}

MemoryList::~MemoryList()
{
    delete first;
}

void MemoryList::add_element(int sz)
{
    MemoryElement *element = fit(sz);
    MemoryElement *element_prev = find_prev(element);

    if (!element)
    {
        cout << "Memory full." << endl;
    }
    else
    {
        MemoryElement *new_p = new MemoryElement('P', element->getPos(), sz);
        if(!element_prev)
        {
            first = new_p;
        }
        else
        {
            element_prev->setNext(new_p);
        }
        
        if(element->getSz() == sz)
        {
            new_p->setNext(element->getNext());
        }
        else
        {
            element->setSz(element->getSz()-sz);
            element->setPos(element->getPos()+sz);
            new_p->setNext(element);
        }            
    }    
}

MemoryElement* MemoryList::fit(int sz)
{
    return scheduler->memory_fit(first, sz);
}

void MemoryList::del_element(int num)
{
    MemoryElement *e;
    MemoryElement *e_prev;
    MemoryElement *e_next;

    e = first;
    for(int i = 1; i<num; i++)
    {
        e = e->getNext();
    }

    e_prev = find_prev(e);
    e_next = e->getNext();

    if (e_next && e_next->getStatus() == 'L')
    {
        e->setSz(e->getSz() + e_next->getSz());
        e->setNext(e_next->getNext());
        e->setStatus('L');
        delete e_next;
    } 
    
    if(e_prev && e_prev->getStatus() == 'L')
    {
        e_prev->setSz(e_prev->getSz() + e->getSz());
        e_prev->setNext(e->getNext());
        delete e;   
    }
    else
    {
        e->setStatus('L');
    }

}

MemoryElement* MemoryList::find_prev(MemoryElement *current)
{
    MemoryElement *e = first;   
    while(e->getNext())
    {
        if(e->getNext() == current)
        {
            return e;
        }
        e = e->getNext();
    }
    return NULL;
}

void MemoryList::print_list()
{
    cout << "Printing memory list..." << endl;
    MemoryElement *c = first;
    while (c)
    {
        cout << c->getStatus() << ", " << c->getPos() << ", " << c->getSz() << endl;
        c = c->getNext();
    }
}