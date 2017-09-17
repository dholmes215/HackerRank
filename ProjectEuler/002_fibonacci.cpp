#include <iostream>

int main() {

	int t;
	std::cin >> t;
	for (int i=0; i<t; i++) {

		uint64_t n;
		std::cin >> n;

		uint64_t sum = 0;
		uint64_t fibJMinus2 = 0;
		uint64_t fibJMinus1 = 1;
		uint64_t fibJ = 1;
		while (fibJ < n) {

			if (fibJ % 2 == 0) {
				sum += fibJ;
			}

			fibJMinus2 = fibJMinus1;
			fibJMinus1 = fibJ;
			fibJ = fibJMinus2 + fibJMinus1;
		}

		std::cout << sum << std::endl;;
	}


	return 0;
}
