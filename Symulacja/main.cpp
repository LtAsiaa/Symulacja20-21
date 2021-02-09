#include <iostream>
#include <random>
#include "transportCompany.h"
#include "truck.h"
#include "event_list.h"
#include "goods.h"
#include "logger.h"
#include <fstream>
#include <string>

using namespace std;


int main()
{   
	//double time_truck = 0;
	//double truck = 0;
	
	printf("------------------------------------------------------------------------\n");
	printf("                           INITIALIZATION\n");
	printf("------------------------------------------------------------------------\n");

	int step_mode = 1;
	do
	{
		cerr << "Choose simulation mode (1 - step by step, 0 - continous): ";
		cin >> step_mode;
	} while (step_mode > 1 || step_mode < 0);
	int logger_verb;
	do
	{
		cerr << "Choose logger verbosity level (1-4): ";
		std::cin >> logger_verb;
	} while (logger_verb < 1 || logger_verb > 4);
	Logger::GetInstance()->SetLogVerbosity(static_cast<Logger::LogVerbosity>(logger_verb));


	printf("------------------------------------------------------------------------\n");
	printf("                           SIMULATION\n");
	printf("------------------------------------------------------------------------\n");

	TransportCompany* transportcompany = new TransportCompany;
	transportcompany->ClearExcel();
	const auto event_list = new Event_list;
	auto clock = 0.0;
	Process* current_process;
	for (int i = 0; i < 8; i++)
	{
		current_process = new Truck(event_list, transportcompany, i+1, 10, 0, 0);
		current_process->activate(0);
		current_process->Info();
	}
	
	for (int i = 0; i < 7; i++)
	{
		current_process = new Goods(event_list, transportcompany, Generators::Distribution(), Generators::NormalDistributionGenerator(make_pair(2.00, 0.36)), i, -1);
		current_process->activate(0);
		current_process->Info();
	}

	current_process = nullptr;
	
	double prev_clock = -1;
	int terminated_counter = 0;
	bool block = true;
	double f_p = 0;
	while(clock < 5000)
	{
		//Faza pocz¹tkowa zerowanie
		/*
		if (clock > 1000 and block == true)
		{
			f_p = clock;
			transportcompany->ClearStatistic();
			block = false;
		}
		*/
		auto current_event = event_list->RemoveFirst();

		current_process = current_event->proc_;
		clock = current_event->event_time_;
		//cerr << "Current clock: " << clock << endl;
		current_event = nullptr;
		current_process->execute(clock);

		if (prev_clock > clock)
		{
			Logger::GetInstance()->Print(("\nERROR! TIME TRAVEL!\n "), Logger::L4);
			cin.get();
		}			
		prev_clock = clock;

		if (step_mode)
		{
			Logger::GetInstance()->Print(("\n Press ENTER to continue..."), Logger::L1);
			cin.get();
		}
	}
	transportcompany->PrintStatistic(clock, f_p); 
	/*
	ofstream f;
	double tim;
	for (int i = 0; i < 10000; i++)
	{
		//tim = Generators::Distribution();
		tim = Generators::ExponentialDistributionGenerator(50);

		//f.open("excel/Distribution.csv", ios::app);
		f.open("excel/ExponentialDistributionGenerator.csv", ios::app);
		f << std::to_string(tim) << endl;
		f.close();
	}*/
	printf("------------------------------------------------------------------------\n");
	printf("                           FINISHED\n");
	printf("------------------------------------------------------------------------\n");
	system("Pause");
}
