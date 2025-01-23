#include <matrix.h>
#include <gtest/gtest.h>

TEST(default_constructor, constructor_int) {
    linalg::Matrix<int> mat;
    EXPECT_EQ(mat.rows(), 0);
    EXPECT_EQ(mat.columns(), 0);
    EXPECT_EQ(mat.capacity(), 0);
    EXPECT_EQ(mat.size(), 0);
    EXPECT_TRUE(mat.empty());
}

TEST(default_constructor, constructor_double) {
    linalg::Matrix<double> mat;
    EXPECT_EQ(mat.rows(), 0);
    EXPECT_EQ(mat.columns(), 0);
    EXPECT_EQ(mat.capacity(), 0);
    EXPECT_EQ(mat.size(), 0);
    EXPECT_TRUE(mat.empty());
}

TEST(default_constructor, constructor_bool) {
    linalg::Matrix<bool> mat;
    EXPECT_EQ(mat.rows(), 0);
    EXPECT_EQ(mat.columns(), 0);
    EXPECT_EQ(mat.capacity(), 0);
    EXPECT_EQ(mat.size(), 0);
    EXPECT_TRUE(mat.empty());
}

TEST(one_parameter_constructor, constructor_int) {
    linalg::Matrix<int> mat(5);
    EXPECT_EQ(mat.rows(), 5);
    EXPECT_EQ(mat.columns(), 1);
    EXPECT_EQ(mat.capacity(), 5);
    EXPECT_EQ(mat.size(), 5);
    EXPECT_FALSE(mat.empty());
    linalg::Matrix<int> mat2(0);
    EXPECT_EQ(mat2.rows(), 0);
    EXPECT_EQ(mat2.columns(), 0);
    EXPECT_EQ(mat2.capacity(), 0);
    EXPECT_EQ(mat2.size(), 0);
    EXPECT_TRUE(mat2.empty());
}

TEST(one_parameter_constructor, constructor_double) {
    linalg::Matrix<double> mat(5);
    EXPECT_EQ(mat.rows(), 5);
    EXPECT_EQ(mat.columns(), 1);
    EXPECT_EQ(mat.capacity(), 5);
    EXPECT_EQ(mat.size(), 5);
    EXPECT_FALSE(mat.empty());
    linalg::Matrix<double> mat2(0);
    EXPECT_EQ(mat2.rows(), 0);
    EXPECT_EQ(mat2.columns(), 0);
    EXPECT_EQ(mat2.capacity(), 0);
    EXPECT_EQ(mat2.size(), 0);
    EXPECT_TRUE(mat2.empty());
}

TEST(one_parameter_constructor, constructor_bool) {
    linalg::Matrix<bool> mat(5);
    EXPECT_EQ(mat.rows(), 5);
    EXPECT_EQ(mat.columns(), 1);
    EXPECT_EQ(mat.capacity(), 5);
    EXPECT_EQ(mat.size(), 5);
    EXPECT_FALSE(mat.empty());
    linalg::Matrix<bool> mat2(0);
    EXPECT_EQ(mat2.rows(), 0);
    EXPECT_EQ(mat2.columns(), 0);
    EXPECT_EQ(mat2.capacity(), 0);
    EXPECT_EQ(mat2.size(), 0);
    EXPECT_TRUE(mat2.empty());
}

TEST(two_parameter_constructor, constructor_int) {
    linalg::Matrix<int> mat(3, 4);
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 4);
    EXPECT_EQ(mat.size(), 12);
    EXPECT_EQ(mat.capacity(), 12);
    EXPECT_FALSE(mat.empty());
    linalg::Matrix<int> mat2(0, 0);
    EXPECT_TRUE(mat2.empty());
}

TEST(two_parameter_constructor, constructor_double) {
    linalg::Matrix<double> mat(3, 4);
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 4);
    EXPECT_EQ(mat.size(), 12);
    EXPECT_EQ(mat.capacity(), 12);
    EXPECT_FALSE(mat.empty());
    linalg::Matrix<double> mat2(0, 0);
    EXPECT_TRUE(mat2.empty());
}

TEST(two_parameter_constructor, constructor_bool) {
    linalg::Matrix<bool> mat(3, 4);
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 4);
    EXPECT_EQ(mat.size(), 12);
    EXPECT_EQ(mat.capacity(), 12);
    EXPECT_FALSE(mat.empty());
    linalg::Matrix<bool> mat2(0, 0);
    EXPECT_TRUE(mat2.empty());
}

TEST(diagonal_matrix_constructor, constructor_int) {
    linalg::Matrix<int> mat(3, 3, 5);
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 3);
    EXPECT_EQ(mat.size(), 9);
    EXPECT_EQ(mat.capacity(), 9);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            if (i == j) {
                EXPECT_EQ(mat(i, j), 5);
            }
            else {
                EXPECT_EQ(mat(i, j), 0);
            }
        }
    }
    EXPECT_THROW(linalg::Matrix<int>(0, 0, 0), std::runtime_error);
}

TEST(diagonal_matrix_constructor, constructor_double) {
    linalg::Matrix<double> mat(3, 3, 5);
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 3);
    EXPECT_EQ(mat.size(), 9);
    EXPECT_EQ(mat.capacity(), 9);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            if (i == j) {
                EXPECT_EQ(mat(i, j), 5);
            }
            else {
                EXPECT_EQ(mat(i, j), 0);
            }
        }
    }
    EXPECT_THROW(linalg::Matrix<double>(0, 0, 0), std::runtime_error);
}

TEST(diagonal_matrix_constructor, constructor_bool) {
    linalg::Matrix<bool> mat(3, 3, true);
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 3);
    EXPECT_EQ(mat.size(), 9);
    EXPECT_EQ(mat.capacity(), 9);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            if (i == j) {
                EXPECT_EQ(mat(i, j), true);
            }
            else {
                EXPECT_EQ(mat(i, j), false);
            }
        }
    }
    EXPECT_THROW(linalg::Matrix<bool>(0, 0, 0), std::runtime_error);
}

TEST(copy_constructor, same_types) {
    linalg::Matrix<int> origin(2, 3);
    origin(0, 0) = 1;
    origin(0, 1) = 2;
    origin(0, 2) = 3;
    linalg::Matrix<int> copy(origin);
    EXPECT_EQ(copy.rows(), origin.rows());
    EXPECT_EQ(copy.columns(), origin.columns());
    EXPECT_EQ(copy.capacity(), 2 * 3);
    EXPECT_EQ(copy(0, 0), 1);
    EXPECT_EQ(copy(0, 1), 2);
    EXPECT_EQ(copy(0, 2), 3);
    linalg::Matrix<int> mat;
    linalg::Matrix<int> mat_copy(mat); // NOLINT(*-unnecessary-copy-initialization)
    EXPECT_EQ(mat_copy.rows(), 0);
    EXPECT_EQ(mat_copy.capacity(), 0);
    EXPECT_EQ(mat_copy.columns(), 0);
    EXPECT_TRUE(mat_copy.empty());
}

TEST(copy_constructor, different_types) {
    linalg::Matrix<double> origin(2, 3);
    origin(0, 0) = 1.5;
    origin(0, 1) = 2.1;
    origin(0, 2) = 3.2;
    linalg::Matrix<int> copy(origin);
    EXPECT_EQ(copy.rows(), origin.rows());
    EXPECT_EQ(copy.columns(), origin.columns());
    EXPECT_EQ(copy.capacity(), 2 * 3);
    EXPECT_EQ(copy(0, 0), 1);
    EXPECT_EQ(copy(0, 1), 2);
    EXPECT_EQ(copy(0, 2), 3);
    linalg::Matrix<int> origin_2(2, 3);
    origin_2(0, 0) = 1;
    origin_2(0, 1) = 2;
    origin_2(0, 2) = 3;
    linalg::Matrix<double> copy_2(origin_2);
    EXPECT_EQ(copy_2.rows(), origin_2.rows());
    EXPECT_EQ(copy_2.columns(), origin_2.columns());
    EXPECT_EQ(copy_2.capacity(), 2 * 3);
    EXPECT_EQ(copy_2(0, 0), 1);
    EXPECT_EQ(copy_2(0, 1), 2);
    EXPECT_EQ(copy_2(0, 2), 3);
    linalg::Matrix<double> mat;
    linalg::Matrix<int> mat_copy(mat); // NOLINT(*-unnecessary-copy-initialization)
    EXPECT_EQ(mat_copy.rows(), 0);
    EXPECT_EQ(mat_copy.capacity(), 0);
    EXPECT_EQ(mat_copy.columns(), 0);
    EXPECT_TRUE(mat_copy.empty());
    linalg::Matrix<int> mat_2;
    linalg::Matrix<double> mat_copy_2(mat); // NOLINT(*-unnecessary-copy-initialization)
    EXPECT_EQ(mat_copy_2.rows(), 0);
    EXPECT_EQ(mat_copy_2.capacity(), 0);
    EXPECT_EQ(mat_copy_2.columns(), 0);
    EXPECT_TRUE(mat_copy_2.empty());
}

TEST(move_constructor, move_constructor) {
    linalg::Matrix<double> origin(2, 3);
    origin(0, 0) = 2.1;
    origin(0, 1) = 3.1;
    linalg::Matrix<double> moved(std::move(origin));
    EXPECT_EQ(moved.rows(), 2);
    EXPECT_EQ(moved.columns(), 3);
    EXPECT_EQ(moved.capacity(), 6);
    EXPECT_EQ(moved(0, 0), 2.1);
    EXPECT_EQ(moved(0, 1), 3.1);
    EXPECT_EQ(origin.rows(), 0);
    EXPECT_EQ(origin.columns(), 0);
    EXPECT_EQ(origin.capacity(), 0);
    EXPECT_TRUE(origin.empty());
    linalg::Matrix<int> origin_2;
    linalg::Matrix<double> moved_2(std::move(origin_2)); // NOLINT(*-move-const-arg)
    EXPECT_EQ(moved_2.rows(), 0);
    EXPECT_EQ(moved_2.columns(), 0);
    EXPECT_EQ(moved_2.capacity(), 0);
    EXPECT_EQ(origin_2.rows(), 0);
    EXPECT_EQ(origin_2.capacity(), 0);
    EXPECT_TRUE(origin_2.empty());
    linalg::Matrix<int> moved_3(std::move(origin)); // NOLINT(*-move-const-arg)
    EXPECT_EQ(moved_3.rows(), 0);
    EXPECT_EQ(moved_3.columns(), 0);
    EXPECT_EQ(moved_3.capacity(), 0);
}

TEST(init_list_1d_constructor, constructor_int) {
    linalg::Matrix<int> mat = {1, 2, 3};
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 1);
    EXPECT_EQ(mat.capacity(), 3);
    EXPECT_FALSE(mat.empty());
    EXPECT_EQ(mat(0, 0), 1);
    EXPECT_EQ(mat(1, 0), 2);
    EXPECT_EQ(mat(2, 0), 3);
}

TEST(init_list_1d_constructor, constructor_double) {
    linalg::Matrix<double> mat = {1.1, 2.2, 3.3};
    EXPECT_EQ(mat.rows(), 3);
    EXPECT_EQ(mat.columns(), 1);
    EXPECT_EQ(mat.capacity(), 3);
    EXPECT_FALSE(mat.empty());
    EXPECT_EQ(mat(0, 0), 1.1);
    EXPECT_EQ(mat(1, 0), 2.2);
    EXPECT_EQ(mat(2, 0), 3.3);
}

TEST(init_list_nd_constructor, constructor_int) {
    linalg::Matrix<int> mat = {{1, 2}, {3, 4}};
    EXPECT_EQ(mat.rows(), 2);
    EXPECT_EQ(mat.columns(), 2);
    EXPECT_EQ(mat.capacity(), 4);
    EXPECT_FALSE(mat.empty());
    EXPECT_EQ(mat(0, 0), 1);
    EXPECT_EQ(mat(0, 1), 2);
    EXPECT_EQ(mat(1, 0), 3);
    EXPECT_EQ(mat(1, 1), 4);
    linalg::Matrix<int> mat2 {{1, 2, 3, 4}};
    EXPECT_EQ(mat2.rows(), 1);
    EXPECT_EQ(mat2.columns(), 4);
    EXPECT_EQ(mat2.capacity(), 4);
    EXPECT_FALSE(mat2.empty());
    EXPECT_EQ(mat2(0, 0), 1);
    EXPECT_EQ(mat2(0, 1), 2);
    EXPECT_EQ(mat2(0, 2), 3);
    EXPECT_EQ(mat2(0, 3), 4);
    linalg::Matrix<int> mat3 {1, 2, 3, 4};
    EXPECT_EQ(mat3.rows(), 4);
    EXPECT_EQ(mat3.columns(), 1);
    EXPECT_EQ(mat3.capacity(), 4);
    EXPECT_FALSE(mat3.empty());
    EXPECT_EQ(mat3(0, 0), 1);
    EXPECT_EQ(mat3(1, 0), 2);
    EXPECT_EQ(mat3(2, 0), 3);
    EXPECT_EQ(mat3(3, 0), 4);
    linalg::Matrix<double> mat4({{1}, {2}, {3}});
    EXPECT_EQ(mat4.rows(), 3);
    EXPECT_EQ(mat4.columns(), 1);
    EXPECT_EQ(mat4.capacity(), 3);
    EXPECT_FALSE(mat4.empty());
    EXPECT_EQ(mat4(0, 0), 1);
    EXPECT_EQ(mat4(1, 0), 2);
    EXPECT_EQ(mat4(2, 0), 3);
}

TEST(init_list_nd_constructor, constructor_double) {
    linalg::Matrix<double> mat = {{1.1, 2.2}, {3.3, 4.4}};
    EXPECT_EQ(mat.rows(), 2);
    EXPECT_EQ(mat.columns(), 2);
    EXPECT_EQ(mat.capacity(), 4);
    EXPECT_FALSE(mat.empty());
    EXPECT_EQ(mat(0, 0), 1.1);
    EXPECT_EQ(mat(0, 1), 2.2);
    EXPECT_EQ(mat(1, 0), 3.3);
    EXPECT_EQ(mat(1, 1), 4.4);
    linalg::Matrix<double> mat2 {{1.1, 2.2, 3.3, 4.4}};
    EXPECT_EQ(mat2.rows(), 1);
    EXPECT_EQ(mat2.columns(), 4);
    EXPECT_EQ(mat2.capacity(), 4);
    EXPECT_FALSE(mat2.empty());
    EXPECT_EQ(mat2(0, 0), 1.1);
    EXPECT_EQ(mat2(0, 1), 2.2);
    EXPECT_EQ(mat2(0, 2), 3.3);
    EXPECT_EQ(mat2(0, 3), 4.4);
    linalg::Matrix<double> mat3 {1.1, 2.2, 3.3, 4.4};
    EXPECT_EQ(mat3.rows(), 4);
    EXPECT_EQ(mat3.columns(), 1);
    EXPECT_EQ(mat3.capacity(), 4);
    EXPECT_FALSE(mat3.empty());
    EXPECT_EQ(mat3(0, 0), 1.1);
    EXPECT_EQ(mat3(1, 0), 2.2);
    EXPECT_EQ(mat3(2, 0), 3.3);
    EXPECT_EQ(mat3(3, 0), 4.4);
}

class TestClass {
public:
    inline static int destructor_count = 0;

    TestClass() = default;
    ~TestClass() { ++destructor_count; }
};

TEST(matrixd_destructor_test, matrixd_destructor_test) {
    const size_t rows = 3, columns = 3;
    {
        linalg::Matrix<TestClass> matrix(rows, columns);
        ASSERT_EQ(TestClass::destructor_count, 0);
    }
    ASSERT_EQ(TestClass::destructor_count, rows * columns);
}