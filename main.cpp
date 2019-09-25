#include <iostream>
#include <stdlib.h>
#include "memorylist.h"

using namespace std;

int main(int argc, char *argv[])
{
    int memory_size;
    int algorithm_choice;
    if(argc < 3)
    {
        cout << "You must pass the follow arguments:" << endl;
        cout << " - memory size; \n - fit algorithm, (1) for first fit, (2) for best fit and (3) for worst fit." << endl;
        return 0;
    }else{
        memory_size = atoi(argv[1]);
        algorithm_choice = atoi(argv[2]);
    }

    MemoryList ml(memory_size, algorithm_choice);



    //testing add element (schedule)
    cout << "Memory allocated percentage: " << ml.memory_allocated_percentage() << "%" << endl;
    ml.add_element(10);
    ml.add_element(15);
    ml.add_element(10);
    ml.add_element(5);
    cout << "Memory allocated percentage: " << ml.memory_allocated_percentage() << "%" << endl;
    ml.print_list();
    //testing del element
    ml.del_element(2);
    ml.print_list();
    ml.del_element(10);
    ml.print_list();
    ml.add_element(5);
    ml.print_list();
    cout << "Memory allocated percentage: " << ml.memory_allocated_percentage() << "%" << endl;

    return 0;
}