from stack import stack

class MinStack(stack):

    def __init__(self):
        stack.__init__(self)
        self.min_array = []
        
    def min():
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