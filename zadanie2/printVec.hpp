#pragma once

#include <iostream>
#include <vector>

void printForEach(const std::vector<int>& vec);

void printForEachN(const std::vector<int>& vec);

void printRangeBased(const std::vector<int>& vec);

void printForIter(const std::vector<int>& vec);

void printForClassic(const std::vector<int>& vec);

void printCopy(const std::vector<int>& vec);

void printTransform(const std::vector<int>& vec);

std::ostream& operator<<(std::ostream& out, const std::vector<int>& vec);

void printMinMax(const std::vector<int>& vec);

struct printVector {
    void operator()(const int value);
};

void printFunc(const std::vector<int>& vec);

void printAccumulate(const std::vector<int>& vec);

void printGenerate(const std::vector<int>& vec);

void printGenerateN(const std::vector<int>& vec);

void printReverseCopy(const std::vector<int>& vec);
