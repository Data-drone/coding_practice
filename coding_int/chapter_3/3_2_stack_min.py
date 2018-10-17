from stack import stack, item

class MinStack(stack):

    def __init__(self):
        stack.__init__(self)
        self.min_array = []
        
    def min(self):
        return self.min_array[-1]
    
    def push(self, datavalue):
        # add item to the top
        if isinstance(datavalue, item):
            new_item = datavalue
        else:
            new_item = item(datavalue)
        if self.head is None:
            self.min_array.append(new_item)
            
            self.head = new_item
            self.last = new_item
            
        else:
            if datavalue < self.min_array[-1].data:
                self.min_array.append(new_item)
            else:
                self.min_array.append(self.min_array[-1])
            current_last = self.last
            self.last.next = new_item
            self.last = new_item
            self.last.previous = current_last

    def pop(self):
        if self.last is not None:
            extract = self.last
            self.min_array.pop()
            if (extract == self.head):
                self.head = None
            self.last = self.last.previous
            return extract
        else:
            return None

if __name__ == "__main__":

    test_stack = MinStack()

    test_stack.push(4)
    assert test_stack.min().data == 4, 'wrong minimum'

    test_stack.push(3)
    assert test_stack.min().data == 3, 'wrong minimum'

    test_stack.push(2)
    assert test_stack.min().data == 2, 'wrong minimum'

    test_stack.push(6)
    assert test_stack.min().data == 2, 'wrong minimum'

    test_stack.pop()
    test_stack.pop()
    assert test_stack.min().data == 3, 'wrong minimum'


