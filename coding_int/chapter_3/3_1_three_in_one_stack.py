

class fixed_size_array:

    def __init__(self, stack_size=9, num_stacks=3):
        self.sizes = [0 for x in range(0, num_stacks)]
        self.values = [None for x in range(0, num_stacks*stack_size)]
        self.stackSize = stack_size

        
    def push(self, value, stacknum):
        # add a value if the stack isn't full
        if not self.isFull(stacknum):
            index = stacknum*self.stackSize + self.sizes[stacknum]
            self.values[index] = value
            self.sizes[stacknum] += 1
        else:
            print("stack is full")
            return None



    def pop(self, stacknum):
        # remove the top value and return it 
        if not self.isEmpty(stacknum):
            index = stacknum*self.stackSize + self.sizes[stacknum]
            ret_value = self.values[index]
            self.values[index] = None
            self.sizes[stacknum] -= 1
            return self.values[index]
        else:
            return None
    
    def peek(self, stacknum):
        # get top value in place without removing it
        if not self.isEmpty(stacknum):
            return self.values[stacknum*self.stackSize + self.sizes[stacknum]+1]
        else:
            return None

    def isEmpty(self, stacknum):
        # check if a stack is empty or not
        if (self.sizes[stacknum] == 0) and (self.values[stacknum*self.stackSize] is None):
            return True
        else:
            return False
        
    def isFull(self, stacknum):
        if (self.sizes[stacknum] == self.stackSize):
            return True
        else:
            return False

if __name__ == "__main__":


    test_stack = fixed_size_array(stack_size = 2)


    for i in range(0,3):
        assert test_stack.isEmpty(i) == True, "isEmpty isn't working"

    for i in range(0,3):
        test_stack.push(value=3, stacknum=i)
        test_stack.push(value=2, stacknum=i)
    
    for i in range(0,3):
        assert test_stack.isEmpty(i) == False, "isEmpty isn't working"
        assert test_stack.isFull(i) == True, "isFull isn't working"

    for i in range(0,3):
        print("value is: {0}".format(test_stack.peek(stacknum = i)))
        assert test_stack.peek(stacknum = i) == 2, "peek is pulling wrong value"




    


    