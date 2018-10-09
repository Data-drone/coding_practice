class node:
    def __init__(self, value=None):
        self.next = None
        self.datavalue = value
    
class llist:
    def __init__(self, head=None):
        self.head = head
        self.tail = None

    def __iter__(self):
        current = self.head
        while(current):
            yield current
            current=current.next

    def __str__(self):
        current = self.head
        result = ""
        while(current):
            result = result + current.datavalue + " " 
            current = current.next

        return result

    def addValue(self, dataitem):

        new_node = node(dataitem)
        if self.head is None:
            self.head = new_node
            self.tail = new_node

        else:
            self.tail.next = new_node
            self.tail = new_node

    def isPalindrome(self):

        forward = ''.join([x.datavalue for x in self])
        backward = ''.join([x.datavalue for x in self])[::-1]

        return(forward == backward)
        

if __name__ == "__main__":

    test_list = llist()
    test_list.addValue("c")
    test_list.addValue("a")
    test_list.addValue("a")
    test_list.addValue("c")
    print(test_list)
    print(test_list.isPalindrome())

    test_list_2 = llist()
    test_list_2.addValue("c")
    test_list_2.addValue("a")
    test_list_2.addValue("b")
    test_list_2.addValue("c")
    test_list_2.addValue("a")
    print(test_list_2)
    print(test_list_2.isPalindrome())

            