
def urlIfy(string_thing):

    result = string_thing.replace(" ", "%20")

    return result


if __name__ == "__main__":

    a = "test string"
    b = "test string of stuff"
    c = "ohnonospaces"

    print(urlIfy(a))
    print(urlIfy(b))
    print(urlIfy(c))
