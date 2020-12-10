#include <iostream>
#include "regionalDepots.h"
#include "truck.h"
#include "headquarters.h"


RegionalDepots::RegionalDepots():nPlatformD_(),served_truck_(nullptr)
{

}
RegionalDepots::~RegionalDepots()
{
	if (served_truck_ != nullptr)
		delete served_truck_;
}
