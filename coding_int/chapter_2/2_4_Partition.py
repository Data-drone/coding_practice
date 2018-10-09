class node:
    def __init__(self, val = None):
        self.next = None
        self.val = val

class llist:
    def __init__(self, head_node = None):
        self.head = head_node
        self.tail = None

    def __iter__(self):
        current = self.head
        while current is not None:
            yield current
            current = current.next

    def __str__(self):
        print("---start---")
        for item in self:
            if item.val is not None:
                print("{0} \t".format(item.val))

        return "---end---"
    
    def addValue(self, value):

        new_node = node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
    
    def partition(self, pivot):

        less = llist()
        more = llist()

        for item in self:
            if item.val is not None:
                if (item.val < pivot):
                    less.addValue(item.val)
                elif item.val >= pivot:
                    more.addValue(item.val)

        self.head = less.head
        self.tail = less.tail
        self.tail.next = more.head
        self.tail = more.tail

if __name__ == "__main__":

    test_list = llist()
    test_list.addValue(1)
    test_list.addValue(5)
    test_list.addValue(6)
    test_list.addValue(9)
    test_list.addValue(3)
    test_list.addValue(7)

    print(test_list)

    test_list.partition(6)
    print(test_list)
    

    