#include "process.h"
using namespace std;
Process::Process(Event_list* list, int id) : phase_(0), event_list_(list), id_(++id)
{

}

Process::~Process()
{

}

double Process::time()
{
	return 0;
}

void Process::Info()
{

}

void Process::activate(const double time)
{
	cout << "\nscheduled time: " << time << endl;
	my_event_->event_time_ = time;
	event_list_->AddNewEvent(my_event_);
}

void Process::TimeUpdate(const double new_time)
{
	
}