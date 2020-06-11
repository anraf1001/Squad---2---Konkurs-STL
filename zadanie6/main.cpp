#include <iostream>
#include <tuple>
#include <vector>

#include "wordsRemoving.hpp"

int main() {
    std::vector<std::tuple<std::string, std::string>> cases{
        std::make_tuple("", "KOTA"),
        std::make_tuple("Ala ma a kot ma Ale, to dawno.", "Ala ma kota a kot ma Ale, jednak to bylo dawno temu."),
        std::make_tuple("Ala ma", "Ala ma kota"),
        std::make_tuple("Ala ma ", "Ala ma kota "),
        std::make_tuple("Ala ma", "Ala ma kotare"),
        std::make_tuple(" ma", "Alan ma kota"),

    };

    for (const auto& testCase : cases) {
        auto result = stringWithWordsRemoved(std::get<1>(testCase));
        if (result == std::get<0>(testCase)) {
            std::cout << "\t\tPASSED!";
        } else {
            std::cout << "!!!FAILED! Expected : \n"
                      << std::get<0>(testCase) << ", got : \n"
                      << result
                      << " for strings: '" << std::get<1>(testCase);
        }
        std::cout << '\n';
    }
    return 0;
}