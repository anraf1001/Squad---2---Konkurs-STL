#include "reverseVector.hpp"

int main() {
    std::vector<int> vec{1, 2, 3, 4};
    print(vec);
    print(reverse1(vec));
    print(reverse2(vec));
    print(reverse3(vec));
    print(reverse4(vec));
    print(reverse5(vec));
    print(reverse6(vec));  //Warning! The function requires a small vector. The level of stupidity is over 9000 :)
}
