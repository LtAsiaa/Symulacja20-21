#ifndef MODEL_HEADQUARTERS_H_
#define MODEL_HEADQUARTERS_H_
#include <queue>
#include <vector>
#include "process.h"
#include "truck.h"
#include "goods.h"

class Headquarters
{
public:
	Headquarters();
	~Headquarters();
	void AddToQueueTruck(Process*);
	Truck* GetFromQueue();

	void AddToQueueGoods(Goods*);
	
	queue<Goods*> goods_queue;

	void PlaceTruckontoPlatform();
	
private:
	const int kNofPlatform = 3;
	queue<Truck*> queue_to_platform_; //Line of waiting trucks to the platforms
	std::queue<Goods*> queue_goods; //Line of all goods
	queue<Process*> queue_;
};

#endif /* MODEL_HEADQUARTERS_H_ */
