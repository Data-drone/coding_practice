from collections import Counter

def string_compression(stringa):

    pos = 0
    count = 0

    dict_test = Counter(stringa)
    if (len(dict_test.keys()) == len(stringa)):
        return stringa

    result = ""
    for item in stringa:
        if pos == 0:
            holder = item
            count = 1
            result += item

        else:
            if item == holder:
                count += 1
            else:
                result += str(count)
                holder = item
                result += item
                count = 1

            if (pos == (len(stringa) - 1)):
                result += str(count)

        pos += 1
    
    return result

if __name__ == "__main__":

    print(string_compression("aabccaabbcc"))
    print(string_compression("baltic"))
    print(string_compression("rabbit"))
    print(string_compression("eat eat eat"))
    print(string_compression("aabccaabbcc"))
    print(string_compression("bacon toot"))