#include<iostream>

class node 
{
    public:

    node* next;
    int data;
    node* min;
    node* previous;
};

class MinStack
{
    public:

    MinStack();

    void push(int item);
    int pop();
    int peek();
    int min();
    bool isEmpty();
    void printStack();

    node* head;
    node* tail;
    node* min_node;

};
    