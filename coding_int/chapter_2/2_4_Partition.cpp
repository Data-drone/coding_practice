#include<iostream>

class node {
    public:

    node* next;
    int data;
};

class llist {

    private:

    node* head;
    node* tail;

    public:

    llist() {
        head = NULL;
        tail = NULL;
    }

    void addVal(int newdata) {

        node *temp = new node;
        temp->data =  newdata;
        temp->next = NULL;
        
        if (head==NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void printList() {

        node *temp = new node;
        temp = head;

        while(temp) {
            std::cout << temp->data << "\t";
            temp = temp->next;
        }
        std::cout << std::endl << "---end---" << std::endl; 

    }

    void partition(const int pivot) {

        // left - less than pivot
        // right - equal to or greater than pivot

        llist *less = new llist;
        llist *more = new llist;

        node *temp = new node;
        temp = head;

        while(temp){
            
            if (temp->data < pivot) {
                less->addVal(temp->data);
            } else if (temp->data >= pivot) {
                more->addVal(temp->data);
            }

            temp = temp->next;
        }

        head = less->head;
        tail = less->tail;
        tail->next = more->head;
        tail = more->tail;
    }
};

int main() {

    llist *testing = new llist;
    testing->addVal(1);
    testing->addVal(5);
    testing->addVal(6);
    testing->addVal(9);
    testing->addVal(3);
    testing->addVal(7);

    testing->printList();

    testing->partition(6);
    testing->printList();

    testing->partition(3);
    testing->printList();

}