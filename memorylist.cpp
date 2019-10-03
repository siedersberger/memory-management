#include <iostream>
#include "memorylist.h"

using namespace std;

MemoryList::MemoryList(int sz, int scheduler_choice)
{
    fit_algorithm = FitAlgorithm::algorithm_factory(scheduler_choice);
    MemoryElement *new_p = new MemoryElement('L', 0, sz);
    head = new_p;
    tail = new_p;
    sz_max = sz;
    len = 0;
}

MemoryList::~MemoryList()
{
    delete head;
    delete fit_algorithm;
}

int MemoryList::add_element(int sz)
{
    MemoryElement *element = fit(sz);

    if (!element)
    {
        return -1;
    }
    
    MemoryElement *element_prev = find_prev(element);
    MemoryElement *new_p = new MemoryElement('P', element->getPos(), sz);
    
    if(!element_prev)
    {
        head = new_p;
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
    len++;
    return 0; 
}

MemoryElement* MemoryList::fit(int sz)
{
    return fit_algorithm->memory_fit(head, sz);
}

int MemoryList::del_element(int num)
{
    if(num < 1)
        return -1;

    MemoryElement *e;
    MemoryElement *e_prev;
    MemoryElement *e_next;
    int i = 0;
    e = head;

    while(i<num)
    {
        if(!e)
            return -1;
        if(e->getStatus() == 'P')
            i++;
        if(i<num)
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
    return 0;
}

MemoryElement* MemoryList::find_prev(MemoryElement *current)
{
    MemoryElement *e = head;   
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
    MemoryElement *c = head;
    while (c)
    {
        cout << c->getStatus() << ", " << c->getPos() << ", " << c->getSz() << endl;
        c = c->getNext();
    }
}

double MemoryList::memory_allocated_percentage()
{
    MemoryElement *c = head;
    double sum = 0;

    while (c)
    {
        if(c->getStatus() == 'P')
            sum += c->getSz();
        c = c->getNext();
    }
    return (sum/sz_max)*100;
}

string MemoryList::mem_status()
{
    MemoryElement *c = head;
    string status;
    while (c)
    {
        if(c->getStatus() == 'P')
            status += '1';
        else
            status += '0';
        
        c = c->getNext();
    }
    return status;
}
    
int MemoryList::getLen()
{
    return len;
}