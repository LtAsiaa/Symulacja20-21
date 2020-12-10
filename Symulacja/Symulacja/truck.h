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
	int getID() const;
	int getU() const; //getter units
	
	static const int seed_ = 123456;
	static double ExponentialDistributionGenerator(const int average);
	int getStan();
	void setStan(int stan);

private:
	//static int id_;
	int stan = -1;
	//const int kID_; //id truck
	//const int totalUnits_; //truck load capacity
	//int freeSpace; //free space on truck
};


#endif /*MODEL_TRUCK_H_*/
