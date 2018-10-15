#include "FixedSizeStack.h"

FixedSizeStack::FixedSizeStack(int stack_size) {

    this->stackCapacity = stack_size;
    values = new int[stackCapacity * stackNum]();
    sizes = new int[stackNum]();
    //sizes = {0};
}

void FixedSizeStack::push(int item, int stacknum) {
    
    if (isFull(stacknum)) {
        std::cout << "stack is full" << std::endl;
    } else {
        //std::cout << "adding to array" << std::endl;
        sizes[stacknum]++;
        // this is updating the size too for some reason?
        int index = stackNum*stackCapacity+sizes[stacknum]-1;
        values[index] = item;
    }

}

int FixedSizeStack::pop(int stacknum) {
    if(isEmpty(stacknum)) {
        throw "stack is empty";
    } else {
        int ret_val = values[stackNum*stackCapacity+sizes[stacknum]];
        //values[stackNum*stackCapacity+sizes[stacknum]] = NULL;
        sizes[stacknum]--;
        return  ret_val;
    }

}

int FixedSizeStack::peek(int stacknum) {
    if(isEmpty(stacknum)) {
        throw "stack is empty";
    } else {
        return values[stackNum*stackCapacity+sizes[stacknum]-1];
    }
}

bool FixedSizeStack::isEmpty(int stackNum) {
    return (sizes[stackNum] == 0);
}

bool FixedSizeStack::isFull(int stackNum) {
    //std::cout << sizes[stackNum] << " " << stackCapacity << std::endl;
    return (sizes[stackNum] == stackCapacity);
}

void FixedSizeStack::printSize() {
    for (int i = 0; i < 3; i++) {
        std::cout << "stack " << i << " is size " << sizes[i] << " || "; 
    }
    std::cout << std::endl;
}

