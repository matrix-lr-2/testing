//// tests for matrix methods
//class matrix_method_test_1 : public ::testing::Test {
//protected:
//    linalg::Matrix not_singular_squared = {{7, 4}, {5, 3}};
//    linalg::Matrix not_squared = {{1, 2, 3}, {4, 5, 6}};
//    linalg::Matrix singular_squared = {{3, 3, 3}, {1, 1, 1}, {2, 2, 2}};
//    linalg::Matrix e = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
//    linalg::Matrix  m;
//};
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