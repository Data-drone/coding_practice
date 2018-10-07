# Python Linked List

class Node:
    def __init__(self, dataval=None):
        self.dataval = dataval
        self.nextval = None

class unordered_linked_list:
    def __init__(self):
        self.headval = None

    def __iter__(self):
        current = self.headval
        while current is not None:
            yield current
            current = current.nextval

def basic_dedup(llist):
    """
    traverse linked list
    find duplicates
    remove them
    """

    dedup_dict = {}

    if llist.headval is not None:
        dedup_dict[llist.headval.dataval] = 1

    for item in llist:
        # we haven't hit the end yet
        if item.nextval is not None:
            #check next node
            next_item = item.nextval
            if next_item.dataval not in dedup_dict.keys():
                dedup_dict[next_item.dataval] = 1
                
            # key is a duplicate!
            elif next_item.dataval in dedup_dict.keys():
                # there are links to keep
                if next_item.nextval is not None:
                    item.nextval = next_item.nextval
                #just drop this node
                elif next_item.nextval is None:
                    item.nextval = None
                    return basic_dedup(llist)
        
        elif item.nextval is None:
            return llist

    


if __name__ == "__main__":

    llist = unordered_linked_list()
    llist.headval = Node("jack")
    
    n2 = Node("tom")
    n3 = Node("brett")
    n4 = Node("pete")
    n5 = Node("testy")
    n6 = Node("item")
    n7 = Node("item")
    n8 = Node("eats")

    llist.headval.nextval = n2
    n2.nextval = n3
    n3.nextval = n4
    n4.nextval = n5
    n5.nextval = n6
    n6.nextval = n7
    n7.nextval = n8

    print("-----Before-----")
    for item in llist:
        print(item.dataval)



    llist = basic_dedup(llist)

    print("-----After-----")
    for item in llist:
        print(item.dataval)


