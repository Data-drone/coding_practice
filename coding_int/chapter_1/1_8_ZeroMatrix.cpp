#include<iostream>
#include<vector>
#include<algorithm>

void make_matrix(std::vector<std::vector<int>> mat_hold) {

    using size_type = decltype(mat_hold)::size_type;
    for (size_type i = 0; i < mat_hold.size(); ++i ) {
        for (size_type j = 0; j = mat_hold[0].size(); ++j) {
            mat_hold[i][j] = rand() % 15;
        } 
    }
}

int main() {

    int m = 3;
    int n = 4;
    std::vector<std::vector<int>> test_matrix(m, std::vector<int>(n));

    make_matrix(test_matrix);


}
