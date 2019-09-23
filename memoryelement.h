#include <iostream>

using namespace std;

class MemoryElement
{
private:
    char status; // P for process, L for nothing
    int pos;
    int sz;
    MemoryElement *next_p;
public:
    MemoryElement(char id, int position, int size){
        status = id;
        pos = position;
        sz = size;
        next_p = NULL;
    }
    char getStatus() {return status;}
    int getPos() {return pos;}
    int getSz() {return sz;}
    MemoryElement* getNext() {return next_p;}
    void setStatus(char s) {status = s;}
    void setPos(int new_position) {pos = new_position;}
    void setSz(int new_sz) {sz = new_sz;}
    void setNext(MemoryElement *next) {next_p = next;}
};