#include <matrix.h>
#include <gtest/gtest.h>

TEST(rows_matrix, get_rows) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_EQ(mat.rows(), 2);
}

TEST(columns_matrix, get_columns) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_EQ(mat.columns(), 3);
}

TEST(capacity_matrix, get_capacity) {
    linalg::Matrix<int> mat = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_EQ(mat.capacity(), 6);
}

TEST(size_matrix, get_size) {
    linalg::Matrix<int> mat = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_EQ(mat.size(), 6);
}

TEST(empty_matrix, check_empty) {
    linalg::Matrix<int> mat;
    EXPECT_TRUE(mat.empty());
    linalg::Matrix<int> mat2 = {{1, 2}, {3, 4}};
    EXPECT_FALSE(mat2.empty());
}

TEST(swap_matrix, swap_matrices_method) {
    linalg::Matrix<int> mat1 = {{1, 2}, {3, 4}};
    linalg::Matrix<int> mat2 = {{5, 6}, {7, 8}, {4, 5}};
    mat1.swap(mat2);
    linalg::Matrix<int> expected1 = {{5, 6}, {7, 8}, {4, 5}};
    linalg::Matrix<int> expected2 = {{1, 2}, {3, 4}};
    EXPECT_EQ(mat1, expected1);
    EXPECT_EQ(mat2, expected2);
    EXPECT_EQ(mat2.size(), 4);
    EXPECT_EQ(mat2.capacity(), 4);
}

TEST(swap_matrix, swap_matrices) {
    linalg::Matrix<int> mat1 = {{1, 2}, {3, 4}};
    linalg::Matrix<int> mat2 = {{5, 6}, {7, 8}, {4, 5}};
    swap(mat1, mat2);
    linalg::Matrix<int> expected1 = {{5, 6}, {7, 8}, {4, 5}};
    linalg::Matrix<int> expected2 = {{1, 2}, {3, 4}};
    EXPECT_EQ(mat1, expected1);
    EXPECT_EQ(mat2, expected2);
    EXPECT_EQ(mat2.size(), 4);
    EXPECT_EQ(mat2.capacity(), 4);
}

TEST(swap_rows_matrix, swap_rows) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    mat.swap_rows(0, 2);
    linalg::Matrix<int> expected = {{7, 8, 9}, {4, 5, 6}, {1, 2, 3}};
    EXPECT_EQ(mat, expected);
}

TEST(swap_columns_matrix, swap_columns) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    mat.swap_columns(0, 2);
    linalg::Matrix<int> expected = {{3, 2, 1}, {6, 5, 4}, {9, 8, 7}};
    EXPECT_EQ(mat, expected);
}

TEST(swap_rows_matrix, swap_rows_2) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    mat.swap_rows(0, 2);
    EXPECT_EQ(mat(0, 0), 7);
    EXPECT_EQ(mat(0, 1), 8);
    EXPECT_EQ(mat(0, 2), 9);
    EXPECT_EQ(mat(2, 0), 1);
    EXPECT_EQ(mat(2, 1), 2);
    EXPECT_EQ(mat(2, 2), 3);

    EXPECT_THROW(mat.swap_rows(0, 3), std::runtime_error);
    EXPECT_THROW(mat.swap_rows(3, 1), std::runtime_error);
}

TEST(swap_columns_matrix, swap_columns_2) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    mat.swap_columns(0, 2);
    EXPECT_EQ(mat(0, 0), 3);
    EXPECT_EQ(mat(0, 2), 1);
    EXPECT_EQ(mat(1, 0), 6);
    EXPECT_EQ(mat(1, 2), 4);
    EXPECT_EQ(mat(2, 0), 9);
    EXPECT_EQ(mat(2, 2), 7);

    EXPECT_THROW(mat.swap_columns(0, 3), std::runtime_error);
    EXPECT_THROW(mat.swap_columns(3, 1), std::runtime_error);
}

TEST(swap_rows_empty_matrix, swap_rows_empty) {
    linalg::Matrix<int> mat;
    EXPECT_THROW(mat.swap_rows(0, 1), std::runtime_error);
}

TEST(swap_columns_empty_matrix, swap_columns_empty) {
    linalg::Matrix<int> mat;
    EXPECT_THROW(mat.swap_columns(0, 1), std::runtime_error);
}

TEST(capacity_test, capacity_less) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {5, 6, 7}};
    linalg::Matrix<int> mat2 = {{1, 2, 3}, {5, 6, 7}};
    mat.reserve(5);
    EXPECT_EQ(mat.capacity(), 6);
    EXPECT_TRUE(mat == mat2);
}

TEST(capacity_test, capacity_less_2) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {5, 6, 7}, {1, 0, -1}};
    linalg::Matrix<int> mat2 = {{1, 2, 3}, {5, 6, 7}, {1, 0, -1}};
    mat.reserve(6);
    EXPECT_EQ(mat.capacity(), 9);
    EXPECT_TRUE(mat == mat2);
}

TEST(capacity_test, capacity_the_same) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {5, 6, 7}};
    linalg::Matrix<int> mat2 = {{1, 2, 3}, {5, 6, 7}};
    mat.reserve(6);
    EXPECT_TRUE(mat == mat2);
    EXPECT_EQ(mat.capacity(), 6);
}

TEST(capacity_test, capacity_bigger) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {5, 6, 7}};
    linalg::Matrix<int> mat2 = {{1, 2, 3}, {5, 6, 7}};
    mat.reserve(100);
    EXPECT_TRUE(mat == mat2);
    EXPECT_EQ(mat.capacity(), 100);
    EXPECT_EQ(mat.size(), 6);
    EXPECT_EQ(mat.rows(), 2);
    EXPECT_EQ(mat.columns(), 3);
}

TEST(clear, clear) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {5, 6, 7}};
    mat.clear();
    EXPECT_EQ(mat.capacity(), 6);
    EXPECT_EQ(mat.size(), 0);
    EXPECT_EQ(mat.rows(), 0);
    EXPECT_EQ(mat.columns(), 0);
    linalg::Matrix<int> mat2;
    mat2.clear();
    EXPECT_EQ(mat2.capacity(), 0);
    EXPECT_EQ(mat2.size(), 0);
    EXPECT_EQ(mat2.rows(), 0);
    EXPECT_EQ(mat2.columns(), 0);
}

TEST(shrink_to_fit, bigger_to_smaller) {
    linalg::Matrix<int> mat(100);
    linalg::Matrix<short> mat2 = {{1, 2, 3}, {0, 0, 0}, {52, 52, 52}};
    mat = mat2;
    EXPECT_EQ(mat.capacity(), 100);
    EXPECT_EQ(mat.size(), 9);
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 3);
    mat.shrink_to_fit();
    EXPECT_EQ(mat.capacity(), 9);
    EXPECT_EQ(mat.size(), 9);
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 3);
}

TEST(shrink_to_fit, equal) {
    linalg::Matrix<short> mat = {{1, 2, 3}, {0, 0, 0}, {52, 52, 52}};
    mat.shrink_to_fit();
    EXPECT_EQ(mat.capacity(), 9);
    EXPECT_EQ(mat.size(), 9);
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 3);
}

TEST(reshape_matrix, increase_size) {
    linalg::Matrix<int> mat(2, 2);
    mat(0, 0) = 1;
    mat(0, 1) = 2;
    mat(1, 0) = 3;
    mat(1, 1) = 4;
    mat.reshape(3, 3);
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 3);
    EXPECT_EQ(mat(0, 0), 1);
    EXPECT_EQ(mat(0, 1), 2);
    EXPECT_EQ(mat(0, 2), 0);
    EXPECT_EQ(mat(1, 0), 3);
    EXPECT_EQ(mat(1, 1), 4);
    EXPECT_EQ(mat(1, 2), 0);
    EXPECT_EQ(mat(2, 0), 0);
    EXPECT_EQ(mat(2, 1), 0);
    EXPECT_EQ(mat(2, 2), 0);
}

TEST(reshape_matrix, decrease_size) {
    linalg::Matrix<int> mat(3, 3);
    mat(0, 0) = 1;
    mat(0, 1) = 2;
    mat(0, 2) = 3;
    mat(1, 0) = 4;
    mat(1, 1) = 5;
    mat(1, 2) = 6;
    mat(2, 0) = 7;
    mat(2, 1) = 8;
    mat(2, 2) = 9;
    mat.reshape(2, 2);
    EXPECT_EQ(mat.rows(), 2);
    EXPECT_EQ(mat.columns(), 2);
    EXPECT_EQ(mat(0, 0), 1);
    EXPECT_EQ(mat(0, 1), 2);
    EXPECT_EQ(mat(1, 0), 3);
    EXPECT_EQ(mat(1, 1), 4);
}

TEST(reshape_matrix, same_size) {
    linalg::Matrix<int> mat(3, 3);
    mat(0, 0) = 1;
    mat(0, 1) = 2;
    mat(0, 2) = 3;
    mat(1, 0) = 4;
    mat(1, 1) = 5;
    mat(1, 2) = 6;
    mat(2, 0) = 7;
    mat(2, 1) = 8;
    mat(2, 2) = 9;
    mat.reshape(3, 3);
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 3);
    EXPECT_EQ(mat(0, 0), 1);
    EXPECT_EQ(mat(0, 1), 2);
    EXPECT_EQ(mat(0, 2), 3);
    EXPECT_EQ(mat(1, 0), 4);
    EXPECT_EQ(mat(1, 1), 5);
    EXPECT_EQ(mat(1, 2), 6);
    EXPECT_EQ(mat(2, 0), 7);
    EXPECT_EQ(mat(2, 1), 8);
    EXPECT_EQ(mat(2, 2), 9);
}

TEST(reshape_matrix, shrink_to_single_element) {
    linalg::Matrix<int> mat(3, 3);
    mat(0, 0) = 1;
    mat(0, 1) = 2;
    mat(0, 2) = 3;
    mat(1, 0) = 4;
    mat(1, 1) = 5;
    mat(1, 2) = 6;
    mat(2, 0) = 7;
    mat(2, 1) = 8;
    mat(2, 2) = 9;
    mat.reshape(1, 1);
    EXPECT_EQ(mat.rows(), 1);
    EXPECT_EQ(mat.columns(), 1);
    EXPECT_EQ(mat(0, 0), 1);
}

TEST(reshape_matrix, expand_with_default_values) {
    linalg::Matrix<int> mat(2, 2);
    mat(0, 0) = 1;
    mat(0, 1) = 2;
    mat(1, 0) = 3;
    mat(1, 1) = 4;
    mat.reshape(3, 4);
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 4);
    EXPECT_EQ(mat(0, 0), 1);
    EXPECT_EQ(mat(0, 1), 2);
    EXPECT_EQ(mat(0, 2), 0);
    EXPECT_EQ(mat(0, 3), 0);
    EXPECT_EQ(mat(1, 0), 3);
    EXPECT_EQ(mat(1, 1), 4);
    EXPECT_EQ(mat(1, 2), 0);
    EXPECT_EQ(mat(1, 3), 0);
    EXPECT_EQ(mat(2, 0), 0);
    EXPECT_EQ(mat(2, 1), 0);
    EXPECT_EQ(mat(2, 2), 0);
    EXPECT_EQ(mat(2, 3), 0);
}

TEST(reshape_matrix, reshape_to_clear) {
    linalg::Matrix<int> mat(2, 2);
    mat(0, 0) = 1;
    mat(0, 1) = 2;
    mat(1, 0) = 3;
    mat(1, 1) = 4;
    mat.reshape(0, 0);
    EXPECT_EQ(mat.rows(), 0);
    EXPECT_EQ(mat.columns(), 0);
    EXPECT_EQ(mat.capacity(), 4);
    linalg::Matrix<int> mat2(2, 2);
    mat2(0, 0) = 1;
    mat2(0, 1) = 2;
    mat2(1, 0) = 3;
    mat2(1, 1) = 4;
    mat2.reshape(0, 2);
    EXPECT_EQ(mat2.rows(), 0);
    EXPECT_EQ(mat2.columns(), 0);
    EXPECT_EQ(mat2.capacity(), 4);
    linalg::Matrix<int> mat3(2, 2);
    mat3(0, 0) = 1;
    mat3(0, 1) = 2;
    mat3(1, 0) = 3;
    mat3(1, 1) = 4;
    mat3.reshape(3, 0);
    EXPECT_EQ(mat3.rows(), 0);
    EXPECT_EQ(mat3.columns(), 0);
    EXPECT_EQ(mat3.capacity(), 4);
}