#include <iostream>
#include "mathlib/include/mathlib.hpp"
int main() {
    std::cout << "MathLib::has_unique_digits(123) = " << MathLib::has_unique_digits(123) << std::endl;
    std::cout << "MathLib::has_unique_digits(112) = " << MathLib::has_unique_digits(112) << std::endl;
    std::cout << "MathLib::get_tens_digit(456) = " << MathLib::get_tens_digit(456) << std::endl;
    std::cout << "MathLib::solve_kenguru_problem(100, 2) = " << MathLib::solve_kenguru_problem(100, 2) << std::endl;
    return 0;
}
