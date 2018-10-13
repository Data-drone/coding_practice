class item:
    def __init__(self, data_v):
        self.data = data_v
        self.next = None

class stack:
    """
    a stack is a Last in First out structure
    we will implement with a linked list
    """

    def __init__(self):
        self.head
        self.last

    def pop(self):
        # TODO implement
        # remove the top item
        raise NotImplementedError

    def push(self, datavalue):
        # add item to the top
        new_item = item(datavalue)
        if self.head is None:
            self.head = new_item
            self.last = new_item
        else:
            self.last.next = new_item
            self.last = new_item
            

    def peek(self):
        if self.last is not None:
            return self.last
        else:
            print("stack is empty")
            return None

    def isEmpty(self):
        if self.head is None:
            return True
        else:
            return False