#include<iostream>
#include<unordered_map>
#include<string>
#include<cmath>

bool oneAway(std::string a, std::string b){

    std::unordered_map<char, int> a_map;
    std::unordered_map<char, int> b_map;

    int diff = a.length() - b.length();

    int length_diff = std::abs(diff);
    if (length_diff > 1) {
        return false;
    }
    //std::cout << "same length" << std::endl;

    for (std::string::size_type i = 0; i < a.size(); ++i) {
        ++a_map[a[i]];
    }

    for (std::string::size_type i = 0; i < b.size(); ++i) {
        ++b_map[b[i]];
    }

    int diff_count = 0;

    for (auto it : a_map) {
        auto b_find = b_map.find(it.first);
        //std::cout << "into loop" << std::endl;
        if (it.second > 1) {
            //std::cout << "path 1 " << std::endl;
            if (b_find == b_map.end()) {
                return false;
            } else {
                int bcount = b_find->second;
                int count_diff = it.second - bcount;
                if (count_diff > 1) {
                    return false;
                } else if (count_diff == 1) {
                    ++diff_count;
                }
            }
        }

        if (it.second == 1) {
            //std::cout << "path 2 " << std::endl;
            if (b_find == b_map.end()) {
                ++diff_count;
            } else {
                int bcount = b_find->second;
                int count_diff = it.second - bcount;
                if (count_diff > 1) {
                    return false;
                } else if (count_diff == 1) {
                    ++diff_count;
                }
            }
        }

        if (diff_count > 1) {
            return false;
        }  
    }

    return true;
}

int main() {

    std::string a = "pale";
    std::string b = "ple";

    std::string c = "pales";
    std::string d = "pale";
    
    std::string e = "pale";
    std::string f = "bale";

    std::string g = "pale";
    std::string h = "bake";

    std::cout << "string a " << a << " string b " << b << " result " << oneAway(a,b) << std::endl;
    std::cout << "string a " << c << " string b " << d << " result " << oneAway(c,d) << std::endl;
    std::cout << "string a " << e << " string b " << f << " result " << oneAway(e,f) << std::endl;
    std::cout << "string a " << g << " string b " << h << " result " << oneAway(g,h) << std::endl;
    
}