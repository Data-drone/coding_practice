

def find_permutations(stringa, stringb):
    """
    check if stringa and stringb are permutations of each other
    """
    
    dict_x = {}
    for char in stringa:
        if char not in dict_x.keys():
            dict_x[char] = 1
        else:
            dict_x[char] += 1
    
    for char in stringb:
        if char not in dict_x.keys():
            return "not permutation"
        else:
            dict_x[char] -= 1
            if dict_x[char] < 0:
                return "not permutation"
    
    return "permutation"

if __name__ == "__main__":

    string_a = "abasdfjaklwerjajvkjaretasfsd"
    string_b = "aba"

    string_c = "dakka"
    string_d = "akdka"

    string_e = "eatme"
    string_f = "eatlots"

    print(find_permutations(string_a, string_b))

    print(find_permutations(string_c, string_d))

    print(find_permutations(string_e, string_f))

