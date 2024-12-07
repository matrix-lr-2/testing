#include <matrix.h>
#include <gtest/gtest.h>

TEST(matrix_addition, addition_same_type) {
    linalg::Matrix<int> mat1 = {{1, 2}, {3, 4}};
    linalg::Matrix<int> mat2 = {{5, 6}, {7, 8}};

    linalg::Matrix<int> result = mat1 + mat2;

    EXPECT_EQ(result(0, 0), 6);
    EXPECT_EQ(result(0, 1), 8);
    EXPECT_EQ(result(1, 0), 10);
    EXPECT_EQ(result(1, 1), 12);
}

TEST(matrix_addition, addition_different_type) {
    linalg::Matrix<int> mat1 = {{1, 2}, {3, 4}};
    linalg::Matrix<float> mat2 = {{5.5f, 6.5f}, {7.5f, 8.5f}};

    linalg::Matrix<float> result = mat1 + mat2;

    EXPECT_FLOAT_EQ(result(0, 0), 6.5f);
    EXPECT_FLOAT_EQ(result(0, 1), 8.5f);
    EXPECT_FLOAT_EQ(result(1, 0), 10.5f);
    EXPECT_FLOAT_EQ(result(1, 1), 12.5f);
}

TEST(matrix_addition, addition_different_size) {
    linalg::Matrix<int> mat1 = {{1, 2}, {3, 4}};
    linalg::Matrix<int> mat2 = {{5, 6}, {7, 8}, {9, 10}};

    EXPECT_THROW(mat1 += mat2, std::runtime_error);
    EXPECT_THROW(mat1 + mat2, std::runtime_error);
}

TEST(matrix_addition, addition_empty_matrix) {
    linalg::Matrix<int> mat1 = {{1, 2}, {3, 4}};
    linalg::Matrix<int> mat2; // Пустая матрица

    EXPECT_THROW(mat1 += mat2, std::runtime_error);
    EXPECT_THROW(mat1 + mat2, std::runtime_error);
}

TEST(matrix_addition, addition_result_type) {
    linalg::Matrix<int> mat1 = {{1, 2}, {3, 4}};
    linalg::Matrix<double> mat2 = {{5.5, 6.5}, {7.5, 8.5}};

    linalg::Matrix<double> result = mat1 + mat2;

    EXPECT_DOUBLE_EQ(result(0, 0), 6.5);
    EXPECT_DOUBLE_EQ(result(0, 1), 8.5);
    EXPECT_DOUBLE_EQ(result(1, 0), 10.5);
    EXPECT_DOUBLE_EQ(result(1, 1), 12.5);
}

TEST(matrix_addition, self_addition) {
    linalg::Matrix<int> mat = {{1, 2}, {3, 4}};

    mat += mat;

    EXPECT_EQ(mat(0, 0), 2);
    EXPECT_EQ(mat(0, 1), 4);
    EXPECT_EQ(mat(1, 0), 6);
    EXPECT_EQ(mat(1, 1), 8);
}

TEST(matrix_subtraction, subtraction_same_type) {
    linalg::Matrix<int> mat1 = {{5, 6}, {7, 8}};
    linalg::Matrix<int> mat2 = {{1, 2}, {3, 4}};

    linalg::Matrix<int> result = mat1 - mat2;

    EXPECT_EQ(result(0, 0), 4);
    EXPECT_EQ(result(0, 1), 4);
    EXPECT_EQ(result(1, 0), 4);
    EXPECT_EQ(result(1, 1), 4);
}

TEST(matrix_subtraction, subtraction_different_type) {
    linalg::Matrix<int> mat1 = {{5, 6}, {7, 8}};
    linalg::Matrix<double> mat2 = {{1.5, 2.5}, {3.5, 4.5}};

    linalg::Matrix<double> result = mat1 - mat2;

    EXPECT_DOUBLE_EQ(result(0, 0), 3.5);
    EXPECT_DOUBLE_EQ(result(0, 1), 3.5);
    EXPECT_DOUBLE_EQ(result(1, 0), 3.5);
    EXPECT_DOUBLE_EQ(result(1, 1), 3.5);
}

TEST(matrix_subtraction, subtraction_bool_type) {
    linalg::Matrix<bool> mat1 = {{true, false}, {true, true}};
    linalg::Matrix<bool> mat2 = {{false, true}, {true, false}};

    linalg::Matrix<int> result = mat1 - mat2;

    EXPECT_EQ(result(0, 0), 1);
    EXPECT_EQ(result(0, 1), -1);
    EXPECT_EQ(result(1, 0), 0);
    EXPECT_EQ(result(1, 1), 1);
}

TEST(matrix_subtraction, subtraction_different_size) {
    linalg::Matrix<int> mat1 = {{5, 6}, {7, 8}};
    linalg::Matrix<int> mat2 = {{1, 2}, {3, 4}, {5, 6}};

    EXPECT_THROW(mat1 -= mat2, std::runtime_error);
    EXPECT_THROW(mat1 - mat2, std::runtime_error);
}

TEST(matrix_subtraction, subtraction_empty_matrix) {
    linalg::Matrix<int> mat1 = {{5, 6}, {7, 8}};
    linalg::Matrix<int> mat2;

    EXPECT_THROW(mat1 -= mat2, std::runtime_error);
    EXPECT_THROW(mat1 - mat2, std::runtime_error);
}

TEST(matrix_subtraction, subtraction_result_type) {
    linalg::Matrix<int> mat1 = {{5, 6}, {7, 8}};
    linalg::Matrix<double> mat2 = {{1.5, 2.5}, {3.5, 4.5}};

    linalg::Matrix<double> result = mat1 - mat2;

    EXPECT_DOUBLE_EQ(result(0, 0), 3.5);
    EXPECT_DOUBLE_EQ(result(0, 1), 3.5);
    EXPECT_DOUBLE_EQ(result(1, 0), 3.5);
    EXPECT_DOUBLE_EQ(result(1, 1), 3.5);
}

TEST(matrix_subtraction, self_subtraction) {
    linalg::Matrix<int> mat = {{5, 6}, {7, 8}};

    mat -= mat;

    EXPECT_EQ(mat(0, 0), 0);
    EXPECT_EQ(mat(0, 1), 0);
    EXPECT_EQ(mat(1, 0), 0);
    EXPECT_EQ(mat(1, 1), 0);
}

TEST(matrix_multiplication, multiplication_same_type) {
    linalg::Matrix<int> mat1 = {{1, 2}, {3, 4}};
    linalg::Matrix<int> mat2 = {{5, 6}, {7, 8}};

    linalg::Matrix<int> result = mat1 * mat2;

    EXPECT_EQ(result(0, 0), 19);
    EXPECT_EQ(result(0, 1), 22);
    EXPECT_EQ(result(1, 0), 43);
    EXPECT_EQ(result(1, 1), 50);
}

TEST(matrix_multiplication, multiplication_empty_matrix) {
    linalg::Matrix<int> mat1 = {{1, 2}, {3, 4}};
    linalg::Matrix<int> mat2;

    EXPECT_THROW(mat1 *= mat2, std::runtime_error);
    EXPECT_THROW(mat1 * mat2, std::runtime_error);
}

TEST(matrix_multiplication, multiplication_dimension_mismatch) {
    linalg::Matrix<int> mat1 = {{1, 2}, {3, 4}};
    linalg::Matrix<int> mat2 = {{1, 2}};

    EXPECT_THROW(mat1 *= mat2, std::runtime_error);
    EXPECT_THROW(mat1 * mat2, std::runtime_error);
}

TEST(matrix_multiplication, self_multiplication) {
    linalg::Matrix<int> mat1 = {{1, 2}, {3, 4}};

    mat1 *= mat1;

    EXPECT_EQ(mat1(0, 0), 7);
    EXPECT_EQ(mat1(0, 1), 10);
    EXPECT_EQ(mat1(1, 0), 15);
    EXPECT_EQ(mat1(1, 1), 22);
}

TEST(matrix_multiplication, multiplication_with_bool) {
    linalg::Matrix<bool> mat1 = {{true, false}, {false, true}};
    linalg::Matrix<bool> mat2 = {{false, true}, {true, false}};

    linalg::Matrix<int> result = mat1 * mat2;

    EXPECT_EQ(result(0, 0), false);
    EXPECT_EQ(result(0, 1), true);
    EXPECT_EQ(result(1, 0), true);
    EXPECT_EQ(result(1, 1), false);
}

TEST(matrix_multiplication, multiplication_double_double) {
    linalg::Matrix<double> mat1 = {{1.5, 2.5}, {3.5, 4.5}};
    linalg::Matrix<double> mat2 = {{5.5, 6.5}, {7.5, 8.5}};

    mat1 *= mat2;

    EXPECT_DOUBLE_EQ(mat1(0, 0), 27.0);
    EXPECT_DOUBLE_EQ(mat1(0, 1), 31.0);
    EXPECT_DOUBLE_EQ(mat1(1, 0), 53.0);
    EXPECT_DOUBLE_EQ(mat1(1, 1), 61.0);
}

TEST(matrix_multiplication, multiplication_double_int) {
    linalg::Matrix<double> mat1 = {{1.5, 2.5}, {3.5, 4.5}};
    linalg::Matrix<int> mat2 = {{5, 6}, {7, 8}};

    mat1 *= mat2;

    EXPECT_DOUBLE_EQ(mat1(0, 0), 25.0);
    EXPECT_DOUBLE_EQ(mat1(0, 1), 29.0);
    EXPECT_DOUBLE_EQ(mat1(1, 0), 49.0);
    EXPECT_DOUBLE_EQ(mat1(1, 1), 57.0);
}

TEST(matrix_multiplication, multiplication_double_multiple) {
    linalg::Matrix<double> mat1 = {{1.5, 2.5}, {3.5, 4.5}};
    linalg::Matrix<double> mat2 = {{5.5, 6.5}, {7.5, 8.5}};
    linalg::Matrix<int> mat3 = {{1, 2}, {3, 4}};

    mat1 *= mat2;
    mat1 *= mat3;

    EXPECT_DOUBLE_EQ(mat1(0, 0), 120.0);
    EXPECT_DOUBLE_EQ(mat1(0, 1), 178.0);
    EXPECT_DOUBLE_EQ(mat1(1, 0), 236.0);
    EXPECT_DOUBLE_EQ(mat1(1, 1), 350.0);
}

TEST(matrix_scalar_multiplication, multiplication_by_double) {
    linalg::Matrix<int> mat = {{1, 2}, {3, 4}};
    double scalar = 2.5;

    auto result = mat * scalar;

    EXPECT_DOUBLE_EQ(result(0, 0), 2.5);
    EXPECT_DOUBLE_EQ(result(0, 1), 5.0);
    EXPECT_DOUBLE_EQ(result(1, 0), 7.5);
    EXPECT_DOUBLE_EQ(result(1, 1), 10.0);
}

TEST(matrix_scalar_multiplication, multiplication_by_double_in_place) {
    linalg::Matrix<int> mat = {{1, 2}, {3, 4}};
    double scalar = 2.5;

    mat *= scalar;

    EXPECT_DOUBLE_EQ(mat(0, 0), 2);
    EXPECT_DOUBLE_EQ(mat(0, 1), 5);
    EXPECT_DOUBLE_EQ(mat(1, 0), 7);
    EXPECT_DOUBLE_EQ(mat(1, 1), 10);
}

TEST(matrix_scalar_multiplication, multiplication_by_int) {
    linalg::Matrix<double> mat = {{1.5, 2.5}, {3.5, 4.5}};
    int scalar = 2;

    auto result = mat * scalar;

    EXPECT_DOUBLE_EQ(result(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(result(0, 1), 5.0);
    EXPECT_DOUBLE_EQ(result(1, 0), 7.0);
    EXPECT_DOUBLE_EQ(result(1, 1), 9.0);
}

TEST(matrix_scalar_multiplication, multiplication_by_int_2) {
    linalg::Matrix<double> mat = {{1.5, 2.5}, {3.5, 4.5}};
    int scalar = 2;

    auto result = scalar * mat;

    EXPECT_DOUBLE_EQ(result(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(result(0, 1), 5.0);
    EXPECT_DOUBLE_EQ(result(1, 0), 7.0);
    EXPECT_DOUBLE_EQ(result(1, 1), 9.0);
}

TEST(matrix_scalar_multiplication, multiplication_by_int_in_place) {
    linalg::Matrix<double> mat = {{1.5, 2.5}, {3.5, 4.5}};
    int scalar = 2;

    mat *= scalar;

    EXPECT_DOUBLE_EQ(mat(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(mat(0, 1), 5.0);
    EXPECT_DOUBLE_EQ(mat(1, 0), 7.0);
    EXPECT_DOUBLE_EQ(mat(1, 1), 9.0);
}

TEST(matrix_scalar_multiplication, multiplication_by_zero) {
    linalg::Matrix<int> mat = {{1, 2}, {3, 4}};
    int scalar = 0;

    auto result = mat * scalar;

    EXPECT_EQ(result(0, 0), 0);
    EXPECT_EQ(result(0, 1), 0);
    EXPECT_EQ(result(1, 0), 0);
    EXPECT_EQ(result(1, 1), 0);
}

TEST(matrix_scalar_multiplication, multiplication_by_zero_in_place) {
    linalg::Matrix<int> mat = {{1, 2}, {3, 4}};
    int scalar = 0;

    mat *= scalar;

    EXPECT_EQ(mat(0, 0), 0);
    EXPECT_EQ(mat(0, 1), 0);
    EXPECT_EQ(mat(1, 0), 0);
    EXPECT_EQ(mat(1, 1), 0);
}

TEST(matrix_scalar_multiplication, multiplication_by_negative) {
    linalg::Matrix<int> mat = {{1, -2}, {3, -4}};
    int scalar = -3;

    auto result = mat * scalar;

    EXPECT_EQ(result(0, 0), -3);
    EXPECT_EQ(result(0, 1), 6);
    EXPECT_EQ(result(1, 0), -9);
    EXPECT_EQ(result(1, 1), 12);
}

TEST(matrix_scalar_multiplication, multiplication_by_negative_in_place) {
    linalg::Matrix<int> mat = {{1, -2}, {3, -4}};
    int scalar = -3;

    mat *= scalar;

    EXPECT_EQ(mat(0, 0), -3);
    EXPECT_EQ(mat(0, 1), 6);
    EXPECT_EQ(mat(1, 0), -9);
    EXPECT_EQ(mat(1, 1), 12);
}