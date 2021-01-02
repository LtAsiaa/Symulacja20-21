#include "process.h"


Process::Process(Event_list* listt, int id, double size, int phase) : terminated_(false), event_list_(listt), id_(++id), size_(size), phase_(phase)
{
	Logger::GetInstance()->Print(("\nProcess: New process created!"), Logger::L2);
	//cerr << "\nProcess: New process created!";
	my_event_ = new Event(this);
	idx_ = 0;
	
}

Process::~Process()
{
	Logger::GetInstance()->Print(("\nProcess destruktor"), Logger::L2);
	//cout << "Process destruktor\n";
	delete my_event_;
}

double Process::time()
{
	return my_event_->event_time_;
}

void Process::Info()
{
	Logger::GetInstance()->Print(("\nID: " + to_string(id_) + " FAZA: " + to_string(phase_)+ "  CZAS:  " + to_string(time()) + "\n"), Logger::L4);
	//cout << "\nID: " << id_ << "  FAZA: " << phase_<<"   CZAS: " << time() << endl;
}

void Process::activate(const double time)
{
		Logger::GetInstance()->Print(("\nscheduled time: " + to_string(time)), Logger::L4);
		//cout << "\nscheduled time: " << time << endl;
		my_event_->event_time_ = time;
		event_list_->AddNewEvent(my_event_);
}

void Process::TimeUpdate(const double new_time)
{
	my_event_->event_time_ = new_time;
}


