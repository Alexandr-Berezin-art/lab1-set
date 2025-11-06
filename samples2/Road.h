#pragma once
#include "LightsC.h"
#include "LightsH.h"

class Road
{
public:
	Road() {}
	void start_lights(int count_see = 4);

private:
	LightsC car;
	LightsH human;
};
