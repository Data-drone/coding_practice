class node:
    def __init__(self, value=None):
        self.next = None
        self.data = value

class llist:

    def __init__(self, head=None):
        self.head = head
        self.tail = None

    def __iter__(self):
        current = self.head
        while current is not None:
            yield current
            current = current.next

    def __str__(self):
        print("----start----")
        for item in self:
            if item.data is not None:
                print("{0} \t".format(item.data))

        return "----END----"

    def addValue(self, value):
        new_node = node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

def extract_node(llist, node_value):

    for item in llist:
        if item.data == node_value:
            return item

def remove_node(node):

    next_node = node.next
    node.next = next_node.next
    node.data = next_node.data

if __name__ == "__main__":

    test_list = llist()
    test_list.addValue("test1")
    test_list.addValue("test2")
    test_list.addValue("test3")
    test_list.addValue("test4")
    test_list.addValue("test5")
    test_list.addValue("test6")

    test3_node = extract_node(test_list, "test3")

    print(test3_node.data)

    remove_node(test3_node)

    print(test_list)

    