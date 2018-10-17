#include "stack_min.h"

MinStack::MinStack() {
    
    node* head = NULL;
    node* tail = NULL;

}

void MinStack::push( int item) 
{
    node *temp = new node;
    temp->data = item;
    temp->next = NULL;
    temp->previous = NULL;

    if (head == NULL) {
        temp->min = temp;
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
            temp->min = temp;
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
    if (head == NULL) {
        return NULL;
    } else {
        node *temp = new node;
        temp = tail;


        

    }
}


