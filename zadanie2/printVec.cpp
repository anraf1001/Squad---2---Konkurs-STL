#include "printVec.hpp"

#include <algorithm>
#include <iterator>
#include <numeric>

void printForEach(const std::vector<int>& vec) {
    std::for_each(vec.cbegin(), vec.cend(), [](auto value) {
        std::cout << value << " ";
    });
}

void printForEachN(const std::vector<int>& vec) {
    std::for_each_n(vec.cbegin(), vec.size(), [](auto value) {
        std::cout << value << " ";
    });
}

void printRangeBased(const std::vector<int>& vec) {
    for (const auto elem : vec) {
        std::cout << elem << " ";
    }
}

void printForIter(const std::vector<int>& vec) {
    for (auto it = vec.cbegin(); it != vec.cend(); it++) {
        std::cout << *it << " ";
    }
}

void printForClassic(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
}

void printCopy(const std::vector<int>& vec) {
    std::copy(vec.cbegin(), vec.cend(),
              std::ostream_iterator<int>(std::cout, " "));
}

void printTransform(const std::vector<int>& vec) {
    std::transform(vec.begin(), vec.end(),
                   std::ostream_iterator<int>(std::cout, " "),
                   [](int value) {
                       return value;
                   });
}

std::ostream& operator<<(std::ostream& out, const std::vector<int>& vec) {
    if (vec.empty()) {
        return out;
    }
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(out, " "));
    return out;
}

void printMinMax(const std::vector<int>& vec) {
    auto vectorRange = std::minmax_element(vec.begin(), vec.end());
    std::for_each(vectorRange.first, vectorRange.second + 1, [](int value) {
        std::cout << value << " ";
    });
}

void printVector::operator()(const int value) {
    std::cout << value << " ";
}

void printFunc(const std::vector<int>& vec) {
    std::for_each(vec.begin(), vec.end(), printVector());
}

void printAccumulate(const std::vector<int>& vec) {
    int sum = std::accumulate(vec.begin(), vec.end(), 0, [](int first, int second) {
        std::cout << second << " ";
        return first + second;
    });
}

void printGenerate(const std::vector<int>& vec) {
    std::vector<int> vec2(vec.size());

    std::generate(vec2.begin(), vec2.end(), [i{1}]() mutable {
        std::cout << i << " ";
        return i++;
    });
}

void printGenerateN(const std::vector<int>& vec) {
    std::vector<int> vec3(vec.size());
    std::generate_n(vec3.begin(), vec3.size(), [i{1}]() mutable {
        std::cout << i << " ";
        return i++;
    });
}

void printReverseCopy(const std::vector<int>& vec) {
    std::reverse_copy(vec.rbegin(), vec.rend(), std::ostream_iterator<int>(std::cout, " "));
}
