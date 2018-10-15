#include <iostream>

class FixedSizeStack
{
    public:

    FixedSizeStack(int stack_size);

    void push(int item, int stacknum);
    int pop(int stacknum);
    int peek(int stacknum);
    bool isEmpty(int stacknum);
    bool isFull(int stacknum);
    void printSize();
    
    private:

    int stackNum = 3;
    int stackCapacity;
    int *values;
    int *sizes;

};