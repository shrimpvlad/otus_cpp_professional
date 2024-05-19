#include <tuple>
#include <stdexcept>
#include <cassert>
#include "matrix.hpp"

int main() {
    // Matrix<int, -1> matrix;
    // assert(matrix.size() == 0); // все ячейки свободны
    // auto a = matrix[0][0];
    // assert(a == -1);
    // assert(matrix.size() == 0);
    // matrix[100][100] = 314;
    // assert(matrix[100][100] == 314);
    // assert(matrix.size() == 1);
    // // выведется одна строка
    // // 100100314
    // for(auto c: matrix)
    // {
    //     int x = c.first.first;
    //     int y = c.first.second;
    //     int v = c.second;
    //     std::cout << x << y << v << std::endl;
    // }
    // ((matrix[100][100] = 314) = 0) = 217;
    // std::cout << matrix[100][100] << std::endl;

    Matrix<int, 0> matrix;
    std::cout << "matrix:\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == j || (i == 9 - j)) {
                matrix[i][j] = i;
            }
        }
    }
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {    
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "size = " << matrix.size() << std::endl;
    for (const auto& m : matrix) {
        std::cout << "matrix["<< m.first.first << "][" << m.first.second << "] = "<< m.second << std::endl;
    }
}