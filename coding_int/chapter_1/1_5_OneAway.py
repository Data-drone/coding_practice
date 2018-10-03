from collections import Counter

def oneAway(a,b):
    a = a.lower()
    b = b.lower()

    # base check
    if abs(len(a) - len(b)) > 1:
        return False

    a_dict = Counter(a)
    b_dict = Counter(b)

    diff = 0
    for key in a_dict.keys():
        key_value = a_dict[key]

        if key_value > 1:
            if key not in b_dict.keys():
                return False
            else:
                if abs(a_dict[key] - b_dict[key]) > 1:
                    return False
                else:
                    if abs(a_dict[key] - b_dict[key]) == 1:
                        diff += 1
        else:
            if key_value == 1:
                if key not in b_dict.keys():
                    diff += 1
                if key in b_dict.keys():
                    if abs(a_dict[key] - b_dict[key]) > 1:
                        return False
                    elif abs(a_dict[key] - b_dict[key]) == 1:
                        diff += 1
        if diff > 1:
            return False

    return True

if __name__ == "__main__":

    print(oneAway("pale", "ple"))
    print(oneAway("pales", "pale"))
    print(oneAway("pale", "bale"))
    print(oneAway("pale", "bake"))



