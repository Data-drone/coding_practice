#include<iostream>
#include<string>
#include<set>

class Node
{
    // basic node inside a linked list
    // data_value which is ?anything?
    // pointer to the next item
    public:
    
    Node* nextval;
    std::string dataitem;
};

class LinkedList
{
    private:
    
    Node* head;
    Node* tail;
    // methods - add
    // methods - delete
    
    public: 
    LinkedList() 
    {
        head = NULL;
        tail = NULL;
    }


    void addItem(std::string data_value){
        
        Node *temp=new Node;
        temp->dataitem = data_value;
        temp->nextval = NULL;

        if(head==0){
            head = temp;
            tail = temp;
            temp = NULL;
        } else {
            tail->nextval=temp;
            tail=temp;
        }
    }

    void printList(){
        Node *temp = new Node;
        temp=head;
        while(temp!=NULL){
            std::cout << temp->dataitem << "\t";
            temp = temp->nextval;
        }
        std::cout << std::endl << "----stop----" << std::endl;
    }

    void dedup() {
        std::set<std::string> distinctValues;

        Node *temp = new Node;
        Node *oneForward = new Node;
        temp=head;
        oneForward = temp->nextval;

        distinctValues.insert(temp->dataitem);

        while(oneForward!=NULL){
            if (distinctValues.insert(oneForward->dataitem).second == false) {
                // duplicate scenario

                // scenario 1 we still have values after one forward
                if (oneForward->nextval != NULL){
                    temp->nextval = oneForward->nextval;
                    oneForward = oneForward->nextval;

                // scenario 2 we don't have any more nodes after one forward
                } else if(oneForward->nextval == NULL) {
                    temp->nextval = NULL;
                    oneForward = NULL;
                }
                
            } else {
                distinctValues.insert(oneForward->dataitem);
                temp = temp->nextval;
                oneForward = oneForward->nextval;
            }
        }
    }
};

int main(){

    LinkedList *testing_list = new LinkedList;
    LinkedList *testing_dupe_list = new LinkedList;
    LinkedList *testing_dupe_list_2 = new LinkedList;
    

    testing_list->addItem("jeff");
    testing_list->addItem("brett");
    testing_list->addItem("jane");
    testing_list->addItem("thom");
    testing_list->addItem("bill");

    testing_list->printList();

    testing_dupe_list = new LinkedList;
    testing_dupe_list->addItem("jeff");
    testing_dupe_list->addItem("brett");
    testing_dupe_list->addItem("jane");
    testing_dupe_list->addItem("jane");
    testing_dupe_list->addItem("bill");

    testing_dupe_list->printList();
    testing_dupe_list->dedup();
    testing_dupe_list->printList();

    testing_dupe_list_2 = new LinkedList;
    testing_dupe_list_2->addItem("jeff");
    testing_dupe_list_2->addItem("brett");
    testing_dupe_list_2->addItem("jane");
    testing_dupe_list_2->addItem("jane");
    testing_dupe_list_2->addItem("jane");

    testing_dupe_list_2->printList();
    testing_dupe_list_2->dedup();
    testing_dupe_list_2->printList();

}