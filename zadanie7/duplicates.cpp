#include "duplicates.hpp"

#include <algorithm>
#include <iterator>
#include <numeric>
#include <sstream>
#include <vector>

std::string removeDuplicates(const std::string& str) {
    if (str.empty() || str.find(' ') == std::string::npos) {
        return str;
    }

    std::istringstream iss(str);
    std::vector<std::string> words((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

    std::reverse(words.begin(), words.end());

    words.erase(std::unique(words.begin(), words.end(), [](auto lhs, auto rhs) {
                    lhs.erase(std::remove_if(lhs.begin(), lhs.end(), [](auto letter) { return !isalnum(letter) && isprint(letter); }), lhs.end());
                    rhs.erase(std::remove_if(rhs.begin(), rhs.end(), [](auto letter) { return !isalnum(letter) && isprint(letter); }), rhs.end());
                    return lhs == rhs;
                }),
                words.end());

    std::transform(words.begin() + 1, words.end(), words.begin() + 1, [](auto word) {
        word += ' ';
        return word;
    });

    return std::accumulate(words.rbegin(), words.rend(), std::string{}, [](auto sum, const auto& word) {
        sum += word;
        return sum;
    });
}
