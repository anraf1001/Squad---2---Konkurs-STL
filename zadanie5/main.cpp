#include <iostream>
#include <tuple>
#include <vector>

#include "anagram.hpp"

int main() {
    std::vector<std::tuple<bool, std::string, std::string>> cases{
        std::make_tuple(true, "Ala ma kota", "Ala ma kota"),
        std::make_tuple(false, "Ala ma kota", "Ala na kota"),
        std::make_tuple(true, "", ""),
        std::make_tuple(true, " ", " "),
        std::make_tuple(false, "", " "),
        std::make_tuple(false, "Ala ma kota", "Ala ma kota "),
        std::make_tuple(false, "Ala ma kota ", "Ala ma kota"),
        std::make_tuple(false, "", "Ala ma kota"),
        std::make_tuple(false, "Ala ma kota", ""),

    };

    for (const auto& testCase : cases) {
        auto result = annagramReduce(std::get<1>(testCase), std::get<2>(testCase));
        if (result == std::get<0>(testCase)) {
            std::cout << "\t\tPASSED!";
        } else {
            std::cout << "!!!FAILED! Expected : " << std::get<0>(testCase) << ", got : " << result
                      << " for strings: '" << std::get<1>(testCase) << "' , '" << std::get<2>(testCase);
        }
        std::cout << '\n';
    }
    return 0;
}