#include<iostream>
#include<string>

std::string urlIfy(std::string a) {

    std::string result;
    std::string replacement = "%20";

    for (std::string::size_type i=0; i < a.length(); ++i) {
        char test = a[i];

        if(isspace(test)) {
            result += replacement;
        } else {
            result += a[i];
        }
    }

    return result;
}

int main(){

    std::string a = "test string";
    std::string b = "test string of stuff";
    std::string c = "ohnonospaces";

    std::cout << "raw: \"" << a << "\" urlified \"" << urlIfy(a) << "\"" << std::endl;
    std::cout << "raw: \"" << b << "\" urlified \"" << urlIfy(b) << "\"" << std::endl;
    std::cout << "raw: \"" << c << "\" urlified \"" << urlIfy(c) << "\"" << std::endl;
    

}