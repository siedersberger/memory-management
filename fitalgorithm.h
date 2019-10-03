#include "memoryelement.h"

class FitAlgorithm
{
    public:
        static FitAlgorithm *algorithm_factory(int choice);
        virtual MemoryElement *memory_fit(MemoryElement * head, int size) = 0;
};

class FirstFit: public FitAlgorithm
{
    public:
        MemoryElement *memory_fit(MemoryElement * head, int size);
};

class BestFit: public FitAlgorithm
{
    public:
        MemoryElement *memory_fit(MemoryElement * head, int size);
};

class WorstFit: public FitAlgorithm
{
    public:
        MemoryElement *memory_fit(MemoryElement * head, int size);
};