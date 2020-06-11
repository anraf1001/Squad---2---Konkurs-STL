#include "printVec.hpp"

int main() {
    const std::vector<int> vectorToPrint = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printForEach(vectorToPrint);
    std::cout << '\n';
    printForEachN(vectorToPrint);
    std::cout << '\n';
    printRangeBased(vectorToPrint);
    std::cout << '\n';
    printForIter(vectorToPrint);
    std::cout << '\n';
    printForClassic(vectorToPrint);
    std::cout << '\n';
    printCopy(vectorToPrint);
    std::cout << '\n';
    printTransform(vectorToPrint);
    std::cout << '\n';
    std::cout << vectorToPrint;
    std::cout << '\n';
    printMinMax(vectorToPrint);
    std::cout << '\n';
    printFunc(vectorToPrint);
    std::cout << '\n';
    printAccumulate(vectorToPrint);
    std::cout << '\n';
    printGenerate(vectorToPrint);
    std::cout << '\n';
    printGenerateN(vectorToPrint);
    std::cout << '\n';
    printReverseCopy(vectorToPrint);
    std::cout << '\n';

    return 0;
}