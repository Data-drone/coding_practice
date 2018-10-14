#include "FixedSizeStack.h"

FixedSizeStack::FixedSizeStack(int stack_size) {

    int stackCapacity = stack_size;
    int values[stackCapacity * stackNum];
    int sizes[stackNum];
}

void FixedSizeStack::push(int item, int stacknum) {
    if (isFull(stacknum)) {
        std::cout << "stack is full" << std::endl;
    } else {
        sizes[stacknum]++;
        values[stackNum*stackCapacity+sizes[stacknum]] = item;
    }
}

int FixedSizeStack::pop(int stacknum) {
    if(isEmpty(stacknum)) {
        std::cout << "stack is empty" << std::endl;
        return NULL;
    } else {
        int ret_val = values[stackNum*stackCapacity+sizes[stacknum]];
        values[stackNum*stackCapacity+sizes[stacknum]] = NULL;
        sizes[stacknum]--;
        return  ret_val;
    }

}

int FixedSizeStack::peek(int stacknum) {
    if(isEmpty(stacknum)) {
        std::cout << "stack is empty" << std::endl;
        return NULL;
    } else {
        return values[stackNum*stackCapacity+sizes[stacknum]];
    }
}

bool FixedSizeStack::isEmpty(int stackNum) {
    return sizes[stackNum] == 0;
}

bool FixedSizeStack::isFull(int stackNum) {
    return sizes[stackNum] == stackCapacity;
}