#include "truck.h"

#include <ctime>
#include <random>

#include "even_list.h"
#include "process.h"
#include "headquarters.h"



Truck::Truck(Event_list* list,  int id): Process(list, id)
{

}

void Truck::execute(const double new_time)
{
	TimeUpdate(new_time);
	Info();
	auto active = true;
	while (active)
	{
		switch (phase_)
		{
			case 0:
			{
				std::cerr << "\n -- Faza 0: Przyjazd do HQ --";
				Process* process = new Truck(event_list_, id_);
				process->activate(time() + ExponentialDistributionGenerator(2.2));
				process = nullptr;
				stan = 0;
				phase_ = 1;

				active = false;

			}
			break;
			case 1:
			{
				std::cerr << "\n -- Faza 1: Wjazd do platformy i roz³adunek --";
				
			
			}
			break;
			case 2:
			{
				std::cerr << "\n -- Faza 2: Za³adunek --";
			}
			break;
			case 3:
			{
				std::cerr << "\n -- Faza 3:Zakonczenie ³adunku i sprawdzenie stanu trucka --";
			}
			break;
			case 4:
			{
				std::cerr << "\n -- Faza 4:Jazda do odpowiedniego odbiorcy --";
			}
			break;
		}
	}
}

double Truck::ExponentialDistributionGenerator(const int average)
{
	static std::default_random_engine generator(seed_);
	const std::exponential_distribution<double> distribution(average);
	return 1 / distribution(generator);
}
int Truck::getStan()
{
	return stan;
}
void Truck::setStan(int stan)
{
	this->stan = stan;
}
Truck::~Truck()
{

}

