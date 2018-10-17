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
    int peak();
    int min();
    bool isEmpty();

    node* head;
    node* tail;
    node* min_node;

};
    