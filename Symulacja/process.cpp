#include "process.h"

Process::Process(Event_list* listt, int id, double size, int phase, int id_p) : terminated_(false), event_list_(listt), id_(id), size_(size), phase_(phase), id_p_(++id_p)
{
	//cerr << "\nProcess: New process created!";
	my_event_ = new Event(this);
	idx_ = 0;
	tim = 0;
}

Process::~Process()
{
	Logger::GetInstance()->Print(("\nProcess destruktor"), Logger::L3);
	delete my_event_;
}

double Process::time()
{
	return my_event_->event_time_;
}

void Process::Info()
{
	Logger::GetInstance()->Print(("\nID: " + to_string(id_) + " FAZA: " + to_string(phase_) + "  CZAS:  " + to_string(time())+ "IDP: " + to_string(id_p_) + "\n"), Logger::L4);
	//cout << "\nID: " << id_ << "  FAZA: " << phase_<<"   CZAS: " << time() << "IDP: " << id_p_ << endl;
}

void Process::activate(const double time)
{

		//cout << "\nscheduled time: " << time << endl;
		my_event_->event_time_ = time;
		event_list_->AddNewEvent(my_event_);
}

void Process::TimeUpdate(const double new_time)
{
	my_event_->event_time_ = new_time;
}


