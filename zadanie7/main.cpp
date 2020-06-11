#include <iostream>
#include <vector>

#include "duplicates.hpp"

int main() {
    const std::vector<std::pair<std::string, std::string>> cases{
        {"Ala ma kota, a kot ma Ale.", "Ala ma ma kota, a kot ma ma Ale Ale."},
        {"", ""},
        {"Ala ma kota, a kot ma Ale.", "Ala Ala ma kota kota, a kot ma ma ma Ale."},
        {"Kot", "Kot"}};

    std::cout << "Testing removing duplicates\n";
    for (const auto& testCase : cases) {
        auto result = removeDuplicates(testCase.second);
        if (result == testCase.first) {
            std::cout << "PASSED\n";
        } else {
            std::cout << std::boolalpha << "FAILED!!! (" << testCase.second << ") Expected: " << testCase.first << " Got: " << result << '\n';
        }
    }

    return 0;
}