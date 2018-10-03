# scenarios:
# basically count letters if total character count is even then all counts must be even
# else allow one set of odd
# lower and strip spaces then character count?

# odd / even is by modulo 2

def isPallindrome(striga):

    transform = striga.lower()
    transform = transform.replace(" ", "")

    holder = {}
    length_string = 0

    for char in transform:
        if char in holder.keys():
            holder[char] += 1
        else:
            holder[char] = 1

        length_string += 1
    
    if (length_string % 2 == 0):

        for key in holder.keys():
            if (holder[key] % 2 != 0):
                return False
        
        return True
    
    elif (length_string % 2 != 0):
        odd = 0

        for key in holder.keys():
            if( holder[key] % 2 != 0):
                odd += 1
                if (odd > 1):
                    return False
        
        return True
    
    raise ValueError("our logic failed")

if __name__ == "__main__":
    
    a = "eat food" # should be false
    b = "abba" # should be true
    c = "eateatfood" # should be false
    d = "eat eat food" # should be false
    e = "eat tae dood" # should be true

    list_tests = [a,b,c,d,e]

    for item in list_tests:
        print(isPallindrome(item))