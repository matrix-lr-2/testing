//#include <matrix.h>
//#include <gtest/gtest.h>
//// function for comparing double numbers
//static bool are_equal(double a, double b) {
//    return std::abs(a - b) <= std::numeric_limits<double>::epsilon() * 100000;
//}

//// test for matrix assigment operators
//TEST(matrix_assignment_operator_test, copy_assignment) {
//    linalg::Matrix mat1(2, 3);
//    mat1(0, 0) = 1;
//    mat1(0, 1) = 2;
//    mat1(0, 2) = 3;
//    linalg::Matrix mat2;
//    mat2 = mat1;
//    EXPECT_EQ(mat2(0, 0), 1);
//    EXPECT_EQ(mat2(0, 1), 2);
//    EXPECT_EQ(mat2(0, 2), 3);
//    EXPECT_EQ(mat2.rows(), 2);
//    EXPECT_EQ(mat2.columns(), 3);
//    EXPECT_FALSE(mat2.empty());
//    linalg::Matrix mat;
//    mat2 = mat; // NOLINT(*-unnecessary-copy-initialization)
//    EXPECT_EQ(mat2.rows(), 0);
//    EXPECT_EQ(mat2.columns(), 0);
//    EXPECT_TRUE(mat2.empty());
//    mat2 = mat2;
//    EXPECT_EQ(mat2.rows(), 0);
//    EXPECT_EQ(mat2.columns(), 0);
//    EXPECT_TRUE(mat2.empty());
//}
//
//TEST(matrix_assignment_operator_test, move_assignment) {
//    linalg::Matrix mat1(2, 3);
//    mat1(0, 0) = 1;
//    mat1(0, 1) = 2;
//    mat1(0, 2) = 3;
//    linalg::Matrix mat2;
//    mat2 = std::move(mat1);
//    EXPECT_EQ(mat2(0, 0), 1);
//    EXPECT_EQ(mat2(0, 1), 2);
//    EXPECT_EQ(mat2(0, 2), 3);
//    EXPECT_EQ(mat2.rows(), 2);
//    EXPECT_EQ(mat2.columns(), 3);
//    EXPECT_EQ(mat1.rows(), 0);
//    EXPECT_EQ(mat1.columns(), 0);
//    EXPECT_TRUE(mat1.empty());
//}
//
//// test for matrix index operators
//class matrix_index_test : public ::testing::Test {
//protected:
//    linalg::Matrix m1 = {{1, 2, 3}, {4, 5, 6}};
//    linalg::Matrix m;
//};
//
//TEST_F(matrix_index_test, index_one_param) {
//    EXPECT_EQ(m1(0), 1);
//    EXPECT_EQ(m1(1), 2);
//    EXPECT_THROW(m1(1000), std::runtime_error);
//    EXPECT_THROW(m(0), std::runtime_error);
//}
//
//TEST_F(matrix_index_test, two_one_param) {
//    EXPECT_EQ(m1(0, 0), 1);
//    EXPECT_EQ(m1(0, 1), 2);
//    EXPECT_THROW(m1(1000, 12), std::runtime_error);
//    EXPECT_THROW(m(0, 0), std::runtime_error);
//}
//
//TEST_F(matrix_index_test, squarede_brackets) {
//    EXPECT_EQ(m1[0][0], 1);
//    EXPECT_EQ(m1[0][1], 2);
//    EXPECT_THROW(m1[1000][12], std::runtime_error);
//    EXPECT_THROW(m[0][0], std::runtime_error);
//}
//
//// test for matrix comparison operators
//TEST(matrix_comparison_operator_test, equality_operator) {
//    linalg::Matrix mat1 = {{1, 2, 3}, {4, 5, 6}};
//    linalg::Matrix mat2 = {{1, 2, 3}, {4, 5, 6}};
//    linalg::Matrix mat3 = {{1, 2, 3}, {4, 5, 7}};
//    EXPECT_TRUE(mat1 == mat2);
//    EXPECT_FALSE(mat1 == mat3);
//    EXPECT_FALSE(mat1 != mat2);
//    EXPECT_TRUE(mat1 != mat3);
//    EXPECT_TRUE(mat1 == mat1);
//    EXPECT_FALSE(mat1 != mat1);
//}
//
//// test for matrix arithmetic operators
//class matrix_arithmetic_test : public ::testing::Test {
//protected:
//    void SetUp() override {
//        mat1 = {{0, 1, 7}, {4, 3, 0}};
//        mat2 = {{3, 2, 5}, {0, 0, -3}};
//        mat3 = {{1, 0.5, -5, 1}, {0, 0, -3, 2}};
//        mat6 = {{1, 0.5, -5}, {0, 0, -3}};
//    }
//    linalg::Matrix mat1, mat2, mat3, mat4, mat5, mat6;
//};
//
//TEST_F(matrix_arithmetic_test, addition) {
//    linalg::Matrix result = mat1 + mat2;
//    linalg::Matrix expected = {{3, 3, 12}, {4, 3, -3}};
//    EXPECT_EQ(result, expected);
//    EXPECT_THROW({ mat1 + mat3;}, std::runtime_error);
//    mat1 += mat2;
//    EXPECT_EQ(mat1, expected);
//    EXPECT_THROW({ mat1 += mat3;}, std::runtime_error);
//    EXPECT_THROW(mat4 += mat5, std::runtime_error);
//    EXPECT_THROW(mat4 + mat5, std::runtime_error);
//    result = mat2 + mat6 + mat6;
//    expected = {{5, 3, -5}, {0, 0, -9}};
//    EXPECT_EQ(result, expected);
//    mat2 += mat6 += mat6;
//    EXPECT_EQ(mat2, expected);
//}
//
//TEST_F(matrix_arithmetic_test, subtraction) {
//    linalg::Matrix result = mat1 - mat2;
//    linalg::Matrix expected = {{-3, -1, 2}, {4, 3, 3}};
//    EXPECT_EQ(result, expected);
//    EXPECT_THROW({ mat1 - mat3;}, std::runtime_error);
//    mat1 -= mat2;
//    EXPECT_EQ(mat1, expected);
//    EXPECT_THROW({ mat1 -= mat3;}, std::runtime_error);
//    EXPECT_THROW(mat4 -= mat5, std::runtime_error);
//    EXPECT_THROW(mat4 - mat5, std::runtime_error);
//    result = mat2 - mat6 - mat6;
//    expected = {{1, 1, 15}, {0, 0, 3}};
//    EXPECT_EQ(result, expected);
//    mat2 -= mat6 -= mat6;
//    EXPECT_EQ(mat2, mat2);
//}
//
//TEST_F(matrix_arithmetic_test, scalar_multiplication) {
//    linalg::Matrix result = mat1 * 2;
//    linalg::Matrix expected = {{0, 2, 14}, {8, 6, 0}};
//    EXPECT_EQ(result, expected);
//    result = 2 * mat1;
//    EXPECT_EQ(result, expected);
//    mat1 *= 2;
//    EXPECT_EQ(mat1, expected);
//    result = mat1 * 0.5;
//    expected = {{0, 1, 7}, {4, 3, 0}};
//    EXPECT_EQ(result, expected);
//    mat1 *= 0.5;
//    EXPECT_EQ(mat1, expected);
//    result = mat1 * 0;
//    expected = {{0, 0, 0}, {0, 0, 0}};
//    EXPECT_EQ(result, expected);
//    mat1 *= 0;
//    EXPECT_EQ(mat1, expected);
//    result = mat3 * 1;
//    expected = {{1, 0.5, -5, 1}, {0, 0, -3, 2}};
//    EXPECT_EQ(result, expected);
//    mat3 *= 1;
//    EXPECT_EQ(mat3, expected);
//    result = mat2 * -1;
//    expected = {{-3, -2, -5}, {0, 0, 3}};
//    EXPECT_EQ(result, expected);
//    mat2 *= -1;
//    EXPECT_EQ(mat2, expected);
//    result = mat6 * -2;
//    expected = {{-2, -1, 10}, {0, 0, 6}};
//    EXPECT_EQ(result, expected);
//    result = -2 * mat6;
//    EXPECT_EQ(result, expected);
//    mat6 *= -2;
//    EXPECT_EQ(mat6, expected);
//    result = mat6 * -0.5;
//    expected = {{1, 0.5, -5}, {0, 0, -3}};
//    EXPECT_EQ(result, expected);
//    mat6 *= -0.5;
//    EXPECT_EQ(mat6, expected);
//    EXPECT_THROW(2 * mat5, std::runtime_error);
//    EXPECT_THROW(mat5 * 2, std::runtime_error);
//    EXPECT_THROW(mat5 *= 2;, std::runtime_error);
//}
//
//TEST_F(matrix_arithmetic_test, matrix_multiplication) {
//    EXPECT_THROW({ mat1 * mat2;}, std::runtime_error);
//    EXPECT_THROW({ mat1 *= mat2;}, std::runtime_error);
//    linalg::Matrix e = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
//    linalg::Matrix e1 = {{1, 0}, {0, 1}};
//    EXPECT_EQ(e * e, e);
//    EXPECT_EQ(e *= e, e);
//    EXPECT_EQ(mat1 * e, mat1);
//    EXPECT_EQ(e1 * mat1, mat1);
//    EXPECT_EQ(mat1 *= e, mat1);
//    EXPECT_EQ(e1 *= mat1, mat1);
//    EXPECT_THROW(mat4 * mat5, std::runtime_error);
//    e1 = {{1, 0}, {0, 1}};
//    linalg::Matrix mat7 = {{7, 4}, {5, 3}};
//    linalg::Matrix inv_mat7 = {{3, -4}, {-5, 7}};
//    EXPECT_EQ(mat7 * inv_mat7, e1);
//    EXPECT_EQ(inv_mat7 * mat7, e1);
//    linalg::Matrix zero = {{0, 0}, {0, 0}};
//    EXPECT_EQ(mat7 * zero, zero);
//    EXPECT_EQ(zero * mat7, zero);
//    linalg::Matrix mat8 = {{1, 2}, {3, 4}, {1, 1}};
//    EXPECT_EQ(mat1 * mat8, linalg::Matrix({{10, 11}, {13, 20}}));
//}
//
//// tests for matrix methods
//class matrix_method_test_1 : public ::testing::Test {
//protected:
//    linalg::Matrix not_singular_squared = {{7, 4}, {5, 3}};
//    linalg::Matrix not_squared = {{1, 2, 3}, {4, 5, 6}};
//    linalg::Matrix singular_squared = {{3, 3, 3}, {1, 1, 1}, {2, 2, 2}};
//    linalg::Matrix e = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
//    linalg::Matrix  m;
//};
//
//TEST_F(matrix_method_test_1, reshape) {
//    not_singular_squared.reshape(2, 2);
//    EXPECT_EQ(not_singular_squared, not_singular_squared);
//    not_singular_squared.reshape(1, 4);
//    EXPECT_EQ(not_singular_squared, linalg::Matrix({{7, 4, 5, 3}}));
//    not_squared.reshape(3, 2);
//    EXPECT_EQ(not_squared, linalg::Matrix({{1, 2}, {3, 4}, {5, 6}}));
//    not_singular_squared.reshape(4, 1);
//    linalg::Matrix expected(4, 1);
//    expected(0, 0) = 7;
//    expected(1, 0) = 4;
//    expected(2, 0) = 5;
//    expected(3, 0) = 3;
//    EXPECT_EQ(not_singular_squared, expected);
//    EXPECT_THROW(e.reshape(0, 9), std::runtime_error);
//    EXPECT_THROW(singular_squared.reshape(3, 9), std::runtime_error);
//    EXPECT_THROW(m.reshape(0, 2), std::runtime_error);
//    EXPECT_THROW(m.reshape(1, 2), std::runtime_error);
//}
//
//TEST_F(matrix_method_test_1, element_power) {
//    e.element_power(0);
//    EXPECT_EQ(e, linalg::Matrix({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}));
//    e = not_squared.element_power(2);
//    EXPECT_EQ(e, linalg::Matrix({{1, 4, 9}, {16, 25, 36}}));
//    EXPECT_THROW(m.element_power(3), std::runtime_error);
//}
//
//TEST_F(matrix_method_test_1, sum) {
//    EXPECT_THROW(m.sum(), std::runtime_error);
//    EXPECT_EQ(not_squared.sum(), 21);
//    EXPECT_EQ(e.sum(), 3);
//}
//
//TEST_F(matrix_method_test_1, norm) {
//    EXPECT_THROW(m.norm(), std::runtime_error);
//    EXPECT_EQ(not_squared.norm(), 9.539392014169456);
//    EXPECT_EQ(e.norm(), 1.7320508075688772);
//}
//
//TEST_F(matrix_method_test_1, trace) {
//    EXPECT_THROW(m.trace(), std::runtime_error);
//    EXPECT_THROW(not_squared.trace(), std::runtime_error);
//    EXPECT_EQ(e.trace(), 3);
//}
//
//TEST_F(matrix_method_test_1, swap) {
//    not_squared.swap_rows(0, 1);
//    EXPECT_EQ(not_squared, linalg::Matrix({{4, 5, 6}, {1, 2, 3}}));
//    not_squared.swap_columns(0, 1);
//    EXPECT_EQ(not_squared, linalg::Matrix({{5, 4, 6}, {2, 1, 3}}));
//    linalg::Matrix tmp = singular_squared;
//    linalg::Matrix m1 = singular_squared.swap_rows(0, 2);
//    linalg::Matrix m2 = tmp.swap_rows(2, 0);
//    EXPECT_EQ(m1, m2);
//    linalg::Matrix tmp2 = singular_squared;
//    linalg::Matrix m3 = singular_squared.swap_columns(1, 2);
//    linalg::Matrix m4 = tmp2.swap_columns(2, 1);
//    EXPECT_EQ(m3, m4);
//    EXPECT_THROW(m.swap_rows(0, 1), std::runtime_error);
//    EXPECT_THROW(m.swap_columns(0, 1), std::runtime_error);
//    EXPECT_THROW(not_squared.swap_rows(0, 2), std::runtime_error);
//    EXPECT_THROW(not_squared.swap_columns(3, 2), std::runtime_error);
//}
//
//TEST_F(matrix_method_test_1, determinant) {
//    EXPECT_TRUE(are_equal(not_singular_squared.det(), 1));
//    EXPECT_EQ(singular_squared.det(), 0);
//    EXPECT_EQ(e.det(), 1);
//    linalg::Matrix m1 = {{1, 2, 3, 4, 5, 1}, {3, 7, 8, 9, 10, 2}, {11, 12, 13, 7, 15, 3}, {1, 17, 8, 13, 3, 4}, {1, 0, 3, 0, 0, 5}, {1, 2, 3, 4, 5, 6}};
//    EXPECT_TRUE(are_equal(m1.det(), 1810));
//    EXPECT_THROW(not_squared.det(), std::runtime_error);
//    EXPECT_THROW(m.det(), std::runtime_error);
//}
//
//TEST_F(matrix_method_test_1, invert) {
//    EXPECT_EQ(invert(not_singular_squared), linalg::Matrix({{3, -4}, {-5, 7}}));
//    EXPECT_EQ(invert(e), e);
//    linalg::Matrix m1 = {{2, 0, 1}, {0, -3, -1}, {-2, 4, 0}};
//    EXPECT_EQ(invert(m1), linalg::Matrix({{2, 2, 1.5}, {1, 1, 1}, {-3, -4, -3}}));
//    linalg::Matrix m2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//    EXPECT_THROW(invert(m2), std::runtime_error);
//    EXPECT_THROW(invert(singular_squared), std::runtime_error);
//    EXPECT_THROW(invert(not_squared), std::runtime_error);
//    EXPECT_THROW(invert(m), std::runtime_error);
//}
//
//class matrix_method_test_2 : public ::testing::Test {
//protected:
//    linalg::Matrix m1 = {{1, 2, 3}, {2, 0, 1}, {11, 2, 5}, {0, 0, 1}};
//    linalg::Matrix m2 = {{1, 2, 3, 4}, {2, 4, 6, 8}, {0.5, 1, 1.5, 2}, {1, 0, 1, 1}};
//    linalg::Matrix m3 = {{1, 3, -1}, {-4, 2, 0}, {1, 9, -3.2}};
//    linalg::Matrix e = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
//    linalg::Matrix m;
//};
//
//TEST_F(matrix_method_test_2, concatenate) {
//    linalg::Matrix result = concatenate(m1, m2);
//    linalg::Matrix expected = {{1, 2, 3, 1, 2, 3, 4}, {2, 0, 1, 2, 4, 6, 8}, {11, 2, 5, 0.5, 1, 1.5, 2}, {0, 0, 1, 1, 0, 1, 1}};
//    EXPECT_EQ(result, expected);
//    EXPECT_THROW(concatenate(m1, m), std::runtime_error);
//    EXPECT_THROW(concatenate(m, m1), std::runtime_error);
//    EXPECT_THROW(concatenate(m1, m3), std::runtime_error);
//    EXPECT_THROW(concatenate(m, m), std::runtime_error);
//}
//
//TEST_F(matrix_method_test_2, transpose) {
//    linalg::Matrix result = transpose(m1);
//    EXPECT_EQ(result, linalg::Matrix({{1, 2, 11, 0}, {2, 0, 2, 0}, {3, 1, 5, 1}}));
//    result = transpose(result);
//    EXPECT_EQ(result, m1);
//    EXPECT_EQ(transpose(m), m);
//}
//
//TEST_F(matrix_method_test_2, power) {
//    EXPECT_EQ(power(m3, 3), linalg::Matrix({{-9.8, -16.2, 4.96}, {24, -16, -0.8}, {2.24, -47.04, 8.632}}));
//    EXPECT_EQ(power(m3, 4), linalg::Matrix({{59.96, -17.16, -6.072}, {87.2, 32.8, -21.44}, {199.032, -9.672	, -29.8624}}));
//    EXPECT_EQ(power(m2, 0), e);
//    EXPECT_EQ(power(m2, 1), m2);
//    EXPECT_EQ(power(transpose(m3), -1), transpose(power(m3, -1)));
//    m2 = {{1, 2, 0}, {3, 1, 5}, {0, 1, 1}};
//    EXPECT_EQ(power(m2, -1), invert(m2));
//    EXPECT_EQ(power(m2, -2), power(invert(m2), 2));
//    EXPECT_EQ(power(power(m3, -1), 6), power(power(m3, -2), 3));
//    EXPECT_EQ(power(m2 * m3, -1), power(m3, -1) * power(m2, -1));
//    EXPECT_THROW(power(m1, 2), std::runtime_error);
//    EXPECT_THROW(power(m, 3), std::runtime_error);
//}
//
//TEST_F(matrix_method_test_2, upperTriangleForm) {
//    linalg::Matrix result = m2.upper_triangle_form();
//    linalg::Matrix expected = {{2, 4, 6, 8}, {0, -2, -2, -3}, {0, 0, 0, 0}, {0, 0, 0, 0}};
//    EXPECT_EQ(result, expected);
//    m3 = {1};
//    EXPECT_EQ(m3.upper_triangle_form(), m3);
//    result = e.upper_triangle_form();
//    EXPECT_EQ(result, e);
//    EXPECT_THROW(m.upper_triangle_form(), std::runtime_error);
//}
//
//TEST_F(matrix_method_test_2, rank) {
//    EXPECT_EQ(m1.rank(), 3);
//    EXPECT_EQ(m2.rank(), 2);
//    EXPECT_EQ(m3.rank(), 3);
//    EXPECT_EQ(e.rank(), 4);
//    EXPECT_THROW(m.rank(), std::runtime_error);
//}
//
//TEST_F(matrix_method_test_2, reducedRowEchelonForm) {
//    linalg::Matrix result = m2.reduced_row_echelon_form();
//    linalg::Matrix expected = {{1, 0, 1, 1}, {0, 1, 1, 1.5}, {0, 0, 0, 0}, {0, 0, 0, 0}};
//    EXPECT_EQ(result, expected);
//    result = m1.reduced_row_echelon_form();
//    expected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0, 0, 0}};
//    EXPECT_EQ(result, expected);
//    EXPECT_THROW(m.reduced_row_echelon_form(), std::runtime_error);
//}
//
////int main(int argc, char **argv) {
////    ::testing::InitGoogleTest(&argc, argv);
////    std::cout << "iugyiub";
////    return RUN_ALL_TESTS();
////}