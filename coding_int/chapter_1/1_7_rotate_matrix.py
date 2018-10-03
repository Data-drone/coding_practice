import random
import numpy


def make_matrix(n):
    a = []
    # make matrix
    for i in range(n):
        row = []
        for j in range(n):
            row.append(random.randint(1,10) )
        a.append(row)

    return a

def rotate_matrix_left(mat):

    # reversed is an in place copy with reversed indexes
    mat = list(zip(*mat))
    return list(reversed(mat))

def rotate_matrix_right(mat):

    return list(zip(*reversed(mat)))


if __name__ == "__main__":

    # matrix maker - 3x3
    n = 3

    a = make_matrix(n)
    print(a)

    b = rotate_matrix_left(a)
    print(b)

    c = rotate_matrix_right(a)
    print(c)
