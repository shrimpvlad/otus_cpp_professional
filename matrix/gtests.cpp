#include <gtest/gtest.h>
#include "matrix.hpp"

TEST(Matrix, size) {
    Matrix<int, 0> matrix;
    for (int i = 0; i < 10; ++i) {
        matrix[i][i] = 99;
    }
    size_t expectedResult1 = 10;
    ASSERT_EQ(matrix.size(), expectedResult1);

    matrix[5][5] = 0;
    size_t expectedResult2 = 9;
    ASSERT_EQ(matrix.size(), expectedResult2);
}

TEST(Matrix, elements) {
    Matrix<int, 0> matrix;
    matrix[5][50] = 6;
    matrix[50][50] = 8;
    ASSERT_EQ(matrix[5][50], 6);
    ASSERT_EQ(matrix[50][50], 8);
    ASSERT_EQ(matrix[51][50], 0);
    ((matrix[100][100] = 314) = 0) = 217;
    ASSERT_EQ(matrix[100][100], 217);
}

TEST(PrintIP, loop) {
    Matrix<int, 0> matrix;
    for (int i = 0; i < 10; ++i) {
        matrix[i][i] = 37;
    }
    ASSERT_EQ(matrix.size(), 10);
    for (const auto& m : matrix) {
        ASSERT_EQ(m.second, 37);
    }
}
