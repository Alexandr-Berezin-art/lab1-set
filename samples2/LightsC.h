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

	virtual void switch_light() {
		for (int i = 0; i < count_lights; i++) {
			if (set.IsMember(i)) {
				set.DelElem(i);
				set.InsElem( (i + 1) % 3);
				break;
			}
		}
	}

	virtual void print_color() {
		if (set.IsMember(0)) {
			std::cout << "Car: Green" << std::endl;
		}
		else if (set.IsMember(1)) {
			std::cout << "Car: Yellow" << std::endl;
		}
		else if (set.IsMember(2)) {
			std::cout << "Car: Red" << std::endl;
		}
	}
};