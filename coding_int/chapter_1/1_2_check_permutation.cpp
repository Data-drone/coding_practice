#include<iostream>
#include<string>
#include<unordered_map>

int main() 
{
    std::string first = "checkers";
    std::string second = "che";

    std::unordered_map<std::string, int> first_umap;


    for(int i = 0; i <= first.length(); i ++) {
        // issue with character types for the unordered_map
        std::string myChar = first[i];
        auto find_int = first_umap.find(myChar);

        if (find_int == first_umap.end()) {
            first_umap[myChar] = 1;
        } else {
            find_int->second ++;
        }

    }
    return 1;
}
