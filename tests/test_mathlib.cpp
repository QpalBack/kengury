#include <gtest/gtest.h>
#include "mathlib.hpp"

TEST(MathLibTest, HasUniqueDigits) {
    EXPECT_TRUE(MathLib::has_unique_digits(123));
    EXPECT_TRUE(MathLib::has_unique_digits(987654321));
    EXPECT_FALSE(MathLib::has_unique_digits(11));
    EXPECT_FALSE(MathLib::has_unique_digits(1223));
    EXPECT_TRUE(MathLib::has_unique_digits(0));
}

TEST(MathLibTest, GetTensDigit) {
    EXPECT_EQ(MathLib::get_tens_digit(123), 2);
    EXPECT_EQ(MathLib::get_tens_digit(10), 1);
    EXPECT_EQ(MathLib::get_tens_digit(5), -1);
    EXPECT_EQ(MathLib::get_tens_digit(99), 9);
    EXPECT_EQ(MathLib::get_tens_digit(100), 0);
}

TEST(MathLibTest, FindMaxNumberWithUniqueDigits) {
    EXPECT_EQ(MathLib::find_max_number_with_unique_digits(10), 10);
    EXPECT_EQ(MathLib::find_max_number_with_unique_digits(11), 10);
    EXPECT_EQ(MathLib::find_max_number_with_unique_digits(100), 98);
    EXPECT_GE(MathLib::find_max_number_with_unique_digits(1000), 987);
}

TEST(MathLibTest, SolveKenguruProblem) {
    // Примеры чисел с 2 словами в русском языке:
    // 21 → "двадцать один" (2 слова)
    // 31 → "тридцать один" (2 слова)
    // 41 → "сорок один" (2 слова)
    
    // Проверяем, что для max_number=50 находим число 41 (десятки = 4)
    EXPECT_EQ(MathLib::solve_kenguru_problem(50, 2, "ru"), 4);
    
    // Для max_number=30 находим число 21 (десятки = 2)
    EXPECT_EQ(MathLib::solve_kenguru_problem(30, 2, "ru"), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
