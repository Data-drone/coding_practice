#include<iostream>
#include<vector>

void print_matrix(std::vector<std::vector<int>> to_print) {

    for (int i = 0; i < to_print.size(); ++i) {
        for (int j = 0; j < to_print.size(); ++j) {
            std::cout << " " << to_print[i][j];
        }
        std::cout << std::endl;
    }

}

int main() {

    int size = 3;

    std::vector<std::vector<int>> matrix_sample(size, std::vector<int>(size));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix_sample[i][j] = rand() % 10;
        }
    }

    print_matrix(matrix_sample);

    return 1;
}