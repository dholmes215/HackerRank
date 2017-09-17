#include <cstdint>
#include <iostream>

uint64_t count(uint64_t nMinusOne, int divisor) {
    return nMinusOne/divisor;
}

uint64_t first(uint64_t nMinusOne, int divisor) {
    return divisor;
}

uint64_t last(uint64_t nMinusOne, int divisor) {
    return count(nMinusOne, divisor) * divisor;
}

uint64_t medianTimesTwo(uint64_t nMinusOne, int divisor) {
    return first(nMinusOne, divisor) + last(nMinusOne, divisor);
}

// Question: Could one devise a fixed-point number type such
// that we can leave out this "times two" stuff with zero overhead?

uint64_t sumTimesTwo(uint64_t nMinusOne, int divisor) {
    return medianTimesTwo(nMinusOne, divisor) * count(nMinusOne, divisor);
}

uint64_t sumForDivisor(uint64_t n, int divisor) {
    return sumTimesTwo(n-1, divisor) / 2;
}

int main() {

    int t;
    std::cin >> t;

    for (int i=0; i<t; i++) {
        uint64_t n;
        std::cin >> n;

        uint64_t sum = sumForDivisor(n, 3) + sumForDivisor(n, 5) - sumForDivisor(n, 15);
        std::cout << sum << std::endl;
    }

    return 0;
}
