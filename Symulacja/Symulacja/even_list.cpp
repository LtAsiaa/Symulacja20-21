#include "even_list.h"
#include <iostream>
#include "process.h"    //used for avoid warnings
using namespace std;

void Event_list::AddNewEvent(Event* add_event)
{
    if (first_ == nullptr) //If list is empty add event on first
    {
        first_ = last_ = add_event;
    }
    else if (add_event->event_time_ <= first_->event_time_) //Add event on beginning
    {
        first_->prev_ = add_event;
        add_event->next_ = first_;
        first_ = add_event;
    }
    else if (add_event->event_time_ >= last_->event_time_) //Add event on end
    {
        add_event->prev_ = last_;
        last_->next_ = add_event;
        last_ = add_event;
    }
    else {

        Event* search = first_;
        while (search->event_time_ <= add_event->event_time_)
        {
            search = search->next_;
        }
        add_event->next_ = search;
        add_event->prev_ = search->prev_;
        search->prev_->next_ = add_event;
        search->prev_ = add_event;
        search = nullptr;
    }
}