#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

std::string sort_compare(std::string A, std::string B){

    // base case
    if(A.length() != B.length()) {
        return "not permutation";
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(std::string::size_type i = 0; i < A.length(); i++) {
        if(A[i] != B[i]){
            return "not permutation";
        }
    }

    return "permutation";
}

std::string count_compare(std::string A, std::string B) {

    // base case
    if(A.length() != B.length()) {
        return "not permutation";
    }    

    std::unordered_map<char, signed int> first_umap;
    std::unordered_map<char, signed int> second_umap;
    
    // build unsorted_map for both strings    
    for(std::string::size_type i = 0; i <= A.length(); i ++) {
        ++first_umap[A[i]];
        ++second_umap[B[i]];
    }

    for(auto it : first_umap) {
        // search for key from first in second
        auto find_in_second=second_umap.find(it.first);

        if (find_in_second != second_umap.end()) {
            // we found it 
            if (first_umap.find(it.second) != second_umap.find(it.second)) {
                // different counts so no good
                return "not permutation";
            }
        } else {
            return "not permutation";
        }
    }


    return "permutation";
}

int main() 
{
    std::string first = "checkers";
    std::string second = "checcers";

    std::string third = "karl";
    std::string fourth = "lrak";

    // use sort
    std::string result = sort_compare(first, second);
    std::cout << "sort compare result: " << result << std::endl;
    
    result = sort_compare(third, fourth);
    std::cout << "sort compare result: " << result << std::endl;

    // don't use sort
    result = count_compare(first, second);
    std::cout << "sort count result: " << result << std::endl;
    
    result = count_compare(third, fourth);
    std::cout << "sort count result: " << result << std::endl;

    return 1;
}
