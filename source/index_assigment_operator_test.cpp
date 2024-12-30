#include <matrix.h>
#include <gtest/gtest.h>

TEST(copy_assignment, one_type) {
    linalg::Matrix<int> mat1(2, 3);
    mat1(0, 0) = 1;
    mat1(0, 1) = 2;
    mat1(0, 2) = 3;
    linalg::Matrix<int> mat2;
    mat2 = mat1;
    EXPECT_EQ(mat2(0, 0), 1);
    EXPECT_EQ(mat2(0, 1), 2);
    EXPECT_EQ(mat2(0, 2), 3);
    EXPECT_EQ(mat2.rows(), 2);
    EXPECT_EQ(mat2.columns(), 3);
    EXPECT_EQ(mat2.capacity(), 6);
    EXPECT_EQ(mat2.size(), 6);
    EXPECT_FALSE(mat2.empty());
    linalg::Matrix<int> mat4(2,5);
    mat4 = mat1;
    EXPECT_EQ(mat4(0, 0), 1);
    EXPECT_EQ(mat4(0, 1), 2);
    EXPECT_EQ(mat4(0, 2), 3);
    EXPECT_EQ(mat4.rows(), 2);
    EXPECT_EQ(mat4.columns(), 3);
    EXPECT_EQ(mat4.capacity(), 10);
    EXPECT_EQ(mat4.size(), 6);
    EXPECT_FALSE(mat4.empty());
    linalg::Matrix<int> mat5 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    mat5 = mat1;
    EXPECT_EQ(mat5(0, 0), 1);
    EXPECT_EQ(mat5(0, 1), 2);
    EXPECT_EQ(mat5(0, 2), 3);
    EXPECT_EQ(mat5.rows(), 2);
    EXPECT_EQ(mat5.columns(), 3);
    EXPECT_EQ(mat5.capacity(), 9);
    EXPECT_EQ(mat5.size(), 6);
    EXPECT_FALSE(mat5.empty());
    linalg::Matrix<int> mat;
    mat1 = mat; // NOLINT(*-unnecessary-copy-initialization)
    EXPECT_EQ(mat1.rows(), 0);
    EXPECT_EQ(mat1.columns(), 0);
    EXPECT_EQ(mat1.size(), 0);
    EXPECT_EQ(mat1.capacity(), 6);
    EXPECT_TRUE(mat1.empty());
    mat2 = mat2;
    EXPECT_EQ(mat2.rows(), 2);
    EXPECT_EQ(mat2.columns(), 3);
    EXPECT_EQ(mat2.size(), 6);
    EXPECT_EQ(mat2.capacity(), 6);
    EXPECT_FALSE(mat2.empty());
}

TEST(copy_assignment, different_types_1) {
    linalg::Matrix<double> mat1(2, 3);
    mat1(0, 0) = 1;
    mat1(0, 1) = 2;
    mat1(0, 2) = 3;
    linalg::Matrix<int> mat2;
    mat2 = mat1;
    EXPECT_EQ(mat2(0, 0), 1);
    EXPECT_EQ(mat2(0, 1), 2);
    EXPECT_EQ(mat2(0, 2), 3);
    EXPECT_EQ(mat2.rows(), 2);
    EXPECT_EQ(mat2.columns(), 3);
    EXPECT_EQ(mat2.capacity(), 6);
    EXPECT_EQ(mat2.size(), 6);
    EXPECT_FALSE(mat2.empty());
    linalg::Matrix<int> mat4(2,5);
    mat4 = mat1;
    EXPECT_EQ(mat4(0, 0), 1);
    EXPECT_EQ(mat4(0, 1), 2);
    EXPECT_EQ(mat4(0, 2), 3);
    EXPECT_EQ(mat4.rows(), 2);
    EXPECT_EQ(mat4.columns(), 3);
    EXPECT_EQ(mat4.capacity(), 10);
    EXPECT_EQ(mat4.size(), 6);
    EXPECT_FALSE(mat4.empty());
    linalg::Matrix<int> mat5 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    mat5 = mat1;
    EXPECT_EQ(mat5(0, 0), 1);
    EXPECT_EQ(mat5(0, 1), 2);
    EXPECT_EQ(mat5(0, 2), 3);
    EXPECT_EQ(mat5.rows(), 2);
    EXPECT_EQ(mat5.columns(), 3);
    EXPECT_EQ(mat5.capacity(), 9);
    EXPECT_EQ(mat5.size(), 6);
    EXPECT_FALSE(mat5.empty());
    linalg::Matrix<int> mat;
    mat1 = mat; // NOLINT(*-unnecessary-copy-initialization)
    EXPECT_EQ(mat1.rows(), 0);
    EXPECT_EQ(mat1.columns(), 0);
    EXPECT_EQ(mat1.size(), 0);
    EXPECT_EQ(mat1.capacity(), 6);
    EXPECT_TRUE(mat1.empty());
    mat2 = mat2;
    EXPECT_EQ(mat2.rows(), 2);
    EXPECT_EQ(mat2.columns(), 3);
    EXPECT_EQ(mat2.size(), 6);
    EXPECT_EQ(mat2.capacity(), 6);
    EXPECT_FALSE(mat2.empty());
}

TEST(copy_assignment, different_types_2) {
    linalg::Matrix<int> mat1(2, 3);
    mat1(0, 0) = 1;
    mat1(0, 1) = 2;
    mat1(0, 2) = 3;
    linalg::Matrix<double> mat2;
    mat2 = mat1;
    EXPECT_EQ(mat2(0, 0), 1);
    EXPECT_EQ(mat2(0, 1), 2);
    EXPECT_EQ(mat2(0, 2), 3);
    EXPECT_EQ(mat2.rows(), 2);
    EXPECT_EQ(mat2.columns(), 3);
    EXPECT_EQ(mat2.capacity(), 6);
    EXPECT_EQ(mat2.size(), 6);
    EXPECT_FALSE(mat2.empty());
    linalg::Matrix<double> mat4(2,5);
    mat4 = mat1;
    EXPECT_EQ(mat4(0, 0), 1);
    EXPECT_EQ(mat4(0, 1), 2);
    EXPECT_EQ(mat4(0, 2), 3);
    EXPECT_EQ(mat4.rows(), 2);
    EXPECT_EQ(mat4.columns(), 3);
    EXPECT_EQ(mat4.capacity(), 10);
    EXPECT_EQ(mat4.size(), 6);
    EXPECT_FALSE(mat4.empty());
    linalg::Matrix<double> mat5 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    mat5 = mat1;
    EXPECT_EQ(mat5(0, 0), 1);
    EXPECT_EQ(mat5(0, 1), 2);
    EXPECT_EQ(mat5(0, 2), 3);
    EXPECT_EQ(mat5.rows(), 2);
    EXPECT_EQ(mat5.columns(), 3);
    EXPECT_EQ(mat5.capacity(), 9);
    EXPECT_EQ(mat5.size(), 6);
    EXPECT_FALSE(mat5.empty());
    linalg::Matrix<double> mat;
    mat1 = mat; // NOLINT(*-unnecessary-copy-initialization)
    EXPECT_EQ(mat1.rows(), 0);
    EXPECT_EQ(mat1.columns(), 0);
    EXPECT_EQ(mat1.size(), 0);
    EXPECT_EQ(mat1.capacity(), 6);
    EXPECT_TRUE(mat1.empty());
    mat2 = mat2;
    EXPECT_EQ(mat2.rows(), 2);
    EXPECT_EQ(mat2.columns(), 3);
    EXPECT_EQ(mat2.size(), 6);
    EXPECT_EQ(mat2.capacity(), 6);
    EXPECT_FALSE(mat2.empty());
}

TEST(move_assignment, basic_move) {
    linalg::Matrix<int> mat1(2, 3);
    mat1(0, 0) = 1;
    mat1(0, 1) = 2;
    mat1(0, 2) = 3;
    mat1(1, 0) = 4;
    mat1(1, 1) = 5;
    mat1(1, 2) = 6;
    linalg::Matrix<int> mat2;
    mat2 = std::move(mat1);
    EXPECT_EQ(mat2.rows(), 2);
    EXPECT_EQ(mat2.columns(), 3);
    EXPECT_EQ(mat2(0, 0), 1);
    EXPECT_EQ(mat2(0, 1), 2);
    EXPECT_EQ(mat2(0, 2), 3);
    EXPECT_EQ(mat2(1, 0), 4);
    EXPECT_EQ(mat2(1, 1), 5);
    EXPECT_EQ(mat2(1, 2), 6);
    EXPECT_EQ(mat1.rows(), 0);
    EXPECT_EQ(mat1.columns(), 0);
    EXPECT_TRUE(mat1.empty());
}

TEST(move_assignment, self_move) {
    linalg::Matrix<int> mat(2, 3);
    mat(0, 0) = 1;
    mat(1, 2) = 42;
    mat = std::move(mat);
    EXPECT_EQ(mat.rows(), 2);
    EXPECT_EQ(mat.columns(), 3);
    EXPECT_EQ(mat(0, 0), 1);
    EXPECT_EQ(mat(1, 2), 42);
}

TEST(move_assignment, move_from_empty) {
    linalg::Matrix<int> mat1;
    linalg::Matrix<int> mat2(2, 3);
    mat2 = std::move(mat1);
    EXPECT_EQ(mat2.rows(), 0);
    EXPECT_EQ(mat2.columns(), 0);
    EXPECT_TRUE(mat2.empty());
}

TEST(move_assignment, move_to_empty) {
    linalg::Matrix<int> mat1(2, 3);
    mat1(0, 0) = 1;
    mat1(0, 1) = 2;
    linalg::Matrix<int> mat2;
    mat2 = std::move(mat1);
    EXPECT_EQ(mat2.rows(), 2);
    EXPECT_EQ(mat2.columns(), 3);
    EXPECT_EQ(mat2(0, 0), 1);
    EXPECT_EQ(mat2(0, 1), 2);
    EXPECT_EQ(mat1.rows(), 0);
    EXPECT_EQ(mat1.columns(), 0);
    EXPECT_TRUE(mat1.empty());
}

class matrix_index_test : public ::testing::Test {
protected:
    linalg::Matrix<int> m1 = {{1, 2, 3}, {4, 5, 6}};
    linalg::Matrix<double> m2 = {{1.5, 2.2, 3.3}, {4.0, 5.4, 6.3}};
    linalg::Matrix<bool> m;
};

TEST_F(matrix_index_test, index_one_param) {
    EXPECT_EQ(m1(0), 1);
    EXPECT_EQ(m1(1), 2);
    EXPECT_THROW(m1(1000), std::runtime_error);
    EXPECT_EQ(m2(0), 1.5);
    EXPECT_EQ(m2(1), 2.2);
    EXPECT_THROW(m2(1000), std::runtime_error);
    EXPECT_THROW(m(0), std::runtime_error);
}

TEST_F(matrix_index_test, two_one_param) {
    EXPECT_EQ(m1(0, 0), 1);
    EXPECT_EQ(m1(0, 1), 2);
    EXPECT_THROW(m1(1000, 12), std::runtime_error);
    EXPECT_EQ(m2(0, 0), 1.5);
    EXPECT_EQ(m2(0, 1), 2.2);
    EXPECT_THROW(m2(1000, 12), std::runtime_error);
    EXPECT_THROW(m(0, 0), std::runtime_error);
}

TEST_F(matrix_index_test, squared_brackets) {
    EXPECT_EQ(m1[0][0], 1);
    EXPECT_EQ(m1[0][1], 2);
    EXPECT_EQ(m2[0][0], 1.5);
    EXPECT_EQ(m2[0][1], 2.2);
    EXPECT_THROW(m2[1000][12], std::runtime_error);
    EXPECT_THROW(m1[1000][12], std::runtime_error);
    EXPECT_THROW(m[0][0], std::runtime_error);
}

TEST(begin_end, non_empty_matrix) {
    linalg::Matrix<int> mat(2, 3);
    int value = 1;
    for (int i = 0; i < mat.rows(); ++i) {
        for (int j = 0; j < mat.columns(); ++j) {
            mat(i, j) = value++;
        }
    }
    EXPECT_EQ(mat.begin(), &mat(0, 0));
    EXPECT_EQ(mat.end(), &mat(0, 0) + mat.rows() * mat.columns());
    int expected_value = 1;
    for (auto& element : mat) {
        EXPECT_EQ(element, expected_value++);
    }
}

TEST(begin_end, empty_matrix) {
    linalg::Matrix<int> mat;
    EXPECT_EQ(mat.begin(), mat.end());
    EXPECT_TRUE(mat.empty());
}

TEST(begin_end, const_matrix) {
    linalg::Matrix<int> mat(2, 2);
    mat(0, 0) = 42;
    mat(0, 1) = 43;
    mat(1, 0) = 44;
    mat(1, 1) = 45;
    const linalg::Matrix<int> const_mat = mat;
    EXPECT_EQ(const_mat.begin(), &const_mat(0, 0));
    EXPECT_EQ(const_mat.end(), &const_mat(0, 0) + const_mat.rows() * const_mat.columns());
    int expected_values[] = {42, 43, 44, 45};
    int i = 0;
    for (const auto& element : const_mat) {
        EXPECT_EQ(element, expected_values[i++]);
    }
}