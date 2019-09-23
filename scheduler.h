#include "memoryelement.h"

class Scheduler
{
    public:
        static Scheduler *make_scheduler(int choice);
        virtual MemoryElement *memory_fit(MemoryElement * head, int size) = 0;
};

class FirstFit: public Scheduler
{
    public:
        MemoryElement *memory_fit(MemoryElement * head, int size);
};

class BestFit: public Scheduler
{
    public:
        MemoryElement *memory_fit(MemoryElement * head, int size);
};