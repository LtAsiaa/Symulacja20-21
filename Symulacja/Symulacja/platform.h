#pragma once
#include <queue>

#include "goods.h"
#include "truck.h"
class Platform
{
public:
	Truck* truck1;
	Goods* goods1;
	
	bool platformState();
	int getState();
	void setState(bool state_platform);
	bool state_platform;

	//const int nPlatformH_ = 3; //number of platform
	//vector<Platform*> platformH_; // vector onto platform in 
	
};

