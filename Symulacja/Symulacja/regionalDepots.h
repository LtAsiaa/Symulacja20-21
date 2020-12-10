#ifndef MODEL_REGIONALDEPOTS_H_
#define MODEL_REGIONALDEPOTS_H_

#include <queue>

#include "goods.h"

class Truck;
class Headquarters;

class RegionalDepots
{
public:
	RegionalDepots();
	~RegionalDepots();
	
private:
	const int nPlatformD_; //number of platform in regional depots
	Truck* served_truck_;
	//std::queue<Truck*>
	//std::queue<Goods*>
};
#endif /*MODEL_REGIONALDEPOTS_H_*/