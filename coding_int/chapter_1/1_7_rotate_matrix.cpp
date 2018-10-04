#include<iostream>
#include<vector>
#include<utility>

//const int size = 3;


void print_matrix(std::vector<std::vector<int>>& to_print) {

    for (int i = 0; i < to_print.size(); ++i) {
        for (int j = 0; j < to_print.size(); ++j) {
            std::cout << " " << to_print[i][j];
        }
        std::cout << std::endl;
    }

}

void make_matrix(std::vector<std::vector<int>>& fill_mat) {

    for (int i = 0; i < fill_mat.size(); ++i) {
        for (int j = 0; j < fill_mat.size(); ++j) {
            fill_mat[i][j] = rand() % 15;
        }
    }

    //return matrix_sample;
}

void transpose(std::vector<std::vector<int>>& fill_mat) {
    
    for (int i = 0; i < fill_mat.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            std::swap(fill_mat[i][j], fill_mat[j][i]);//
        }
    }

}

void rotate_right(std::vector<std::vector<int>>& rot_mat) {

    int limit = rot_mat.size()/2;
    //std::cout << "limit swap: " << limit << std::endl;

    transpose(rot_mat);

    for (int i = 0; i < rot_mat.size(); ++i) { // go across the row
        for (int j = 0; j < limit; ++j) {
            std::swap(rot_mat[j][i], rot_mat[rot_mat.size()-1-j][i]);
        }
    }

}

void rotate_left(std::vector<std::vector<int>>& rot_mat) {

    int limit = rot_mat.size()/2;
    //std::cout << "limit swap: " << limit << std::endl;

    transpose(rot_mat);

    for (int i = 0; i < rot_mat.size(); ++i) { // go across the row
        for (int j = 0; j < limit; ++j) {
            std::swap(rot_mat[i][j], rot_mat[i][rot_mat.size()-1-j]);
        }
    }

}
    


int main() {

    int size = 3;
    int size_2 = 4;
    int size_3 = 5;

    std::vector<std::vector<int>> matrix_sample(size, std::vector<int>(size));
    std::vector<std::vector<int>> matrix_sample_2(size_2, std::vector<int>(size_2));
    std::vector<std::vector<int>> matrix_sample_3(size_3, std::vector<int>(size_3));


    make_matrix(matrix_sample);
    print_matrix(matrix_sample);

    std::cout << "----## rotate left ##-----" << std::endl;
    rotate_left(matrix_sample);
    print_matrix(matrix_sample);
    std::cout << "----## rotate right ##-----" << std::endl;
    rotate_right(matrix_sample);
    print_matrix(matrix_sample);
    std::cout << "----## end case ##-----" << std::endl;


    make_matrix(matrix_sample_2);
    print_matrix(matrix_sample_2);
    std::cout << "----## rotate left ##-----" << std::endl;
    rotate_left(matrix_sample_2);
    print_matrix(matrix_sample_2);
    std::cout << "----## rotate right ##-----" << std::endl;
    rotate_right(matrix_sample_2);
    print_matrix(matrix_sample_2);
    std::cout << "----## end case ##-----" << std::endl;

    make_matrix(matrix_sample_3);
    print_matrix(matrix_sample_3);
    std::cout << "----## rotate left ##-----" << std::endl;
    rotate_left(matrix_sample_3);
    print_matrix(matrix_sample_3);
    std::cout << "----## rotate right ##-----" << std::endl;
    rotate_right(matrix_sample_3);
    print_matrix(matrix_sample_3);
    std::cout << "----## end case ##-----" << std::endl;


    return 1;
}