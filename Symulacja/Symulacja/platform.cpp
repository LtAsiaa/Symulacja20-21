#include "platform.h"

int Platform::getState()
{
	return state_platform;
}
void Platform::setState(bool state_platform)
{
	this->state_platform = state_platform;
}

/*bool Platform::platformState()
{
	for (int i = 0; i < nPlatformH_; i++)
	{
		if (platformH_[i]->getState() == true)
		{

		}
	}
}*/
