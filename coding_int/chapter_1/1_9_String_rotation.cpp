#include<iostream>
#include<string>

bool isSubstring(std::string a, std::string b) {

    if (a.size() != b.size()) {
        return false;
    }

    std::string c = b + b;

    if(c.find(a) != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

int main() {

    std::string a = "waterbottle";

    std::string b1 = "lewaterbott";
    std::string b2 = "bottlewater";
    std::string b3 = "erbottlewat";
    std::string b4 = "ersdftlewat";

    std::cout << isSubstring(a, b1) << std::endl;
    std::cout << isSubstring(a, b2) << std::endl;
    std::cout << isSubstring(a, b3) << std::endl;
    std::cout << isSubstring(a, b4) << std::endl;
    

}