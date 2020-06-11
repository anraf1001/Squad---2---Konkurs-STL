#include "fibo.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& vec) {
    for (const auto el : vec) {
        out << el << ' ';
    }
    out << '\n';
    return out;
}

std::vector<int> fibonacci_1(const int sequence) {
    if (sequence <= 0) {
        return {};
    } else if (sequence == 1) {
        return {1};
    }
    std::vector<int> v(sequence, 1);
    std::adjacent_difference(v.begin(), v.end() - 1, v.begin() + 1, std::plus<int>{});
    return v;
}

struct sequence_generator {
public:
    sequence_generator()
        : current(0) {}

    int operator()() {
        int val = fibonacci_2(current);
        current++;
        return val;
    }

    int fibonacci_2(const int n) {
        if (n <= 1) {
            return 1;
        }
        return fibonacci_2(n - 2) + fibonacci_2(n - 1);
    }

private:
    int current;
};

std::vector<int> fibonacci_2(const int sequence) {
    std::vector<int> v;

    v.reserve(sequence);

    std::generate_n(std::back_inserter(v), sequence, sequence_generator());

    return v;
}

std::vector<int> fibonacci_3(const int sequence) {
    constexpr auto sqrt_5 = std::sqrt(5);

    if (sequence <= 0) {
        return {};
    } else if (sequence == 1) {
        return {1};
    }

    std::vector<int> result(sequence);
    std::generate(result.begin(), result.end(), [i{0}, &sqrt_5]() mutable {
        i++;
        return static_cast<int>((std::pow(1 + sqrt_5, i) - std::pow(1 - sqrt_5, i)) / (std::pow(2, i) * sqrt_5));
    });

    return result;
}

std::vector<int> fibonacci_4(const int sequence) {
    if (sequence <= 0) {
        return {};
    } else if (sequence == 1) {
        return {1};
    }
    std::vector<int> v(sequence, 1);

    auto it = v.begin();
    auto prev = it;
    auto current = *it++;
    std::for_each(it, v.end(),
                  [&current, &prev](int& n) { std::swap(n, current); current = n + *prev++; });
    return v;
}


std::vector<int> fibonacci_5(const int sequence) {
    if (sequence <= 0) {
        return {};
    } else if (sequence == 1) {
        return {1};
    }
    std::vector<int> result(sequence, 1);
    std::transform(result.begin(), result.end() - 2,
                   result.begin() + 1, result.begin() + 2,
                   std::plus<>());

    return result;
}

std::vector<int> fibonacci_6(const int sequence) {
    if (sequence <= 0) {
        return {};
    } else if (sequence == 1) {
        return {1};
    }
    std::vector<int> v(sequence, 1);

    const auto result = std::accumulate(v.begin(), v.end(), std::vector<int>{},
                                        [](const std::vector<int>& lhs, int rhs) {
                                            std::vector<int> currVec{lhs};
                                            if (lhs.size() < 2) {
                                                currVec.push_back(1);
                                            } else {
                                                auto start = currVec.rbegin();
                                                auto first = *start;
                                                start++;
                                                auto second = *start;
                                                currVec.push_back(first + second);
                                            }
                                            return currVec;
                                        });

    return result;
}

std::vector<int> fibonacci_7(const int sequence) {
    if (sequence <= 0) {
        return {};
    } else if (sequence == 1) {
        return {1};
    }
    std::vector<int> result;
    result.reserve(sequence);

    auto current = 1;
    auto one_before = 1;
    auto two_before = 0;
    result.push_back(current);

    for (int i = 2; i <= sequence; ++i) {
        current = one_before + two_before;
        two_before = one_before;
        one_before = current;
        result.push_back(current);
    }
    return result;
}
