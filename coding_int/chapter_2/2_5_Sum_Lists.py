
class node:
    def __init__(self, value = None):
        self.next = None
        self.value = value

class llist:
    def __init__(self, head = None):
        self.head = head
        self.tail = None

    def __iter__(self):
        current = self.head
        while current is not None:
            yield current
            current = current.next

    def __str__(self):    
        for item in self:
            if item is not None:
                print("{0} \t".format(item.value))

        return "---END---"

    def addValue(self, value):
        
        new_node = node(value)
        if (self.head is None):
            self.head = new_node
            self.tail = new_node

        else:
            self.tail.next = new_node
            self.tail = new_node


def sum_vecs(list1, list2):

    total = llist()

    v1 = []
    v2 = []

    for i1, i2 in zip(list1, list2):
        v1 = [str(i1.value)] + v1
        v2 = [str(i2.value)] + v2

    num1 = int(''.join(v1))
    num2 = int(''.join(v2))

    summation = str(num1 + num2)[::-1]

    for digit in summation:
        total.addValue(digit)

    return total


if __name__ == "__main__":

    vec_1 = llist()
    vec_1.addValue(3)
    vec_1.addValue(5)
    vec_1.addValue(4)

    vec_2 = llist()
    vec_2.addValue(6)
    vec_2.addValue(6)
    vec_2.addValue(3)

    sum_vec = sum_vecs(vec_1, vec_2)
    print(sum_vec)