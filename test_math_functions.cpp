#include <iostream>
#include <dlfcn.h>

int main() {
    void* handle = dlopen("./build/mathlib/libmathlib.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Failed to load library: " << dlerror() << std::endl;
        return 1;
    }
    
    // Загружаем функции
    typedef bool (*has_unique_digits_func)(int);
    typedef int (*get_tens_digit_func)(int);
    typedef int (*solve_func)(int, int);
    
    has_unique_digits_func has_unique_digits = 
        (has_unique_digits_func)dlsym(handle, "_ZN7MathLib16has_unique_digitsEi");
    get_tens_digit_func get_tens_digit = 
        (get_tens_digit_func)dlsym(handle, "_ZN7MathLib14get_tens_digitEi");
    solve_func solve_kenguru_problem = 
        (solve_func)dlsym(handle, "_ZN7MathLib19solve_kenguru_problemEii");
    
    if (!has_unique_digits || !get_tens_digit || !solve_kenguru_problem) {
        std::cerr << "Failed to load functions: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }
    
    // Тестируем
    std::cout << "Testing has_unique_digits(123): " << has_unique_digits(123) << std::endl;
    std::cout << "Testing has_unique_digits(112): " << has_unique_digits(112) << std::endl;
    std::cout << "Testing get_tens_digit(456): " << get_tens_digit(456) << std::endl;
    std::cout << "Testing solve_kenguru_problem(100, 2): " << solve_kenguru_problem(100, 2) << std::endl;
    
    dlclose(handle);
    return 0;
}
