#include "stack_min.h"

MinStack::MinStack() {
    
    node* head = NULL;
    node* tail = NULL;
    node* min_node = NULL;

}

void MinStack::push( int item) 
{
    node *temp = new node;
    temp->data = item;
    temp->next = NULL;
    temp->previous = NULL;

    if (head == NULL) {
        head = temp;
        tail = temp;
        min_node = temp;
    } else {
        temp->previous = tail;
        tail->next = temp;
        tail = temp;

        if (item < min_node->data) {
            // need to be careful here
            // if we change the pointer for temp next will
            // cause issues
            tail->min = tail;
            min_node = temp;
        } else {
            tail->min = min_node;
        }

    }
}

int MinStack::pop() 
// return the tail when there is stuff in the stack
// revert to previous min and move the tail back one
{
    if (isEmpty()) {
        throw "empty stack";
    } else {
        node *temp = new node;
        temp = tail;
        if (tail->previous == NULL) {
            tail = NULL;
            head = NULL;
            min_node = NULL;
        } else {
            tail = tail->previous;
            tail->next = NULL;
            min_node = tail->min;
        }

        return temp->data;
    }
}

int MinStack::min() 
{
    if (isEmpty()) {
        throw "No min value";
    } else {
        return min_node->data;
    }
}

int MinStack::peek() 
{
    if (isEmpty() ) {
        throw "No tail value";
    } else {
        return tail->data;
    }

}

bool MinStack::isEmpty() {
    if (head == NULL) {
        return true;
    }
    return false;
}

void MinStack::printStack()
{
    std::cout << " --- head: " << head->data;
    std::cout << " --- tail: " << tail->data;
    std::cout << " --- min_value: " << min_node->data;
}