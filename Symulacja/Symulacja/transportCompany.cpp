#include "transportCompany.h"
#include <iostream>


TransportCompany::TransportCompany()
{
	for (int i = 0; i < kNofTruck; i++)
	{
		Truck* temp = new Truck(event_list_, i);
		truck_.push_back(temp);
	}
	headquarters_ = new Headquarters();
}

TransportCompany::~TransportCompany()
{

}

void TransportCompany::truckControl()
{
	for(int i=0; i<kNofTruck; i++)
	{
		if (truck_[i]->getStan()==-1)
		{
			continue;
		}
		if (truck_[i]->getStan() == 0)
		{
			headquarters_->AddToQueueTruck(truck_[i]);
		}
	}
}

