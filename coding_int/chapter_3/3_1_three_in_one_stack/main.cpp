#include "FixedSizeStack.h"
#include <cassert>

int main() {

    int size = 3;
    FixedSizeStack *testing = new FixedSizeStack(size);

    for (int i=0; i < 3; i++) {
        assert(testing->isEmpty(i) == true);
    }
    
    for (int i=0; i < 3; i++) {
        std::cout << "iteration: " << i << std::endl;
        std::cout << "---pre start---" << std::endl;
        testing->printSize();
        testing->push(3, i);
        testing->push(2, i);
        testing->printSize();
        testing->push(10, i);
        std::cout << "---post load---" << std::endl;
        testing->printSize();
    }

    testing->printSize();
    /*
    for (int i=0; i < 3; i++) {
        assert(testing->isEmpty(i) == false);
        assert(testing->isFull(i) == true);
    }
    
    for (int i=0; i < 3; i++) {
        assert(testing->peek(i) == 4);
    }

    assert(testing->pop(1) == 4);
    assert(testing->pop(1) == 2);
    */
}