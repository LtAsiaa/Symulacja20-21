#pragma once
#include "even_list.h"
#include <iostream>

#include "event.h"

class Process
{
public:
	Process(Event_list*, int);
	~Process();
	double time();
	void Info();
	int phase_;
	void activate(double);
	void TimeUpdate(double);
	Event_list* event_list_;
	int id_;
	bool terminated_;
	
private:
	Event* my_event_;
};

