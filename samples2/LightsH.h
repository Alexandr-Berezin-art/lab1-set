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

	virtual void switch_light() {
		for (int i = 0; i < count_lights; i++) {
			if (set.IsMember(i)) {
				set.DelElem(i);
				set.InsElem((i + 1) % 3);
				break;
			}
		}
	}

	virtual void print_color() {
		if (set.IsMember(0)) {
			std::cout << "Human: Green" << std::endl;
		}
		else if (set.IsMember(1)) {
			std::cout << "Human: Green" << std::endl;
		}
		else if (set.IsMember(2)) {
			std::cout << "Human: Red" << std::endl;
		}
	}
};