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

    EXPECT_EQ(mat.sum(), 3);
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

    EXPECT_EQ(mat.trace(), 2);
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

    auto result = concatenate(m1, m2);
    linalg::Matrix<double> expected = {{1.0, 2.0, 3.0, 1.0, 2.0, 3.0, 4.0},
                                       {2.0, 0.0, 1.0, 2.0, 4.0, 6.0, 8.0},
                                       {11.0, 2.0, 5.0, 0.5, 1.0, 1.5, 2.0},
                                       {0.0, 0.0, 1.0, 1.0, 0.0, 1.0, 1.0}};
    EXPECT_EQ(result, expected);
}

TEST(concatenate_matrix, concatenate_int_bool) {
    linalg::Matrix<int> m1 = {{1, 2, 3}, {2, 0, 1}, {11, 2, 5}, {0, 0, 1}};
    linalg::Matrix<bool> m2 = {{true, false, true}, {false, true, false}, {true, true, false}, {false, true, true}};

    auto result = concatenate(m1, m2);
    linalg::Matrix<int> expected = {{1, 2, 3, 1, 0, 1},
                                    {2, 0, 1, 0, 1, 0},
                                    {11, 2, 5, 1, 1, 0},
                                    {0, 0, 1, 0, 1, 1}};
    EXPECT_EQ(result, expected);
}

TEST(concatenate_matrix, concatenate_double_double) {
    linalg::Matrix<double> m1 = {{1.0, 2.0, 3.0}, {2.0, 0.0, 1.0}, {11.0, 2.0, 5.0}, {0.0, 0.0, 1.0}};
    linalg::Matrix<double> m2 = {{1.0, 2.0, 3.0, 4.0}, {2.0, 4.0, 6.0, 8.0}, {0.5, 1.0, 1.5, 2.0}, {1.0, 0.0, 1.0, 1.0}};

    auto result = concatenate(m1, m2);
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

static bool tests_equal(double a, double b) {
    return (a - b) < 10e-11;
}

TEST(determinant, det_int) {
    linalg::Matrix<int> not_singular_squared = {{7, 4}, {5, 3}};
    linalg::Matrix<int> not_squared = {{1, 2, 3}, {4, 5, 6}};
    linalg::Matrix<int> singular_squared = {{3, 3, 3}, {1, 1, 1}, {2, 2, 2}};
    linalg::Matrix<int> e = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    linalg::Matrix<int>  m;
    EXPECT_TRUE(tests_equal(not_singular_squared.det(), 1));
    EXPECT_EQ(singular_squared.det(), 0);
    EXPECT_EQ(e.det(), 1);
    linalg::Matrix<int> m1 = {{1, 2, 3, 4, 5, 1}, {3, 7, 8, 9, 10, 2}, {11, 12, 13, 7, 15, 3}, {1, 17, 8, 13, 3, 4}, {1, 0, 3, 0, 0, 5}, {1, 2, 3, 4, 5, 6}};
    EXPECT_TRUE(tests_equal(m1.det(), 1810));
    EXPECT_THROW(not_squared.det(), std::runtime_error);
    EXPECT_THROW(m.det(), std::runtime_error);
}

TEST(determinant, det_double) {
    linalg::Matrix<double> not_singular_squared = {{7.345, 4.876}, {5.12, 3.456}};
    linalg::Matrix<double> not_squared = {{1.234, 2.345, 3.456}, {4.567, 5.678, 6.789}};
    linalg::Matrix<double> singular_squared = {{3.141, 3.141, 3.141}, {1.618, 1.618, 1.618}, {2.718, 2.718, 2.718}};
    linalg::Matrix<double> e = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
    linalg::Matrix<double> m1 = {{1.234, 2.456, 3.678, 4.789, 5.901, 1.345}, {3.567, 7.678, 8.789, 9.123, 10.456, 2.234},
                         {11.234, 12.345, 13.456, 7.123, 15.234, 3.345}, {1.567, 17.234, 8.123, 13.456, 3.567, 4.234},
                         {1.789, 0.987, 3.456, 0.123, 0.876, 5.678}, {1.123, 2.345, 3.567, 4.789, 5.234, 6.345}};
    EXPECT_TRUE(tests_equal(not_singular_squared.det(), 0.4192));
    EXPECT_TRUE(tests_equal(singular_squared.det(), 0.0));
    EXPECT_EQ(e.det(), 1.0);
    EXPECT_TRUE(tests_equal(m1.det(), 1787.48));
    EXPECT_THROW(not_squared.det(), std::runtime_error);
}

TEST(determinant, det_bool) {
    linalg::Matrix<bool> not_singular_squared = {{true, false}, {false, true}};
    linalg::Matrix<bool> not_squared = {{true, false, true}, {false, true, false}};
    linalg::Matrix<bool> singular_squared = {{true, true}, {true, true}};
    EXPECT_TRUE(not_singular_squared.det());
    EXPECT_FALSE(singular_squared.det());
    EXPECT_THROW(not_squared.det(), std::runtime_error);
}

TEST(power_matrix, power_int) {
    linalg::Matrix<int> mat = {{1, 2}, {3, 4}};
    auto result = power(mat, 2);
    linalg::Matrix<int> expected = {{7, 10}, {15, 22}};
    EXPECT_EQ(result, expected);
    result = power(mat, 3);
    expected = {{37, 54}, {81, 118}};
    EXPECT_EQ(result, expected);
    result = power(mat, 0);
    linalg::Matrix<int> expected_identity = {{1, 0}, {0, 1}};
    EXPECT_EQ(result, expected_identity);
    linalg::Matrix<int> mat_non_square = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_THROW(linalg::power(mat_non_square, 2), std::runtime_error);
    linalg::Matrix<int> mat_empty;
    EXPECT_THROW(linalg::power(mat_empty, 2), std::runtime_error);
}

TEST(power_matrix, power_double) {
    linalg::Matrix<double> mat = {{1.5, 2.5}, {3.5, 4.5}};
    auto result = power(mat, 2);
    linalg::Matrix<double> expected = {{11., 15.}, {21., 29.}};
    EXPECT_EQ(result, expected);
    result = power(mat, 3);
    expected = {{69.0, 95.0}, {133.0, 183.0}};
    EXPECT_EQ(result, expected);
    result = power(mat, 0);
    linalg::Matrix<double> expected_identity = {{1.0, 0.0}, {0.0, 1.0}};
    EXPECT_EQ(result, expected_identity);
    linalg::Matrix<double> mat_non_square = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    EXPECT_THROW(linalg::power(mat_non_square, 2), std::runtime_error);
    linalg::Matrix<double> mat_empty;
    EXPECT_THROW(linalg::power(mat_empty, 2), std::runtime_error);
}

TEST(power_matrix, power_bool) {
    linalg::Matrix<bool> mat = {{true, false}, {false, true}};
    auto result = power(mat, 2);
    linalg::Matrix<bool> expected = {{true, false}, {false, true}};
    EXPECT_EQ(result, expected);
    result = power(mat, 3);
    expected = {{true, false}, {false, true}};
    EXPECT_EQ(result, expected);
    result = power(mat, 0);
    linalg::Matrix<bool> expected_identity = {{true, false}, {false, true}};
    EXPECT_EQ(result, expected_identity);
    linalg::Matrix<bool> mat_non_square = {{true, false, true}, {false, true, false}};
    EXPECT_THROW(linalg::power(mat_non_square, 2), std::runtime_error);
    linalg::Matrix<bool> mat_empty;
    EXPECT_THROW(linalg::power(mat_empty, 2), std::runtime_error);
}

TEST(power_matrix, negative_power) {
    linalg::Matrix<int> m1 = {{1, 2, 3}, {2, 0, 1}, {11, 2, 5}, {0, 0, 1}};
    linalg::Matrix<double> m2 = {{1.0, 2.0, 3.0, 4.0}, {2.0, 4.0, 6.0, 8.0}, {0.5, 1.0, 1.5, 2.0}, {1.0, 0.0, 1.0, 1.0}};
    linalg::Matrix<double> m3 = {{1.0, 3.0, -1.0}, {-4.0, 2.0, 0.0}, {1.0, 9.0, -3.2}};
    linalg::Matrix<int> e = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    linalg::Matrix<int> m;
    EXPECT_EQ(power(m3, 3), linalg::Matrix<double>({{-9.8, -16.2, 4.96}, {24.0, -16.0, -0.8}, {2.24, -47.04, 8.632}}));
    EXPECT_EQ(power(m3, 4), linalg::Matrix<double>({{59.96, -17.16, -6.072}, {87.2, 32.8, -21.44}, {199.032, -9.672	, -29.8624}}));
    EXPECT_EQ(power(m2, 0), e);
    EXPECT_EQ(power(m2, 1), m2);
    EXPECT_EQ(power(transpose(m3), -1), transpose(power(m3, -1)));
    m2 = {{1, 2, 0}, {3, 1, 5}, {0, 1, 1}};
    EXPECT_EQ(power(m2, -1), invert(m2));
    EXPECT_EQ(power(m2, -2), power(invert(m2), 2));
    EXPECT_EQ(power(power(m3, -1), 6), power(power(m3, -2), 3));
    EXPECT_EQ(power(m2 * m3, -1), power(m3, -1) * power(m2, -1));
    EXPECT_THROW(power(m1, 2), std::runtime_error);
    EXPECT_THROW(power(m, 3), std::runtime_error);
}

TEST(invert_matrix, invert) {
    linalg::Matrix<int> not_singular_squared = {{7, 4}, {5, 3}};
    linalg::Matrix<int> not_squared = {{1, 2, 3}, {4, 5, 6}};
    linalg::Matrix<int> singular_squared = {{3, 3, 3}, {1, 1, 1}, {2, 2, 2}};
    linalg::Matrix<int> e = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    linalg::Matrix<int>  m;
    EXPECT_EQ(invert(not_singular_squared), linalg::Matrix<int>({{3, -4}, {-5, 7}}));
    EXPECT_EQ(invert(e), e);
    linalg::Matrix<int> m1 = {{2, 0, 1}, {0, -3, -1}, {-2, 4, 0}};
    EXPECT_EQ(invert(m1), linalg::Matrix<double>({{2.0, 2.0, 1.5}, {1.0, 1.0, 1.0}, {-3.0, -4.0, -3.0}}));
    linalg::Matrix<int> m2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    EXPECT_THROW(invert(m2), std::runtime_error);
    EXPECT_THROW(invert(singular_squared), std::runtime_error);
    EXPECT_THROW(invert(not_squared), std::runtime_error);
    EXPECT_THROW(invert(m), std::runtime_error);
}

TEST(invert_matrix, invert_bool) {
    linalg::Matrix<bool> not_singular_squared = {{true, false}, {false, true}};
    linalg::Matrix<bool> singular_squared = {{true, true}, {true, true}};
    linalg::Matrix<bool> e = {{true, false, false}, {false, true, false}, {false, false, true}};
    EXPECT_EQ(invert(not_singular_squared), linalg::Matrix<bool>({{true, false}, {false, true}}));
    EXPECT_EQ(invert(e), e);
    EXPECT_THROW(invert(singular_squared), std::runtime_error);
}

class matrix_method_test_additional : public ::testing::Test {
protected:
    linalg::Matrix<int> m1 = {{1, 2, 3}, {2, 0, 1}, {11, 2, 5}, {0, 0, 1}};
    linalg::Matrix<double> m2 = {{1.0, 2.0, 3.0, 4.0}, {2.0, 4.0, 6.0, 8.0}, {0.5, 1.0, 1.5, 2.0}, {1.0, 0.0, 1.0, 1.0}};
    linalg::Matrix<double> m3 = {{1.0, 3.0, -1.0}, {-4.0, 2.0, 0.0}, {1.0, 9.0, -3.2}};
    linalg::Matrix<int> e = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    linalg::Matrix<bool> m;
};

TEST_F(matrix_method_test_additional, upperTriangleForm) {
    linalg::Matrix result = m2.upper_triangle_form();
    linalg::Matrix<int> expected = {{2, 4, 6, 8}, {0, -2, -2, -3}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    EXPECT_EQ(result, expected);
    m3 = {1};
    EXPECT_EQ(m3.upper_triangle_form(), m3);
    result = e.upper_triangle_form();
    EXPECT_EQ(result, e);
    EXPECT_THROW(m.upper_triangle_form(), std::runtime_error);
}

TEST_F(matrix_method_test_additional, rank) {
    EXPECT_EQ(m1.rank(), 3);
    EXPECT_EQ(m2.rank(), 2);
    EXPECT_EQ(m3.rank(), 3);
    EXPECT_EQ(e.rank(), 4);
    EXPECT_THROW(m.rank(), std::runtime_error);
}

TEST_F(matrix_method_test_additional, reduced_row_echelon_form) {
    linalg::Matrix result = m2.reduced_row_echelon_form();
    linalg::Matrix<double> expected = {{1.0, 0.0, 1.0, 1.0}, {0.0, 1.0, 1.0, 1.5}, {0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0}};
    linalg::Matrix<double> expected1 = {{1}, {2}, {3}};
    EXPECT_EQ(result, expected);
    result = m1.reduced_row_echelon_form();
    expected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0, 0, 0}};
    EXPECT_EQ(result, expected);
    EXPECT_THROW(m.reduced_row_echelon_form(), std::runtime_error);
}

TEST(rotation_3d_test, angle_pi) {
    linalg::Matrix<double> mat = {{-0.6, 0.8, 0.0}, {0.8, 0.6, 0.0}, {0.0, 0.0, -1.0}};
    std::tuple<std::string, double, double, double, double> result = mat.rotation_3d();
    EXPECT_EQ(std::get<0>(result), "rotation");
    EXPECT_TRUE(tests_equal(std::get<1>(result), 1));
    EXPECT_TRUE(tests_equal(std::get<2>(result), 2));
    EXPECT_TRUE(tests_equal(std::get<3>(result), 0));
    EXPECT_TRUE(tests_equal(std::get<4>(result), 180));
}

TEST(rotation_3d_test, stadard_case) {
    linalg::Matrix<double> mat = {{0.0, 0.0, 1.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
    std::tuple<std::string, double, double, double, double> result = mat.rotation_3d();
    EXPECT_EQ(std::get<0>(result), "rotation");
    EXPECT_TRUE(tests_equal(std::get<1>(result), 1));
    EXPECT_TRUE(tests_equal(std::get<2>(result), 1));
    EXPECT_TRUE(tests_equal(std::get<3>(result), 1));
    EXPECT_TRUE(tests_equal(std::get<4>(result), 120));
}

TEST(rotation_3d_test, angle_90) {
    linalg::Matrix<double> mat = {{0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {-1.0, 0.0, 0.0}};
    std::tuple<std::string, double, double, double, double> result = mat.rotation_3d();
    EXPECT_EQ(std::get<0>(result), "rotation");
    EXPECT_TRUE(tests_equal(std::get<1>(result), 0));
    EXPECT_TRUE(tests_equal(std::get<2>(result), 1));
    EXPECT_TRUE(tests_equal(std::get<3>(result), 0));
    EXPECT_TRUE(tests_equal(std::get<4>(result), 90));
}

TEST(rotation_3d_test, identity) {
    linalg::Matrix<double> mat(3, 3, 1);
    std::tuple<std::string, double, double, double, double> result = mat.rotation_3d();
    EXPECT_EQ(std::get<0>(result), "identity transformation");
    EXPECT_TRUE(tests_equal(std::get<1>(result), 0));
    EXPECT_TRUE(tests_equal(std::get<2>(result), 0));
    EXPECT_TRUE(tests_equal(std::get<3>(result), 0));
    EXPECT_TRUE(tests_equal(std::get<4>(result), 0));
}