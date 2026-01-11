#include "mathlib.hpp"
#include <set>
#include <string>
#include <sstream>

namespace MathLib {
    
    bool has_unique_digits(int number) {
        std::set<int> digits;
        while (number > 0) {
            int digit = number % 10;
            if (digits.count(digit)) return false;
            digits.insert(digit);
            number /= 10;
        }
        return true;
    }
    
    int get_tens_digit(int number) {
        if (number < 10) return -1;
        return (number / 10) % 10;
    }
    
    std::string number_to_words(int n) {
        if (n < 0) return "минус " + number_to_words(-n);
        if (n < 20) {
            static const char* words[] = {
                "ноль", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять",
                "десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать",
                "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"
            };
            return words[n];
        }
        if (n < 100) {
            static const char* tens[] = {
                "", "", "двадцать", "тридцать", "сорок", "пятьдесят", 
                "шестьдесят", "семьдесят", "восемьдесят", "девяносто"
            };
            int ten = n / 10;
            int unit = n % 10;
            if (unit == 0) return tens[ten];
            return std::string(tens[ten]) + " " + number_to_words(unit);
        }
        if (n < 1000) {
            static const char* hundreds[] = {
                "", "сто", "двести", "триста", "четыреста", "пятьсот",
                "шестьсот", "семьсот", "восемьсот", "девятьсот"
            };
            int hundred = n / 100;
            int rest = n % 100;
            if (rest == 0) return hundreds[hundred];
            return std::string(hundreds[hundred]) + " " + number_to_words(rest);
        }
        return std::to_string(n);
    }
    
    int count_words(const std::string& s) {
        std::istringstream iss(s);
        std::string word;
        int count = 0;
        while (iss >> word) count++;
        return count;
    }
    
    int solve_kenguru_problem(int max_number, int word_count) {
        int best_number = -1;
        for (int i = max_number; i >= 1; i--) {
            if (has_unique_digits(i)) {
                std::string words = number_to_words(i);
                if (count_words(words) == word_count) {
                    best_number = i;
                    break;
                }
            }
        }
        return get_tens_digit(best_number);
    }
}
