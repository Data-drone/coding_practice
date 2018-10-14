class fixed_size_array:

    def __init__(self, array_size=9, num_stacks=3):
        self.size = array_size
        self.stacks = num_stacks

        self.stack_starts = [0]
        if num_stacks > array_size:
            print("too many stacks for given size")
        else:
            stack_size = int(round(self.size / self.stacks))
            for i in range(1, self.stacks):
                self.stack_starts.append(stack_size*i)


if __name__ == "__main__":


    for i in range(3, 13):
        test_stack = fixed_size_array(array_size = i)
        print("i: {0}, stack_starts: {1}".format(i, test_stack.stack_starts))



    


    