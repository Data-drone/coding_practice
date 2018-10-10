class node:
    def __init__(self, value=None):
        self.next = None
        self.datavalue = value
    
    def __str__(self):
        return "node: {0}".format(self.datavalue)

class llist:
    def __init__(self, head=None):
        self.head = head
        self.tail = head

    def __iter__(self):
        current = self.head
        while(current):
            yield current
            current = current.next
    
    def __str__(self):
        current = self.head
        result = ""
        while(current):
            result = result + str(current.datavalue) + " "
            current = current.next
        return result

    def addValue(self, dataitem):

        if (isinstance(dataitem, node)):
            new_node = dataitem
        else:
            new_node = node(dataitem)
        if (self.head is None):
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

def find_loop(linked_list):

    test_dict = {}

    for item in linked_list:
        if item in test_dict.keys():
            print("circular ref found")
            return item
        else:
            test_dict[item] = True
    print("all clear")
    return False


if __name__ == "__main__":

    test_list = llist()
    test_list.addValue(1)
    test_list.addValue(5)
    test_list.addValue(4)

    result = find_loop(test_list)
    print(result)

    a = node(4)
    b = node(6)
    c = node(8)

    a.next = b
    b.next = c
    c.next = a

    test_list.addValue(a)

    #for item in test_list:
    #    print(item)

    result = find_loop(test_list)
    print(result)


    