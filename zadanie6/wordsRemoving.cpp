#include "wordsRemoving.hpp"

#include <algorithm>
#include <cctype>
#include <numeric>
#include <vector>

bool isPartOfWord(char c) {
    return isalpha(c);
}

int wordLengthRemoval(int i) {
    return (i == 4) || (i == 6);
}

std::string stringWithWordsRemoved(std::string sentence) {
    std::vector<int> alphaWordLength(sentence.length());
    std::transform(sentence.begin(), sentence.end(), alphaWordLength.begin(), isPartOfWord);
    // Now vector has correct name :)

    std::partial_sum(alphaWordLength.begin(), alphaWordLength.end(), alphaWordLength.begin(), [](int currentSum, int alpha) {
        return alpha == 1 ? currentSum + alpha : 0;
    });

    std::partial_sum(alphaWordLength.rbegin(), alphaWordLength.rend(), alphaWordLength.rbegin(), [](int currentSum, int wordLength) {
        return wordLength == 0 ? 0 : std::max(wordLength, currentSum);
    });

    std::string sentenceShortened;
    int charIdx = -1;
    std::copy_if(
        sentence.begin(), sentence.end(), std::back_inserter(sentenceShortened), [&charIdx, &sentence, &alphaWordLength](char c) {
            charIdx++;
            if (c == ' ') {
                if ((size_t)charIdx == sentence.length() - 1)
                    return true;
                if (!wordLengthRemoval(alphaWordLength[charIdx + 1]))
                    return true;
                return false;
            } else {
                return !wordLengthRemoval(alphaWordLength[charIdx]);
            }
        });
    return sentenceShortened;
}
