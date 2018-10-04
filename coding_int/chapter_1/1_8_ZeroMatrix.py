import random


def make_matrix(m,n):
    a = []
    # make matrix
    for i in range(m):
        row = []
        for j in range(n):
            row.append(random.randint(1,10) )
        a.append(row)

    return a


def zeroMatrix(mat_n, m, n):


    zero_rows_change = []
    zero_cols_change = []
    for i in range(m):
        for j in range(n):
            if (mat_n[i][j] == 0):
                zero_rows_change.append(i)
                zero_cols_change.append(j)


    # if we do it in one loop then it will cascade through
    result_mat = mat_n
    for i in range(m):
        for j in range(n):
            if i in zero_rows_change or j in zero_cols_change:
                result_mat[i][j] = 0
    
    return result_mat

def pretty_print(mat_obj):

    for row in range(len(mat_obj)):
        print(mat_obj[row])
    
    print("----##------")

    return 0



if __name__ == "__main__":

    m = 4
    n = 3
    a = make_matrix(m, n)

    a[1][1] = 0
    pretty_print(a)

    b = zeroMatrix(a, m, n)
    pretty_print(b)

    m1 = 10
    n1 = 12
    big_mat = make_matrix(m1,n1)

    big_mat[1][2] = 0
    pretty_print(big_mat)

    zero_big_mat = zeroMatrix(big_mat, m1, n1)
    pretty_print(zero_big_mat)



    