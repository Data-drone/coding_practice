// need to handle teens properly

#include<iostream>
#include<vector>
#include<string>
#include<sstream>

class node {
    public:

    node* next;
    int data_value;
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

    node* getHead(){
        return head;
    }

    void addValue(int adder) {
        
        node *temp = new node;
        temp->data_value = adder;
        temp->next=NULL;

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
            std::cout << temp->data_value << "\t";
            temp = temp->next;
        }
        std::cout << std::endl << "---end---" << std::endl;
    }
};

void sum_vecs(llist *one, llist *two, llist *holder) {

    node *temp_1 = new node;
    node *temp_2 = new node;

    temp_1 = one->getHead();
    temp_2 = two->getHead();

    std::string holder1 = "";
    std::string holder2 = "";
    std::string digit = "";

    while(temp_1) {

        digit = std::to_string(temp_1->data_value);
        holder1 = digit + holder1;
        temp_1 = temp_1->next;
    }

    while(temp_2) {
        digit = std::to_string(temp_2->data_value);
        holder2 = digit + holder2;
        temp_2 = temp_2->next;
    }
        
    int result = std::stoi(holder1) + std::stoi(holder2);
    
    std::string result_str = std::to_string(result);
    std::string reverse_str;
    
    //std::cout << "before reorder: " << result_str << std::endl;

    for (auto item : result_str) {
        reverse_str = item + reverse_str;
    }
    
    for (char& c : reverse_str) {
        int out = c - '0';
        holder->addValue(out);
    }

    //std::cout << reverse_str << std::endl;
}

int main() {

    llist *vector_1 = new llist;
    llist *vector_2 = new llist;

    vector_1->addValue(4);
    vector_1->addValue(5);
    vector_1->addValue(6);

    vector_2->addValue(3);
    vector_2->addValue(2);
    vector_2->addValue(7);

    llist *answer = new llist;
    sum_vecs(vector_1, vector_2, answer);
    answer->printList();



}