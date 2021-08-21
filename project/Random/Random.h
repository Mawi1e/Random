#pragma once
#include <time.h>

using SeedParameter = unsigned int;
#define SEED static_cast<unsigned int>(time(0))
#define doubleMax (1e15)

namespace mawile {
	class RandomShake {
	public:
		void Seed(SeedParameter) noexcept;
		int Shake(int, int) noexcept;
		double Shake(int, double) noexcept;
		double Shake(double, int) noexcept;
		double Shake(double, double) noexcept;

		explicit(true) RandomShake() noexcept;

	private:
		SeedParameter Calc() noexcept;

		SeedParameter seed;
	};
}