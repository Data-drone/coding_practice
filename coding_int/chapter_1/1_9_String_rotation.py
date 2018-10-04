
def stringRotation(a, b):

    assert len(a) == len(b)

    merger = b + b

    if (merger.find(a) != -1):
        return True
    else:
        return False

    # waterbottle
    # lewaterbott
    # bottlewater
    # erbottlewat   
    # 

if __name__ == "__main__":

    print(stringRotation("waterbottle", "lewaterbott"))
    print(stringRotation("waterbottle", "bottlewater"))
    print(stringRotation("waterbottle", "erbottlewat"))

    print(stringRotation("waterbottle", "ersdftlewat"))
     
