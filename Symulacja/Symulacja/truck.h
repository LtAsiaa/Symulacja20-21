#ifndef MODEL_TRUCK_H_
#define MODEL_TRUCK_H_

#include "even_list.h"
#include "process.h"


using namespace std;

class Truck : public Process
{
public:
	Truck(Event_list*, int);
	~Truck();

	void execute(double);
	
	int getID();
	void setID(const int kID_);
	
	int getTotalU(); //getter units
	void setTotalU(const int totalUnits);

	int getStan();
	void setStan(int stan);

	int getFreeSpace();
	void setFreeSpace(int freeSpace);
	
	static const int seed_ = 123456;
	static double ExponentialDistributionGenerator(const int average);
	

private:
	//static int id_;
	int stan = -1;
	int kID_; //id truck
	const int totalUnits_ = 10; //truck load capacity
	int freeSpace; //free space on truck
};


#endif /*MODEL_TRUCK_H_*/
