#include<iostream>
#include<string>
#include<vector>

class node {

    public:

    node *next;
    std::string dataitem;

    void print_node(){
        std::cout << dataitem << std::endl;
    }
};

class linked_list {

    private:

    int found = 0;

    node *head;
    node *tail;
    
    public:

    linked_list() 
    {
        head = NULL;
        tail = NULL;
    }

    void add_data(std::string data_val) {

        node *temp = new node;
        temp->dataitem = data_val;
        temp->next = NULL;

        if (head == 0) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail=temp; 
        }
    }

    void print_list(){

        node *temp = new node;
        temp = head;
        while(temp != NULL) {
            std::cout << temp->dataitem << "\t";
            temp = temp->next;
        }
        std::cout << std::endl << "----stop----" << std::endl;
    }

    void kth_pointer(int n) {

        node *lead = new node;
        node *follow = new node;

        lead = head;
        follow = head;

        while(n >= 0) {
            lead = lead->next;
            n--;
        }

        while(lead) {
            lead = lead->next;
            follow = follow->next;
        }

        std::cout << follow->dataitem << std::endl;
    }

};

int main(){

    linked_list *testing = new linked_list;
    testing->add_data("test1");
    testing->add_data("test2");
    testing->add_data("test3");
    testing->add_data("test4");
    testing->add_data("test5");
    testing->add_data("test6");
    testing->add_data("test7");
    testing->add_data("test8");

    testing->print_list();
    
    for (int i = 1; i <= 7; i++) {
        testing->kth_pointer(i);
    }

}