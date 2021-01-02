#include "generators.h"


Generators::Generators()
{
	
}

double Generators::Distribution()
{
	auto h = (int)((_time) / WspQ);                                              //H =ziarno / 127773
	(_time) = 16807 * ((_time)-WspQ * h) - WspR * h;                      //X = 16807 * ((ziarno - (127773 *H)) - (2836*H)
	if ((_time) < 0) (_time) += Range;                                       // (ziarno<0) ziarno+2147483647
	return (double)_time / (double)Range;
}

double Generators::NormalDistributionGenerator(const pair<const int, const int> p)
{
	static default_random_engine generator(kSeed);
	normal_distribution<double> distribution(p.first, p.second);
	return distribution(generator);
}

double Generators::NormalDistributionGenerator2(const pair<const double, const double> p)
{
	return 0.0;
}

double Generators::ExponentialDistributionGenerator(const int average)
{
	static default_random_engine generator(kSeed);
	const exponential_distribution<double> distribution(average);
	return 1 / distribution(generator);
}
