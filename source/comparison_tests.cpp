#include <matrix.h>
#include <gtest/gtest.h>

TEST(comparison_operator_test, float_and_double_comparison) {
    linalg::Matrix<float> mat1 = {{1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}};
    linalg::Matrix<double> mat2 = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    linalg::Matrix<float> mat3 = {{1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.1f}};

    EXPECT_TRUE(mat1 == mat2);
    EXPECT_FALSE(mat1 == mat3);
    EXPECT_FALSE(mat1 != mat2);
    EXPECT_TRUE(mat1 != mat3);
}

TEST(comparison_operator_test, long_double_comparison) {
    linalg::Matrix<double> mat1 = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    linalg::Matrix<long double> mat2 = {{1.0L, 2.0L, 3.0L}, {4.0L, 5.0L, 6.0L}};
    linalg::Matrix<long double> mat3 = {{1.0L, 2.0L, 3.0L}, {4.0L, 5.0L, 6.0000001L}};

    EXPECT_TRUE(mat1 == mat2);
    EXPECT_FALSE(mat1 == mat3);
    EXPECT_FALSE(mat1 != mat2);
    EXPECT_TRUE(mat1 != mat3);
}

TEST(comparison_operator_test, integer_comparison) {
    linalg::Matrix<int> mat1 = {{1, 2, 3}, {4, 5, 6}};
    linalg::Matrix<int> mat2 = {{1, 2, 3}, {4, 5, 6}};
    linalg::Matrix<int> mat3 = {{1, 2, 3}, {4, 5, 7}};

    EXPECT_TRUE(mat1 == mat2);
    EXPECT_FALSE(mat1 == mat3);
    EXPECT_FALSE(mat1 != mat2);
    EXPECT_TRUE(mat1 != mat3);
}

TEST(comparison_operator_test, mixed_type_comparison) {
    linalg::Matrix<int> mat1 = {{1, 2, 3}, {4, 5, 6}};
    linalg::Matrix<float> mat2 = {{1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}};
    linalg::Matrix<double> mat3 = {{1.0, 2.0, 3.0}, {4.0, 5.0, 7.0}};

    EXPECT_TRUE(mat1 == mat2);
    EXPECT_FALSE(mat1 == mat3);
    EXPECT_FALSE(mat1 != mat2);
    EXPECT_TRUE(mat1 != mat3);
}

TEST(comparison_operator_test, empty_matrix_comparison) {
    linalg::Matrix<int> mat1;
    linalg::Matrix<int> mat2;
    linalg::Matrix<double> mat3;

    EXPECT_TRUE(mat1 == mat2);
    EXPECT_TRUE(mat1 == mat3);
    EXPECT_FALSE(mat1 != mat2);
    EXPECT_FALSE(mat1 != mat3);
}

TEST(comparison_operator_test, self_comparison) {
    linalg::Matrix<float> mat = {{1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}};

    EXPECT_TRUE(mat == mat);
    EXPECT_FALSE(mat != mat);
}

TEST(comparison_operator_test, different_size_comparison) {
    linalg::Matrix<int> mat1 = {{1, 2, 3}, {4, 5, 6}};
    linalg::Matrix<int> mat2 = {{1, 2}, {3, 4}, {5, 6}};

    EXPECT_FALSE(mat1 == mat2);
    EXPECT_TRUE(mat1 != mat2);
}