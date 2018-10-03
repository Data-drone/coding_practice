#include<iostream>
#include<string>

std::string compressString(std::string toTest) {

    char holder;
    int counter = 0;
    bool shortened = false;
    std::string answer_string = "";


    for(std::string::size_type i = 0; i < toTest.length(); ++i ) {

        if (i == 0) {
            holder = toTest[0];
            counter = 1;
            answer_string.append(1, holder);
        } else {
            if (holder == toTest[i]) {
                ++counter;
                shortened = true;
            } else {
                answer_string.append(std::to_string(counter));
                counter = 1;
                holder = toTest[i];
                answer_string.append(1, holder);
            }
        }

        if (i == toTest.length() - 1) {
            answer_string.append(std::to_string(counter));
        }


    }
    if (shortened) {
        return answer_string;
    }
    return toTest;

}

int main() {

    std::string a = "aabccaabbcc";
    std::string b = "baltic";
    std::string c = "rabbit";
    std::string d = "eat eat eat";
    std::string e = "aabccaabbcc";
    std::string f = "bacon toot";

    std::cout << compressString(a) << std::endl;
    std::cout << compressString(b) << std::endl;
    std::cout << compressString(c) << std::endl;
    std::cout << compressString(d) << std::endl;
    std::cout << compressString(e) << std::endl;
    std::cout << compressString(f) << std::endl;


}