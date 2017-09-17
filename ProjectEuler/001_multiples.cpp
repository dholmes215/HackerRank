#include <iostream>

int count(int nMinusOne, int divisor) {
    return nMinusOne/divisor;
}

int first(int nMinusOne, int divisor) {
    return divisor;
}

int last(int nMinusOne, int divisor) {
    return count(nMinusOne, divisor) * divisor;
}

int medianTimesTwo(int nMinusOne, int divisor) {
    return first(nMinusOne, divisor) + last(nMinusOne, divisor);
}

// Question: Could one devise a fixed-point number type such
// that we can leave out this "times two" stuff with zero overhead?

int sumTimesTwo(int nMinusOne, int divisor) {
    return medianTimesTwo(nMinusOne, divisor) * count(nMinusOne, divisor);
}

int sumForDivisor(int n, int divisor) {
    return sumTimesTwo(n-1, divisor) / 2;
}

int main() {

    int t;
    std::cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        std::cin >> n;

        int sum = sumForDivisor(n, 3) + sumForDivisor(n, 5) - sumForDivisor(n, 15);
        std::cout << sum << std::endl;
    }

    return 0;
}
