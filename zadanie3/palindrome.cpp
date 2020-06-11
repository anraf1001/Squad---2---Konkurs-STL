#include "palindrome.hpp"

#include <algorithm>
#include <numeric>

void prepareString(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    str.erase(std::remove_if(str.begin(), str.end(), [](auto letter) { return !isalnum(letter) && isprint(letter); }), str.end());
}

bool isPalindromeEqual(std::string str) {
    prepareString(str);
    return std::equal(str.cbegin(), std::next(str.cbegin(), str.size() / 2), str.crbegin());
}

bool isPalindromeMismatch(std::string str) {
    prepareString(str);
    return std::mismatch(str.cbegin(), str.cend(), str.crbegin(), str.crend()) == std::make_pair(str.cend(), str.crend());
}

bool isPalindromeReverse(std::string str) {
    prepareString(str);
    std::string reversed;
    std::reverse_copy(str.begin(), str.end(), std::back_inserter(reversed));
    return str == reversed;
}

bool isPalindromeClassic(std::string str) {
    prepareString(str);
    return str == std::string(str.crbegin(), str.crend());
}

bool isPalindromeMoveBackward(std::string str) {
    prepareString(str);
    std::string result;
    result.resize(str.size());
    std::move_backward(str.cbegin(), str.cend(), result.rend());
    return result == str;
}

bool isPalindromeInnerProd(std::string str) {
    prepareString(str);
    return std::inner_product(
        str.begin(), str.end(), str.rbegin(), true, std::multiplies<bool>(), [](char c1, char c2) {
            return !bool(c1 - c2);
        });
}

bool isPalindromeTransRed(std::string str) {
    prepareString(str);
    return std::transform_reduce(
        str.begin(), str.end(), str.rbegin(), true, std::multiplies<bool>(), [](char c1, char c2) {
            return !bool(c1 - c2);
        });
}

bool isPalindromeLexico(std::string str) {
    prepareString(str);
    return !std::lexicographical_compare(str.begin(), str.end(), str.rbegin(), str.rend()) &&
           !std::lexicographical_compare(str.rbegin(), str.rend(), str.begin(), str.end());
}

bool isPalindromeAll(std::string str) {
    prepareString(str);
    return std::all_of(str.begin(), str.end(), [i{-1}, &str](char c) mutable { i++; return c == *std::next(str.rbegin(), i); });
}

bool isPalindromeNone(std::string str) {
    prepareString(str);
    return std::none_of(str.begin(), str.end(), [i{-1}, &str](char c) mutable { i++; return c != *std::next(str.rbegin(), i); });
}

bool isPalindromeAny(std::string str) {
    prepareString(str);
    return !std::any_of(str.begin(), str.end(), [i{-1}, &str](char c) mutable { i++; return c != *std::next(str.rbegin(), i); });
}
