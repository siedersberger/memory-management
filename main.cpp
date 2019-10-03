#include <iostream>
#include <stdlib.h>
#include "memorylist.h"

using namespace std;

int main(int argc, char *argv[])
{
        
    if(argc < 2)
    {
        cout << "\n\n ERROR - Memory size argument missed. \n\n";
        return 0;
    }
    
    int memory_size = atoi(argv[1]);
    MemoryList ml_ff(memory_size, 1);
    MemoryList ml_bf(memory_size, 2);
    MemoryList ml_wf(memory_size, 3);

    for(int i = 0; i<1000; i++)
    {
        ml_ff.add_element(rand() % 50 + 10);
        ml_bf.add_element(rand() % 50 + 10);
        ml_wf.add_element(rand() % 50 + 10);

        ml_ff.del_element(rand() % ml_ff.getLen());
        ml_bf.del_element(rand() % ml_bf.getLen());
        ml_wf.del_element(rand() % ml_ff.getLen());
    }

    //testing add element (schedule)
    cout << "FISRT FIT memory allocated percentage: " << ml_ff.memory_allocated_percentage() << "%" << endl;
    cout << "BEST FIT memory allocated percentage: " << ml_bf.memory_allocated_percentage() << "%" << endl;
    cout << "WORST FIT memory allocated percentage: " << ml_wf.memory_allocated_percentage() << "%" << endl;

    return 0;
}