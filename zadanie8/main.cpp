#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

void printTree(int treeHeight) {
    if (treeHeight < 0)
        throw std::invalid_argument("Can't display trees that live underground");

    std::vector<std::string> rows(treeHeight);
    std::generate_n(rows.begin(), treeHeight, [i{0}, &treeHeight]() mutable {
        i++;
        return std::string(treeHeight - i, ' ') +
               std::string(2 * i - 1, '*') +
               std::string(treeHeight - i, ' ');
    });
    std::cout << std::accumulate(rows.begin(), rows.end(), std::string(),
                                 [](const std::string& total, const std::string& row) {
                                     return total + row + '\n';
                                 });
}

int main() {
    try {
        printTree(0);
        printTree(1);
        printTree(2);
        printTree(3);
        printTree(8);
        printTree(-3);
    } catch (const std::invalid_argument except) {
        std::cout << except.what() << '\n';
    }
    return 0;
}