#pragma once
#include "Lights.h"

class LightsH : public Lights {
	int count_lights;
public:
	LightsH() : Lights(3)
	{
		count_lights = set.GetMaxPower();
		set.InsElem(2);
	}

	virtual void switch_light();

	virtual void print_color();
};