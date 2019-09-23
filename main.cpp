#include <iostream>
#include "memorylist.h"

using namespace std;

int main()
{

    MemoryList ml(40, 2);

    //testing add element (schedule)
    ml.add_element(10);
    ml.add_element(15);
    ml.add_element(10);
    ml.add_element(5);
    ml.print_list();
    //testing del element
    ml.del_element(2);
    ml.print_list();
    ml.del_element(4);
    ml.print_list();
    ml.add_element(5);
    ml.print_list();

    return 0;
}