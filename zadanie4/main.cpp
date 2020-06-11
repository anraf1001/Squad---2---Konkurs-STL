#include "fibo.hpp"

int main() {
    constexpr int num = 6;
    std::cout << fibonacci_1(num);
    std::cout << fibonacci_2(num);
    std::cout << fibonacci_3(num);
    std::cout << fibonacci_4(num);
    std::cout << fibonacci_5(num);
    std::cout << fibonacci_6(num);
    std::cout << fibonacci_7(num);
    std::cout << '\n';

    return 0;
}