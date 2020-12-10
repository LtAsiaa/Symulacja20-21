#include "headquarters.h"
#include "truck.h"
#include <queue>
#include <iostream>

Headquarters::Headquarters()
{
	bool state_platform = false;
}
Headquarters::~Headquarters()
{
				
}

void Headquarters::AddToQueueTruck(Process* truck)
{
	queue_.push(truck);
}

Truck* Headquarters::GetFromQueue()
{
	return queue_to_platform_.front();
}

void Headquarters::AddToQueueGoods(Goods* goods)
{
	goods_queue.push(goods);
}

void Headquarters::PlaceTruckontoPlatform()
{
	
}


