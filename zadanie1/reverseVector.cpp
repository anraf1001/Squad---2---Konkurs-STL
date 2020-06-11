#include "reverseVector.hpp"

#include <algorithm>
#include <iostream>
#include <random>

void print(const std::vector<int>& vec) {
    for (auto it : vec) {
        std::cout << it << ' ';
    }
    std::cout << '\n';
}

std::vector<int> reverse1(std::vector<int> vec) {
    int conteiner;

    for (size_t first = 0; first < vec.size() / 2; first++) {
        conteiner = vec[vec.size() - first - 1];
        vec[vec.size() - first - 1] = vec[first];
        vec[first] = conteiner;
    }

    return vec;
}
std::vector<int> reverse2(const std::vector<int>& vec) {
    std::vector<int> copy(vec.size());
    std::move_backward(vec.begin(), vec.end(), copy.rend());

    return copy;
}

std::vector<int> reverse3(std::vector<int> vec) {
    std::reverse(std::begin(vec), std::end(vec));

    return vec;
}
std::vector<int> reverse4(std::vector<int> vec) {
    std::vector<int> copy(vec.size());
    std::reverse_copy(std::begin(vec), std::end(vec), std::begin(copy));

    return copy;
}

std::vector<int> reverse5(std::vector<int> vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        std::rotate(vec.begin(), vec.begin() + 1, vec.end() - i);
    }

    return vec;
}

std::vector<int> reverse6(std::vector<int> vec) {
    std::reverse(std::begin(vec), std::end(vec));
    std::vector<int> expectedVec = vec;
    std::reverse(std::begin(vec), std::end(vec));

    std::random_device rd;
    std::mt19937 g(rd());

    while (vec != expectedVec) {
        std::shuffle(vec.begin(), vec.end(), g);
    }

    return vec;
}
