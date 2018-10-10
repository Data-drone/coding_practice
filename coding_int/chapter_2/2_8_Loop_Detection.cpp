#include<iostream>
#include<set>

class node {
    public:

    node *next;
    int datavalue;
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

    void addValue(int value){

        node *temp = new node;
        temp->datavalue = value;
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
            std::cout << temp->datavalue << "\t";
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

    node *check_loop() {

        node *temp = new node;
        temp=head;

        std::set<node*> setOfNodes;

        while (temp) {
            if(setOfNodes.insert(temp).second == false) {
                std::cout << "loop found" << std::endl;
                return temp;
            } else {
                setOfNodes.insert(temp);
            } 
            temp=temp->next;
        }

        std::cout << "all clear" << std::endl;
        return temp;
    }
};

int main() {

    llist *main1 = new llist;

    main1->addValue(1);
    main1->addValue(3);
    main1->addValue(4);

    node *dupes = new node;
    dupes = main1->check_loop();

    node *n1 = new node;
    n1->datavalue = 8;

    node *n2 = new node;
    n2->datavalue = 12;

    node *n3 = new node;
    n3->datavalue = 41;

    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    main1->addNode(n1);
    dupes = main1->check_loop();



}