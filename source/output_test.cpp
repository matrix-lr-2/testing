#include <matrix.h>
#include <gtest/gtest.h>
#include <string>

TEST(output_operator, empty_matrix) {
    linalg::Matrix<int> mat;
    std::stringstream ss;
    ss << mat;
    EXPECT_EQ(ss.str(), "|Matrix is empty|\n");
}

TEST(output_operator, integer_matrix) {
    linalg::Matrix<int> mat(2, 3);
    mat(0, 0) = 1;
    mat(0, 1) = 2;
    mat(0, 2) = 3;
    mat(1, 0) = 4;
    mat(1, 1) = 5;
    mat(1, 2) = 6;
    std::stringstream ss;
    ss << mat;
    std::string expected_output =
        "|1 2 3|\n"
        "|4 5 6|\n";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(output_operator, floating_point_matrix) {
    linalg::Matrix<double> mat(2, 2);
    mat(0, 0) = 1.23;
    mat(0, 1) = 4.56;
    mat(1, 0) = 7.89;
    mat(1, 1) = 0.12;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << mat;
    std::string expected_output =
        "|1.23 4.56|\n"
        "|7.89 0.12|\n";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(output_operator, matrix_with_different_column_widths) {
    linalg::Matrix<int> mat(3, 3);
    mat(0, 0) = 1;
    mat(0, 1) = 23;
    mat(0, 2) = 456;
    mat(1, 0) = 7;
    mat(1, 1) = 89;
    mat(1, 2) = 1011;
    mat(2, 0) = 234;
    mat(2, 1) = 5678;
    mat(2, 2) = 9;
    std::stringstream ss;
    ss << mat;
    std::string expected_output =
        "|  1   23  456|\n"
        "|  7   89 1011|\n"
        "|234 5678    9|\n";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(output_operator, text) {
    linalg::Matrix<std::string> mat(2, 2);
    mat(0, 0) = "Pechenin";
    mat(0, 1) = "Danila";
    mat(1, 0) = "Mihailovich";
    mat(1, 1) = "BPM233";
    std::stringstream ss;
    ss << mat;
    std::string expected_output =
            "|   Pechenin Danila|\n"
            "|Mihailovich BPM233|\n";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(output_operator, bool_matrix_empty) {
    linalg::Matrix<bool> mat;
    std::stringstream ss;
    ss << mat;
    EXPECT_EQ(ss.str(), "|Matrix is empty|\n");
}

TEST(output_operator, large_exponential_floating_point_matrix) {
    linalg::Matrix<double> mat(2, 2);
    mat(0, 0) = 1.23e5;
    mat(0, 1) = 4.56e-5;
    mat(1, 0) = 7.89e7;
    mat(1, 1) = 0.12e3;
    std::stringstream ss;
    ss << std::scientific << std::setprecision(2) << mat;
    std::string expected_output =
            "|1.23e+05 4.56e-05|\n"
            "|7.89e+07 1.20e+02|\n";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(output_operator, floating_point_matrix_with_exponential_format) {
    linalg::Matrix<double> mat(2, 2);
    mat(0, 0) = 1.23e10;
    mat(0, 1) = 4.56e-5;
    mat(1, 0) = 7.89e-3;
    mat(1, 1) = 0.12e-7;
    std::stringstream ss;
    ss << std::scientific << std::setprecision(3) << mat;
    std::string expected_output =
            "|1.230e+10 4.560e-05|\n"
            "|7.890e-03 1.200e-08|\n";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(output_operator, large_matrix_with_fixed_format) {
    linalg::Matrix<double> mat(3, 3);
    mat(0, 0) = 123456789.12345;
    mat(0, 1) = 987654321.98765;
    mat(0, 2) = 111222333.11122;
    mat(1, 0) = 444555666.44455;
    mat(1, 1) = 777888999.77788;
    mat(1, 2) = 222333444.22233;
    mat(2, 0) = 555666777.55566;
    mat(2, 1) = 333444555.33344;
    mat(2, 2) = 888999000.88899;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << mat;
    std::string expected_output =
            "|123456789.12 987654321.99 111222333.11|\n"
            "|444555666.44 777888999.78 222333444.22|\n"
            "|555666777.56 333444555.33 888999000.89|\n";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(output_operator, mixed_types_matrix) {
    linalg::Matrix<double> mat(2, 2);
    mat(0, 0) = 1.23456;
    mat(0, 1) = 789.01;
    mat(1, 0) = 0.000123;
    mat(1, 1) = 56789.0;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(4) << mat;
    std::string expected_output =
            "|1.2346   789.0100|\n"
            "|0.0001 56789.0000|\n";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(output_operator, empty_column_matrix) {
    linalg::Matrix<int> mat(3, 3);
    mat(0, 0) = 1;
    mat(0, 1) = 0;
    mat(0, 2) = 3;
    mat(1, 0) = 0;
    mat(1, 1) = 0;
    mat(1, 2) = 0;
    mat(2, 0) = 4;
    mat(2, 1) = 5;
    mat(2, 2) = 6;
    std::stringstream ss;
    ss << mat;
    std::string expected_output =
            "|1 0 3|\n"
            "|0 0 0|\n"
            "|4 5 6|\n";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(output_operator, bool_matrix) {
    linalg::Matrix<bool> mat(5, 5);
    mat(0, 0) = true;
    mat(0, 1) = false;
    mat(0, 2) = true;
    mat(0, 3) = false;
    mat(0, 4) = true;
    mat(1, 0) = false;
    mat(1, 1) = true;
    mat(1, 2) = false;
    mat(1, 3) = true;
    mat(1, 4) = false;
    mat(2, 0) = true;
    mat(2, 1) = false;
    mat(2, 2) = true;
    mat(2, 3) = false;
    mat(2, 4) = true;
    mat(3, 0) = false;
    mat(3, 1) = true;
    mat(3, 2) = false;
    mat(3, 3) = true;
    mat(3, 4) = false;
    mat(4, 0) = true;
    mat(4, 1) = false;
    mat(4, 2) = true;
    mat(4, 3) = false;
    mat(4, 4) = true;
    std::stringstream ss;
    ss << mat;
    std::string expected_output =
            "|1 0 1 0 1|\n"
            "|0 1 0 1 0|\n"
            "|1 0 1 0 1|\n"
            "|0 1 0 1 0|\n"
            "|1 0 1 0 1|\n";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(output_operator, bool_alpha) {
    linalg::Matrix<bool> mat(2, 2);
    mat(0, 0) = true;
    mat(0, 1) = false;
    mat(1, 0) = false;
    mat(1, 1) = true;
    std::stringstream ss;
    ss << std::boolalpha << mat;
    std::string expected_output = "| true false|\n|false  true|\n";
    EXPECT_EQ(ss.str(), expected_output);
}