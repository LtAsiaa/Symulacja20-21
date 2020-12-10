#ifndef MODEL_TransportCompany_H_
#define MODEL_TransportCompany_H_

#include "truck.h"
#include "goods.h"
#include "headquarters.h"
#include "regionalDepots.h"
#include <queue>
#include <vector>

class TransportCompany
{
public:
	TransportCompany();
	~TransportCompany();
	
	vector <Truck*> truck_;

	Goods* goods_;
	Headquarters* headquarters_;
	RegionalDepots* regionaldepots_;
	Event_list* event_list_;

	void truckControl();

	
private:
	const int kNofTruck = 8;
	const int kNofDepot = 6;
	
};

#endif /*MODEL_TransportCompany_H_*/