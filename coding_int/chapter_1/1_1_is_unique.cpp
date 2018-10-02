#include<iostream>
#include<set>

int main() {

    std::string testString = "test1";
    int length = testString.length();

    std::set<char> setOfCharacters;

    for (int i = 0; i < testString.length(); i++) {
        if (setOfCharacters.insert(testString[i]).second == false) {
            std::cout << "duplicate: " << testString[i] << std::endl;
            return 1;
        }

        setOfCharacters.insert(testString[i]);
        std::cout << testString[i] << std::endl;
    }
    

    return 1;

}