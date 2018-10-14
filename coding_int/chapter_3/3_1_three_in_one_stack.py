

class fixed_size_array:

    def __init__(self, stack_size=9, num_stacks=3):
        self.sizes = [0 for x in range(0, num_stacks)]
        self.values = []
        self.stackSize = stack_size

        
    def push(self, value, stacknum):
        # add a value if the stack isn't full
        if not isFull(stacknum):
            index = stacknum*stackSize + sizes[stacknum]
            values[index] = value
            sizes[stacknum] += 1
        else:
            print("stack is full")
            return None



    def pop(self, stacknum):
        # remove the top value and return it 
        if not isEmpty(stacknum):
            index = stacknum*stackSize + sizes[stacknum]
            ret_value = values[index]
            values[index] = None
            sizes[stacknum] -= 1
            return values[index]
        else:
            return None
    
    def peek(self, stacknum):
        # get top value in place without removing it
        if not isEmpty(stacknum):
            return values[stacknum*self.stackSize + sizes[stacknum]]
        else:
            return None

    def isEmpty(self, stacknum):
        # check if a stack is empty or not
        if (sizes[stacknum] == 0) and (values[stacknum*self.stackSize] is None):
            return True
        else:
            return False
        
    def isFull(self, stacknum):
        if (sizes[stacknum] == self.stackSize):
            return True
        else:
            return False

if __name__ == "__main__":


    for i in range(3, 13):
        test_stack = fixed_size_array(array_size = i)
        print("i: {0}, stack_starts: {1}".format(i, test_stack.stack_starts))



    


    