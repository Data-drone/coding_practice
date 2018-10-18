#include<iostream>
#include "stack_min.h"
#include <cassert>

int main() {

    MinStack *testing = new MinStack();

    assert(testing->isEmpty() == true);
    
    testing->push(1);
    
    assert(testing->isEmpty() == false);
    assert(testing->peek() == 1);
    assert(testing->min() == 1);
    
    int result;
    // error here
    result = testing->pop();
    assert(testing->isEmpty() == true);
    
    testing->push(2);
    testing->push(3);
    testing->push(4);

    assert(testing->min() == 2);
    testing->push(1);
    std::cout << " -- " << testing->min() << " -- " << std::endl;
    
    assert(testing->min() == 1);
    
    result = testing->pop();
    
    assert(testing->min() == 2);
    
    return 1;
}


