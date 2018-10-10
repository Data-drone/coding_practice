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
        head=NULL;
        tail=NULL;
    }

    void addValue(int datavalue){

        node *temp = new node;
        temp->data = datavalue;
        temp->next = NULL;

        if (head==NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    node* getHead() {
        return head;
    }

    void addNode(node *nodetoadd) {

        if (head==NULL) {
            head = nodetoadd;
            tail = nodetoadd;
        } else {
            tail->next = nodetoadd;
            tail = nodetoadd;
        }

    }

    void printList() {

        node *temp = new node;
        temp = head;

        while(temp) {
            std::cout << temp->data << "\t";
            temp=temp->next;
        }
        std::cout << std::endl << "---end---" << std::endl;
    }

    int list_length() {

        int length  = 0;

        node *temp = new node;
        temp = head;
        while(temp) {
            ++length;
            temp = temp->next;
        }

        return length;
    }
};

node *detectIntersection(llist *l1, llist *l2) {

    node *lead_head=new node;
    node *second_head=new node;

    int length1 = l1->list_length();
    int length2 = l2->list_length();

    if (length1 >= length2) {
        lead_head = l1->getHead();
        second_head = l2->getHead();
        
    } else if (length2 > length1) {
        lead_head = l2->getHead();
        second_head = l1->getHead();
    } else {
        std::cout << "error: " << "length 1 is " << length1 << "length 2 is " \
        << length2 << std::endl;
    }

    unsigned int diff = abs(length1 - length2);

    while(diff>0) {
        lead_head=lead_head->next;
        diff--;
    }

    //std::cout << "lead head is now at " << lead_head->data << std::endl;
    //std::cout << "second head is now at " << second_head->data << std::endl;

    while(lead_head) {

        if (lead_head == second_head) {

            std::cout << "intersection at: " << lead_head->data << std::endl;
            return lead_head; 
        }

        lead_head=lead_head->next;
        second_head=second_head->next;
    }

    return NULL;

}

int main() {

    llist *main1 = new llist;
    llist *main2 = new llist;

    main1->addValue(1);
    main1->addValue(3);
    main1->addValue(4);

    main2->addValue(6);
    main2->addValue(8);
    main2->addValue(3);
    main2->addValue(7);

    node *merger = new node;
    merger->data = 4;

    main1->addNode(merger);
    main2->addNode(merger);

    main1->addValue(8);
    main1->addValue(10);
    main1->addValue(32);

    std::cout << "----list 1----" << std::endl; 
    main1->printList();
    std::cout << "----list 2----" << std::endl;
    main2->printList();

    detectIntersection(main1, main2);

}