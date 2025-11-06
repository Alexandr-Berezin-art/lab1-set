#pragma once
#include "Lights.h"

class LightsC: public Lights{
	int count_lights;
public:
	LightsC(): Lights(3)
	{	
		count_lights = set.GetMaxPower();
		set.InsElem(0);
	}

	virtual void switch_light();

	virtual void print_color();
};