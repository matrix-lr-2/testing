#include <matrix.h>
#include <gtest/gtest.h>

TEST(matrix_element_power_test, positive_power) {
    linalg::Matrix<double> mat = {{1.0, 2.0}, {3.0, 4.0}};
    auto result = mat.element_power(2.0);
    EXPECT_DOUBLE_EQ(result(0, 0), 1.0);
    EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
    EXPECT_DOUBLE_EQ(result(1, 0), 9.0);
    EXPECT_DOUBLE_EQ(result(1, 1), 16.0);
}

TEST(matrix_element_power_test, fractional_power) {
    linalg::Matrix<double> mat = {{1.0, 4.0}, {9.0, 16.0}};
    auto result = mat.element_power(0.5);
    EXPECT_DOUBLE_EQ(result(0, 0), 1.0);
    EXPECT_DOUBLE_EQ(result(0, 1), 2.0);
    EXPECT_DOUBLE_EQ(result(1, 0), 3.0);
    EXPECT_DOUBLE_EQ(result(1, 1), 4.0);
}

TEST(matrix_element_power_test, negative_power) {
    linalg::Matrix<double> mat = {{1.0, 2.0}, {4.0, 8.0}};
    auto result = mat.element_power(-1.0);
    EXPECT_DOUBLE_EQ(result(0, 0), 1.0);
    EXPECT_DOUBLE_EQ(result(0, 1), 0.5);
    EXPECT_DOUBLE_EQ(result(1, 0), 0.25);
    EXPECT_DOUBLE_EQ(result(1, 1), 0.125);
}

TEST(matrix_element_power_test, empty_matrix) {
    linalg::Matrix<double> mat;
    EXPECT_THROW(mat.element_power(2.0), std::runtime_error);
}

TEST(matrix_sum_test, general_case) {
    linalg::Matrix<int> mat = {{1, 2}, {3, 4}};
    EXPECT_EQ(mat.sum(), 10);
}

TEST(matrix_sum_test, empty_matrix) {
    linalg::Matrix<int> mat;
    EXPECT_THROW(mat.sum(), std::runtime_error);
}

TEST(matrix_norm_test, general_case) {
    linalg::Matrix<double> mat = {{1.0, 2.0}, {3.0, 4.0}};
    EXPECT_DOUBLE_EQ(mat.norm(), std::sqrt(30.0));
}

TEST(matrix_norm_test, empty_matrix) {
    linalg::Matrix<double> mat;
    EXPECT_THROW(mat.norm(), std::runtime_error);
}

TEST(matrix_trace_test, square_matrix) {
    linalg::Matrix<int> mat = {{1, 2}, {3, 4}};
    EXPECT_EQ(mat.trace(), 5);
}

TEST(matrix_trace_test, non_square_matrix) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_THROW(mat.trace(), std::runtime_error);
}

TEST(matrix_trace_test, empty_matrix) {
    linalg::Matrix<int> mat;
    EXPECT_THROW(mat.trace(), std::runtime_error);
}

TEST(matrix_sum_test, sum_int) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {4, 5, 6}};

    EXPECT_EQ(mat.sum(), 21);
}

TEST(matrix_sum_test, sum_double) {
    linalg::Matrix<double> mat = {{1.5, 2.5}, {3.5, 4.5}};

    EXPECT_DOUBLE_EQ(mat.sum(), 12.0);
}

TEST(matrix_sum_test, sum_bool) {
    linalg::Matrix<bool> mat = {{true, false}, {true, true}};

    EXPECT_EQ(mat.sum(), true);
}

TEST(matrix_norm_test, norm_int) {
    linalg::Matrix<int> mat = {{3, 4}, {5, 12}};

    EXPECT_EQ(mat.norm(), std::sqrt(3*3 + 4*4 + 5*5 + 12*12));
}

TEST(matrix_norm_test, norm_double) {
    linalg::Matrix<double> mat = {{3.0, 4.0}, {5.0, 12.0}};

    EXPECT_DOUBLE_EQ(mat.norm(), std::sqrt(3.0*3.0 + 4.0*4.0 + 5.0*5.0 + 12.0*12.0));
}

TEST(matrix_norm_test, norm_bool) {
    linalg::Matrix<bool> mat = {{true, false}, {true, true}};

    EXPECT_EQ(mat.norm(), std::sqrt(1*1 + 0*0 + 1*1 + 1*1));
}

TEST(matrix_trace_test, trace_int) {
    linalg::Matrix<int> mat = {{1, 2}, {3, 4}};

    EXPECT_EQ(mat.trace(), 1 + 4);
}

TEST(matrix_trace_test, trace_double) {
    linalg::Matrix<double> mat = {{1.5, 2.5}, {3.5, 4.5}};

    EXPECT_DOUBLE_EQ(mat.trace(), 1.5 + 4.5);
}

TEST(matrix_trace_test, trace_bool) {
    linalg::Matrix<bool> mat = {{true, false}, {false, true}};

    EXPECT_EQ(mat.trace(), true);
}

TEST(transpose_matrix, transpose_int) {
    linalg::Matrix<int> mat = {{1, 2, 3}, {4, 5, 6}};

    linalg::Matrix<int> result = transpose(mat);

    EXPECT_EQ(result(0, 0), 1);
    EXPECT_EQ(result(0, 1), 4);
    EXPECT_EQ(result(1, 0), 2);
    EXPECT_EQ(result(1, 1), 5);
    EXPECT_EQ(result(2, 0), 3);
    EXPECT_EQ(result(2, 1), 6);
}

TEST(transpose_matrix, transpose_double) {
    linalg::Matrix<double> mat = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}};

    linalg::Matrix<double> result = transpose(mat);

    EXPECT_DOUBLE_EQ(result(0, 0), 1.1);
    EXPECT_DOUBLE_EQ(result(0, 1), 4.4);
    EXPECT_DOUBLE_EQ(result(1, 0), 2.2);
    EXPECT_DOUBLE_EQ(result(1, 1), 5.5);
    EXPECT_DOUBLE_EQ(result(2, 0), 3.3);
    EXPECT_DOUBLE_EQ(result(2, 1), 6.6);
}

TEST(transpose_matrix, transpose_bool) {
    linalg::Matrix<bool> mat = {{true, false, true}, {false, true, false}};

    linalg::Matrix<bool> result = transpose(mat);

    EXPECT_EQ(result(0, 0), true);
    EXPECT_EQ(result(0, 1), false);
    EXPECT_EQ(result(1, 0), false);
    EXPECT_EQ(result(1, 1), true);
    EXPECT_EQ(result(2, 0), true);
    EXPECT_EQ(result(2, 1), false);
}

TEST(transpose_matrix, transpose_square_matrix) {
    linalg::Matrix<int> mat = {{1, 2}, {3, 4}};

    linalg::Matrix<int> result = transpose(mat);

    EXPECT_EQ(result(0, 0), 1);
    EXPECT_EQ(result(0, 1), 3);
    EXPECT_EQ(result(1, 0), 2);
    EXPECT_EQ(result(1, 1), 4);
}

TEST(transpose_matrix, transpose_empty_matrix) {
    linalg::Matrix<int> mat;

    linalg::Matrix<int> mat2 = transpose(mat);
    EXPECT_TRUE(mat2.empty());
}

TEST(concatenate_matrix, concatenate_int_double) {
    linalg::Matrix<int> m1 = {{1, 2, 3}, {2, 0, 1}, {11, 2, 5}, {0, 0, 1}};
    linalg::Matrix<double> m2 = {{1.0, 2.0, 3.0, 4.0}, {2.0, 4.0, 6.0, 8.0}, {0.5, 1.0, 1.5, 2.0}, {1.0, 0.0, 1.0, 1.0}};

    auto result = linalg::concatenate(m1, m2);
    linalg::Matrix<double> expected = {{1.0, 2.0, 3.0, 1.0, 2.0, 3.0, 4.0},
                                       {2.0, 0.0, 1.0, 2.0, 4.0, 6.0, 8.0},
                                       {11.0, 2.0, 5.0, 0.5, 1.0, 1.5, 2.0},
                                       {0.0, 0.0, 1.0, 1.0, 0.0, 1.0, 1.0}};
    EXPECT_EQ(result, expected);
}

TEST(concatenate_matrix, concatenate_int_bool) {
    linalg::Matrix<int> m1 = {{1, 2, 3}, {2, 0, 1}, {11, 2, 5}, {0, 0, 1}};
    linalg::Matrix<bool> m2 = {{true, false, true}, {false, true, false}, {true, true, false}, {false, true, true}};

    auto result = linalg::concatenate(m1, m2);
    linalg::Matrix<int> expected = {{1, 2, 3, 1, 0, 1},
                                    {2, 0, 1, 0, 1, 0},
                                    {11, 2, 5, 1, 1, 0},
                                    {0, 0, 1, 0, 1, 1}};
    EXPECT_EQ(result, expected);
}

TEST(concatenate_matrix, concatenate_double_double) {
    linalg::Matrix<double> m1 = {{1.0, 2.0, 3.0}, {2.0, 0.0, 1.0}, {11.0, 2.0, 5.0}, {0.0, 0.0, 1.0}};
    linalg::Matrix<double> m2 = {{1.0, 2.0, 3.0, 4.0}, {2.0, 4.0, 6.0, 8.0}, {0.5, 1.0, 1.5, 2.0}, {1.0, 0.0, 1.0, 1.0}};

    auto result = linalg::concatenate(m1, m2);
    linalg::Matrix<double> expected = {{1.0, 2.0, 3.0, 1.0, 2.0, 3.0, 4.0},
                                       {2.0, 0.0, 1.0, 2.0, 4.0, 6.0, 8.0},
                                       {11.0, 2.0, 5.0, 0.5, 1.0, 1.5, 2.0},
                                       {0.0, 0.0, 1.0, 1.0, 0.0, 1.0, 1.0}};
    EXPECT_EQ(result, expected);
}

TEST(concatenate_matrix, concatenate_same_type) {
    linalg::Matrix<int> m1 = {{1, 2, 3}, {2, 0, 1}, {11, 2, 5}, {0, 0, 1}};
    linalg::Matrix<int> m2 = {{4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};

    auto result = linalg::concatenate(m1, m2);
    linalg::Matrix<int> expected = {{1, 2, 3, 4, 5, 6},
                                    {2, 0, 1, 7, 8, 9},
                                    {11, 2, 5, 10, 11, 12},
                                    {0, 0, 1, 13, 14, 15}};
    EXPECT_EQ(result, expected);
}

TEST(concatenate_matrix, throws) {
    linalg::Matrix<int> m1 = {{1, 2, 3}, {2, 0, 1}, {11, 2, 5}, {0, 0, 1}};
    linalg::Matrix<int> m2 = {{1, 2}, {3, 4}};
    linalg::Matrix<int> m3;

    EXPECT_THROW(linalg::concatenate(m1, m2), std::runtime_error);
    EXPECT_THROW(linalg::concatenate(m3, m2), std::runtime_error);
    EXPECT_THROW(linalg::concatenate(m2, m3), std::runtime_error);
    EXPECT_THROW(linalg::concatenate(m3, m3), std::runtime_error);
}

// TEST(power_matrix, power_int) {
//     linalg::Matrix<int> mat = {{1, 2}, {3, 4}};
//
//     auto result = linalg::power(mat, 2);
//     linalg::Matrix<int> expected = {{7, 10}, {15, 22}};
//     EXPECT_EQ(result, expected);
//
//     result = linalg::power(mat, 3);
//     expected = {{37, 54}, {81, 118}};
//     EXPECT_EQ(result, expected);
//
//     result = linalg::power(mat, 0);
//     linalg::Matrix<int> expected_identity = {{1, 0}, {0, 1}};
//     EXPECT_EQ(result, expected_identity);
//
//     linalg::Matrix<int> mat_non_square = {{1, 2, 3}, {4, 5, 6}};
//     EXPECT_THROW(linalg::power(mat_non_square, 2), std::runtime_error);
//
//     linalg::Matrix<int> mat_empty;
//     EXPECT_THROW(linalg::power(mat_empty, 2), std::runtime_error);
// }
//
// TEST(power_matrix, power_double) {
//     linalg::Matrix<double> mat = {{1.0, 2.0}, {3.0, 4.0}};
//
//     auto result = linalg::power(mat, 2);
//     linalg::Matrix<double> expected = {{7.0, 10.0}, {15.0, 22.0}};
//     EXPECT_EQ(result, expected);
//
//     result = linalg::power(mat, 3);
//     expected = {{37.0, 54.0}, {81.0, 118.0}};
//     EXPECT_EQ(result, expected);
//
//     result = linalg::power(mat, 0);
//     linalg::Matrix<double> expected_identity = {{1.0, 0.0}, {0.0, 1.0}};
//     EXPECT_EQ(result, expected_identity);
//
//     linalg::Matrix<double> mat_non_square = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
//     EXPECT_THROW(linalg::power(mat_non_square, 2), std::runtime_error);
//
//     linalg::Matrix<double> mat_empty;
//     EXPECT_THROW(linalg::power(mat_empty, 2), std::runtime_error);
// }
//
// TEST(power_matrix, power_bool) {
//     linalg::Matrix<bool> mat = {{true, false}, {false, true}};
//
//     auto result = linalg::power(mat, 2);
//     linalg::Matrix<bool> expected = {{true, false}, {false, true}};
//     EXPECT_EQ(result, expected);
//
//     result = linalg::power(mat, 3);
//     expected = {{true, false}, {false, true}};
//     EXPECT_EQ(result, expected);
//
//     result = linalg::power(mat, 0);
//     linalg::Matrix<bool> expected_identity = {{true, false}, {false, true}};
//     EXPECT_EQ(result, expected_identity);
//
//     linalg::Matrix<bool> mat_non_square = {{true, false, true}, {false, true, false}};
//     EXPECT_THROW(linalg::power(mat_non_square, 2), std::runtime_error);
//
//     linalg::Matrix<bool> mat_empty;
//     EXPECT_THROW(linalg::power(mat_empty, 2), std::runtime_error);
// }