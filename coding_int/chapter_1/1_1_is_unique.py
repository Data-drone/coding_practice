
def isUnique(test_string):
    """
    checks if the characters in a string are unique
    """

    holder = {}
    for char in test_string:
        if char in holder.keys():
            return "collision"
        else:
            holder[char] = 1

    return "pass"

if __name__ == "__main__":

    string = "vwap"
    result = isUnique(string)
    print(result)