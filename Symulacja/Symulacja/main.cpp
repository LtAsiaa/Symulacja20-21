#include <iostream>
#include <random>

using namespace std;

const int kSeed = 123456;
double ExponentialDistributionGenerator(const int average) {
	static std::default_random_engine generator(kSeed);
	const std::exponential_distribution<double> distribution(average);
	return 1 / distribution(generator);
}

int main()
{

	system("Pause");
}