class Node:

    def __init__(self, dataval=None):
        self.nextval = None
        self.dataval = dataval

class unordered_linked_list:
    def __init__(self):
        self.headval = None
        self.tailval = None

    def __iter__(self):
        current = self.headval
        while current is not None:
            yield current
            current = current.nextval

    def __str__(self):

        for item in self:
            if item.dataval is not None:
                print("{0} \t".format(item.dataval))

        return "END"    
        

    def add_value(self, value):

        new_item = Node(dataval = value)
        if self.headval is None:
            self.headval = new_item
            self.tailval = new_item
        else:
            self.tailval.nextval = new_item
            self.tailval = new_item

def Kth_to_last(node, n = 0):

    if node is None:
        return (0, None)
        
    (i, res) = Kth_to_last(node.nextval, n)
    if i == n:
        res = node.dataval
    i += 1
    return (i, res)


if __name__=="__main__":

    newl = unordered_linked_list()
    newl.add_value("tom")
    newl.add_value("james")
    newl.add_value("brett")
    newl.add_value("andrew")
    newl.add_value("jack")
    newl.add_value("edge")

    print(newl)

    print(Kth_to_last(newl.headval, 4))



    


