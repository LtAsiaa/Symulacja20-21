#ifndef MODEL_GOODS_H_
#define MODEL_GOODS_H_
#include "truck.h"

class Goods
{
public:
	Goods();
	~Goods();
	int iD;
	float size; //batches size (size r units) r - random variable following normal distribution
	//Truck* served_truck_; //pointer on Truck
};
#endif /*MODEL_GOODS_H_*/