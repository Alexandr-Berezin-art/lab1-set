
#include "LightsC.h"
#include "LightsH.h"
#include "Road.h"


void LightsH::switch_light() {
		for (int i = 0; i < count_lights; i++) {
			if (set.IsMember(i)) {
				set.DelElem(i);
				set.InsElem((i + 1) % 3);
				break;
			}
		}
	}
	
	
void LightsC::switch_light() {
	for (int i = 0; i < count_lights; i++) {
		if (set.IsMember(i)) {
			set.DelElem(i);
			set.InsElem( (i + 1) % 3);
			break;
		}
	}
}
	
	
void LightsC::print_color()
{
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


void LightsH::print_color()
{
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
	
	
void Road::start_lights(int count_see)
{
	while(count_see-- > 0) {
		car.print_color();
		human.print_color();
		std::cout << "---------------------" << std::endl;
		car.switch_light();
		human.switch_light();
	}
}