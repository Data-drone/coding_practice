
class node:
    def __init__(self, value = None):
        self.next = None
        self.data = value
    
    def __str__(self):
        return "Node: {0}".format(self.data)

class llist:
    def __init__(self, head = None):
        self.head = head 
        self.tail = head

    def __iter__(self):
        current = self.head
        while(current):
            yield current
            current = current.next

    def __str__(self):
        current = self.head
        result = ""
        while(current):
            result = result + str(current.data) + " "
            current=current.next

        return result

    def addValue(self, dataitem):

        if isinstance(dataitem, node):
            new_node = dataitem
        else:    
            new_node = node(dataitem)
        if(self.head is None):
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

def isEqual(node_1, node_2):

    if (isinstance(node_1, node) and (isinstance(node_2, node))):
        if (node_1.data == node_2.data) and (node_1.next == node_2.next):
            return True

    return False

def is_intersect(list_1, list_2):
    
    length1 = 0
    length2 = 0
    for item in list_1:
        length1 +=1
    
    for item in list_2:
        length2 +=1

    if length1 > length2:
        lead, follow = list_1.head, list_2.head
    else:
        lead, follow = list_2.head, list_1.head

    diff = abs(length1-length2)

    while(diff > 0 ):
        lead=lead.next
        diff=diff-1
    
    while (lead is not None):

        if (lead == follow):
            return lead

        lead=lead.next
        follow=follow.next

    return None
    

if __name__ == "__main__":

    list_1 = llist()
    list_2 = llist()

    list_1.addValue(12)
    list_1.addValue(7)
    list_1.addValue(9)

    list_2.addValue(2)
    list_2.addValue(7)

    node_1 = node(4)
    node_2 = node(8)
    node_3 = node(10)

    list_1.addValue(node_1)
    list_1.addValue(node_2)
    list_1.addValue(node_3)

    list_2.addValue(node_1)

    result = is_intersect(list_1, list_2)
    print(result)
