#pragma once
#include <random>
#include <string>
using namespace std;
class Generators
{
public:
	Generators();

	static const int kSeed = 123456;
	static const int WspQ = 127773;
	static const int WspR = 2836;
	static const int Range = 2147483647;
	double _time = 6000000;
	double Distribution();
	static double NormalDistributionGenerator(const pair<const int, const int> p);
	static double NormalDistributionGenerator2(const pair<const double, const double> p);
	static double ExponentialDistributionGenerator(const int average);
	
};

