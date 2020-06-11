#include <iostream>
#include <vector>

#include "palindrome.hpp"

int main() {
    const std::vector<std::pair<bool, std::string>> cases{
        {true, "kajak"},
        {true, "Kajak !?"},
        {true, "Aa ?bbaa"},
        {false, "kot"}};

    std::cout << "Testing isPalindromeEqual\n";
    for (const auto& testCase : cases) {
        auto result = isPalindromeEqual(testCase.second);

        if (result == testCase.first) {
            std::cout << "PASSED\n";
        } else {
            std::cout << std::boolalpha << "FAILED!!! (" << testCase.second << ") Expected: " << testCase.first << " Got: " << result << '\n';
        }
    }
    std::cout << '\n';

    std::cout << "Testing isPalindromeMismatch\n";
    for (const auto& testCase : cases) {
        auto result = isPalindromeMismatch(testCase.second);

        if (result == testCase.first) {
            std::cout << "PASSED\n";
        } else {
            std::cout << std::boolalpha << "FAILED!!! (" << testCase.second << ") Expected: " << testCase.first << " Got: " << result << '\n';
        }
    }
    std::cout << '\n';

    std::cout << "Testing isPalindromeReverse\n";
    for (const auto& testCase : cases) {
        auto result = isPalindromeReverse(testCase.second);

        if (result == testCase.first) {
            std::cout << "PASSED\n";
        } else {
            std::cout << std::boolalpha << "FAILED!!! (" << testCase.second << ") Expected: " << testCase.first << " Got: " << result << '\n';
        }
    }
    std::cout << '\n';

    std::cout << "Testing isPalindromeClassic\n";
    for (const auto& testCase : cases) {
        auto result = isPalindromeClassic(testCase.second);

        if (result == testCase.first) {
            std::cout << "PASSED\n";
        } else {
            std::cout << std::boolalpha << "FAILED!!! (" << testCase.second << ") Expected: " << testCase.first << " Got: " << result << '\n';
        }
    }
    std::cout << '\n';

    std::cout << "Testing isPalindromeMoveBackward\n";
    for (const auto& testCase : cases) {
        auto result = isPalindromeMoveBackward(testCase.second);

        if (result == testCase.first) {
            std::cout << "PASSED\n";
        } else {
            std::cout << std::boolalpha << "FAILED!!! (" << testCase.second << ") Expected: " << testCase.first << " Got: " << result << '\n';
        }
    }
    std::cout << '\n';

    std::cout << "Testing isPalindromeInnerProduct\n";
    for (const auto& testCase : cases) {
        auto result = isPalindromeInnerProd(testCase.second);

        if (result == testCase.first) {
            std::cout << "PASSED\n";
        } else {
            std::cout << std::boolalpha << "FAILED!!! (" << testCase.second << ") Expected: " << testCase.first << " Got: " << result << '\n';
        }
    }
    std::cout << '\n';

    std::cout << "Testing isPalindromeTransRed\n";
    for (const auto& testCase : cases) {
        auto result = isPalindromeTransRed(testCase.second);

        if (result == testCase.first) {
            std::cout << "PASSED\n";
        } else {
            std::cout << std::boolalpha << "FAILED!!! (" << testCase.second << ") Expected: " << testCase.first << " Got: " << result << '\n';
        }
    }
    std::cout << '\n';

    std::cout << "Testing isPalindromeLexico\n";
    for (const auto& testCase : cases) {
        auto result = isPalindromeLexico(testCase.second);

        if (result == testCase.first) {
            std::cout << "PASSED\n";
        } else {
            std::cout << std::boolalpha << "FAILED!!! (" << testCase.second << ") Expected: " << testCase.first << " Got: " << result << '\n';
        }
    }
    std::cout << '\n';

    std::cout << "Testing isPalindromeAll\n";
    for (const auto& testCase : cases) {
        auto result = isPalindromeAll(testCase.second);

        if (result == testCase.first) {
            std::cout << "PASSED\n";
        } else {
            std::cout << std::boolalpha << "FAILED!!! (" << testCase.second << ") Expected: " << testCase.first << " Got: " << result << '\n';
        }
    }
    std::cout << '\n';

    std::cout << "Testing isPalindromeNone\n";
    for (const auto& testCase : cases) {
        auto result = isPalindromeNone(testCase.second);

        if (result == testCase.first) {
            std::cout << "PASSED\n";
        } else {
            std::cout << std::boolalpha << "FAILED!!! (" << testCase.second << ") Expected: " << testCase.first << " Got: " << result << '\n';
        }
    }
    std::cout << '\n';

    std::cout << "Testing isPalindromeAny\n";
    for (const auto& testCase : cases) {
        auto result = isPalindromeAny(testCase.second);

        if (result == testCase.first) {
            std::cout << "PASSED\n";
        } else {
            std::cout << std::boolalpha << "FAILED!!! (" << testCase.second << ") Expected: " << testCase.first << " Got: " << result << '\n';
        }
    }
    std::cout << '\n';

    return 0;
}