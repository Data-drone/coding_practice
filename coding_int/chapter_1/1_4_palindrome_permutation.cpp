#include<iostream>
#include<string>
#include<unordered_map>

bool isPallindrome(std::string abba) {

    std::unordered_map<char, int> holder;

    for (std::string::size_type i = 0; i < abba.length(); ++i) {
        ++holder[abba[i]];
    }

    if (abba.length() % 2 == 0) {
        for (auto it : holder) {
            if (it.second % 2 != 0) {
                return false;
            }
        }

        return true;

    } else if (abba.length() % 2 != 0) {
        int odd = 0;
        for (auto it : holder) {
            if (it.second % 2 != 0) {
                ++odd;

                if (odd > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    return false;
}

int main() {

    std::string a = "eat food"; // should be false
    std::string b = "abba"; // should be true
    std::string c = "eateatfood"; // should be false
    std::string d = "eat eat food"; // should be false
    std::string e = "eat tae dood"; // should be true

    std::cout << "case is: " << a << " result is: " << isPallindrome(a) << std::endl;
    std::cout << "case is: " << b << " result is: " << isPallindrome(b) << std::endl;
    std::cout << "case is: " << c << " result is: " << isPallindrome(c) << std::endl;
    std::cout << "case is: " << d << " result is: " << isPallindrome(d) << std::endl;
    std::cout << "case is: " << e << " result is: " << isPallindrome(e) << std::endl;

    return 1;
}
