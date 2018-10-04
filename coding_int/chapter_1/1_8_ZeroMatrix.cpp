#include<iostream>
#include<vector>
#include<algorithm>

void make_matrix(std::vector<std::vector<int>>& mat_hold) {

    for (int i = 0; i < mat_hold.size(); ++i ) {
        for (int j = 0; j < mat_hold[0].size(); ++j) {
            mat_hold[i][j] = rand() % 8;
        } 
    }
}

void print_matrix(std::vector<std::vector<int>>& to_print) {

    for (int i = 0; i < to_print.size(); ++i) {
        for (int j = 0; j < to_print[0].size(); ++j) {
            std::cout << " " << to_print[i][j];
        }
        std::cout << std::endl;
    }
}

void zero_matrix(std::vector<std::vector<int>>& zero_out) {

    std::vector<int> rows(zero_out.size());
    std::vector<int> cols(zero_out[0].size());

    int counter = 0;
    for (int i = 0; i < zero_out.size(); ++i) {
        for(int j = 0; j < zero_out[0].size(); ++j) {
            if (zero_out[i][j] == 0) {
                rows[counter] = i;
                cols[counter] = j;
                ++counter;
            }
        }
    }

    for (int holder = 0; holder < counter; ++holder ){
        int row = rows[holder];
        int col = cols[holder];

        for (int col_it = 0; col_it < zero_out[0].size(); ++col_it) {
            zero_out[row][col_it] = 0;
        }
        for (int row_it = 0; row_it < zero_out.size(); ++row_it) {
            zero_out[row_it][col] = 0;
        }
    }
}
/*
void zero_matrix_opt(std::vector<std::vector<int>>& zero_out_2) {

    std::vector<int> rows(zero_out_2.size());
    std::vector<int> cols(zero_out_2[0].size());

    int tot_columns = zero_out_2[0].size();

    int counter = 0;
    for (int i = 0; i < zero_out_2.size(); ++i) {
        auto it = std::find(zero_out_2.begin(), zero_out_2.end(), 0);
        
        if ( it != zero_out_2.end()) {
            std::vector<int> arr(tot_columns);
            zero_out_2[i] = arr;
        } 

        for (int j = 0; j < zero_out_2.size(); ++j) {
            int col_to_zero = it - zero_out_2.begin();
            zero_out_2[j][col_to_zero] = 0;
        }
    }

}*/


int main() {

    int m = 3;
    int n = 5;
    std::vector<std::vector<int>> test_matrix(m, std::vector<int>(n));

    make_matrix(test_matrix);
    print_matrix(test_matrix);
    std::cout << "-----## made matrix ##-----" << std::endl;

    // test case set a 0
    test_matrix[1][3] = 0;
    print_matrix(test_matrix);

    // find zeros and set the column and row
    std::cout << "-----## added a zero ##-----" << std::endl;
    zero_matrix_opt(test_matrix);
    print_matrix(test_matrix);

    std::cout << "-----## added a zeroed out ##-----" << std::endl;
    

    m = 4;
    n = 8;
    std::vector<std::vector<int>> test_mat_2(m, std::vector<int>(n));

    make_matrix(test_mat_2);
    print_matrix(test_mat_2);
    std::cout << "-----## made matrix ##-----" << std::endl;

    // test case set a 0
    test_mat_2[1][3] = 0;
    test_mat_2[2][4] = 0;
    print_matrix(test_mat_2);

    // find zeros and set the column and row
    std::cout << "-----## added a zero ##-----" << std::endl;
    zero_matrix_opt(test_mat_2);
    print_matrix(test_mat_2);

    std::cout << "-----## added a zeroed out ##-----" << std::endl;





}
