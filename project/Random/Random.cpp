#include "Random.h"

namespace mawile {
	SeedParameter RandomShake::Calc() noexcept {
		(this->seed) = (this->seed) * 0x7df121 + 0x2490f3;
		return (this->seed) % 0x9194;
	}

	void RandomShake::Seed(SeedParameter seed) noexcept {
		(this->seed) = seed;
	}

	int RandomShake::Shake(int Min, int Max) noexcept {
		const double Fractal = ((1.0) / (0x7fff + 1.0));
		int Reuslt =
			Min + static_cast<int>((Max - Min + 1) * Fractal * Calc());

		return ((Reuslt > Max) ? Shake(Min, Max) : Reuslt);
	}

	double RandomShake::Shake(int Min, double Max) noexcept {
		return Shake(static_cast<double>(Min), Max);
	}

	double RandomShake::Shake(double Min, int Max) noexcept {
		return Shake(Min, static_cast<double>(Max));
	}

	double RandomShake::Shake(double Min, double Max) noexcept {
		const double Fractal = ((1.0) / (0x7fff + 1.0));

		long long int FixedMin = static_cast<long long int>(Min * doubleMax);
		long long int FixedMax = static_cast<long long int>(Max * doubleMax);

		long long int Result =
			FixedMin + static_cast<long long int>((FixedMax - FixedMin + 1) * Fractal * Calc());

		return ((Result > FixedMax) ? Shake(Min, Max) : static_cast<double>((Result) / static_cast<double>(doubleMax)));
	}

	RandomShake::RandomShake() noexcept {
		Seed(SEED);
	}
}