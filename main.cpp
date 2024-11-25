#include <iostream>
#include <matrix.h>

int main() {
    // It is an example of using the library
    // To run tests, run executable file with tests
    linalg::Matrix a = {{3,2,1,3,1},{1,1,1,1,1},{2,3,2,2,2},{3,1,1,1,1},{1,1,1,2,3}};
    std::cout << "Matrix A:\n" << a.element_power(-2);
    std::cout << "Matrix A, every element powered in -2:\n" << a.element_power(-2);
    std::cout << "Determinant of A: " <<a.det() << std::endl;
    std::cout << "Upper triangular form of matrix A:\n" << a.upper_triangle_form();
    std::cout << "Reduced row echelon form form of matrix A:\n" << a.reduced_row_echelon_form();
    std::cout << "Invert matrix A:\n" << std::scientific << std::setprecision(2) << invert(a);
    return 0;
}