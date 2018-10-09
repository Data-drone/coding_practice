#include<iostream>
#include<vector>
#include<string>

class node{
    public:

    node* next;
    std::string data;
};

class llist{

    private:

    node* head;
    node* tail;

    public:

    llist() {
        head = NULL;
        tail = NULL;
    }

    void addValue(std::string value){

        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }

    }

    void printValues() {

        node *temp = new node;
        temp = head;

        while (temp) {
            std::cout << temp->data << "\t";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    node* extractNode_by_value(std::string datafind) {

        node *temp = head;

        while(temp) {
            if (temp->data == datafind) {
                return temp;
            } else {
                temp = temp->next;
            }
        }
    }

};

void remove_middle_node(node *temp) {

    if (temp->next == NULL) {
        std::cout << "this is not a middle node" << std::endl;
    }
    
    node *nextnode = temp->next;

    temp->data = nextnode->data;
    temp->next = nextnode->next;

}

int main(){

    llist *testing = new llist;
    testing->addValue("test1");
    testing->addValue("test2");
    testing->addValue("test3");
    testing->addValue("test4");
    testing->addValue("test5");
    testing->addValue("test6");

    testing->printValues();

    node *middle_node;

    middle_node = testing->extractNode_by_value("test3");

    // remove the middle node
    std::cout << "removing: " << middle_node->data << std::endl;
    remove_middle_node(middle_node);

    testing->printValues();
    
    return 1;
}
