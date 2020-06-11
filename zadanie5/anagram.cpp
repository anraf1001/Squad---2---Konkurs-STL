#include "anagram.hpp"

#include <algorithm>
#include <map>
#include <numeric>

bool annagramReduce(std::string str1, std::string str2) {
    if (str1.length() != str2.length())
        return false;

    std::map<char, int> charDifferencesCounter = std::inner_product(
        str1.begin(),
        str1.end(),
        str2.begin(),
        std::map<char, int>(),

        [](std::map<char, int> counter, const std::pair<char, char>& correspondingCharacters) {
            counter[correspondingCharacters.first]++;
            counter[correspondingCharacters.second]--;
            return counter;
        },
        [](char c1, char c2) {
            return std::make_pair(c1, c2);
        });

    return std::none_of(charDifferencesCounter.begin(), charDifferencesCounter.end(), [](const std::pair<char, int>& count) { return count.second != 0; });
}
