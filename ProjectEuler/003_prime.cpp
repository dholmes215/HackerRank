#include <cmath>
#include <iostream>

bool testPrime(uint64_t n) {

    uint64_t sqrtN = std::sqrt(n);

    for (uint64_t i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {

    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {

        uint64_t n;
        std::cin >> n;

        uint64_t sqrtN = std::sqrt(n);

        bool foundResult = false;

        for (uint64_t j = 1; j <= sqrtN; j++) {

            uint64_t testedFactor = n / j;

            if (j * testedFactor == n) {
                // testedFactor is a factor.
                if (testPrime(testedFactor)) {
                    std::cout << testedFactor << std::endl;
                    foundResult = true;
                    break;
                }
            }
        }

        if (!foundResult) {

            for (uint64_t testedFactor = sqrtN; testedFactor > 0; testedFactor--) {

                uint64_t j = n / testedFactor;

                if (j * testedFactor == n) {
                    // testedFactor is a factor.
                    if (testPrime(testedFactor)) {
                        std::cout << testedFactor << std::endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
