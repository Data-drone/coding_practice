class item:
    def __init__(self, data_v):
        self.data = data_v
        self.next = None
        self.previous = None

class stack:
    """
    a stack is a Last in First out structure
    we will implement with a doubly linked list
    """

    def __init__(self):
        self.head = None
        self.last = None

    def pop(self):
        if self.last is not None:
            extract = self.last
            if (extract == self.head):
                self.head = None
            self.last = self.last.previous
            return extract
        else:
            return None

    def push(self, datavalue):
        # add item to the top
        new_item = item(datavalue)
        if self.head is None:
            self.head = new_item
            self.last = new_item
            
        else:
            current_last = self.last
            self.last.next = new_item
            self.last = new_item
            self.last.previous = current_last
            
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

if __name__ == "__main__":

    test_Stack = stack()
    # test initiation
    assert test_Stack.isEmpty() == True
    assert test_Stack.peek() == None
    assert test_Stack.pop() == None

    # test with one object
    test_Stack.push("test1")
    assert test_Stack.isEmpty() == False

    # test that peek doesn't remove
    result = test_Stack.peek()
    assert isinstance(result, item)
    assert test_Stack.isEmpty() == False

    # should be empty after we pop it out
    result2 = test_Stack.pop()
    assert isinstance(result2, item)
    assert test_Stack.isEmpty() == True, "pop isn't removing properly"






