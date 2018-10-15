#include "FixedSizeStack.h"

FixedSizeStack::FixedSizeStack(int stack_size) {

    this->stackCapacity = stack_size;
    values = new int[stackCapacity * stackNum];
    sizes = new int[stackNum];
    //sizes = {0};
}

void FixedSizeStack::push(int item, int stacknum) {
    
    if (isFull(stacknum)) {
        //std::cout << std::to_string(stackCapacity) << std::endl;
        //std::cout << std::to_string(sizes[stacknum]) << std::endl;
        std::cout << "stack is full" << std::endl;
    } else {
        if (sizes[stacknum] < stackCapacity) {
            sizes[stacknum]++;
        } else {
            std::cout << "what is happening!" << std::endl;
        }
        
        values[stackNum*stackCapacity+sizes[stacknum]] = item;
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
        return values[stackNum*stackCapacity+sizes[stacknum]];
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

