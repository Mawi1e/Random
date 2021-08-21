#include <iostream>
#include "Random.h"

void Main(mawile::RandomShake* rShake) {
	rShake->Seed(SEED);

	for (int i = 1; i <= 300; ++i) {
		double Result = rShake->Shake(-3.1, 3.2);
		std::cout << Result << ' ';
		if (i % 5 == 0) {
			std::cout << '\n';
		}
	}

	std::cout << "\n\n";

	for (int i = 1; i <= 300; ++i) {
		int Result = rShake->Shake(1, 10);
		std::cout << Result << ' ';
		if (i % 5 == 0) {
			std::cout << '\n';
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cout << std::fixed;
	std::cout.precision(15);

	mawile::RandomShake* rShake = new mawile::RandomShake;

	Main(rShake);

	delete rShake;

	return (0);
}