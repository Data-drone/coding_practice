#include<iostream>
#include<string>

class node {
    public:

    node* next;
    std::string data;
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

    void addValue(std::string dataitem) {

        node *temp = new node;
        temp->data = dataitem;

        if (head == NULL) {
            head=temp;
            tail=temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void printItems() {

        node *temp = new node;
        temp = head;

        while(temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }

        std::cout << std::endl;
    }

    void isPalindrome(){

        std::string forward = "";
        std::string backward = "";

        node *temp = new node;
        temp = head;

        while (temp) {
            forward = forward + temp->data;
            backward = temp->data + backward;
            temp = temp->next;
        }

        bool result = (forward==backward);
        std::cout << "is palindrome? " << result << std::endl;
    }
};

int main() {

    llist *test_1 = new llist();
    test_1->addValue("c");
    test_1->addValue("a");
    test_1->addValue("a");
    test_1->addValue("c");
    test_1->printItems();
    test_1->isPalindrome();

    llist *test_2 = new llist();
    test_2->addValue("c");
    test_2->addValue("a");
    test_2->addValue("b");
    test_2->addValue("c");
    test_2->addValue("a");
    test_2->printItems();
    test_2->isPalindrome();

}