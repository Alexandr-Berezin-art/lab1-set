#include <iostream>

#include "LightsC.h"
#include "LightsH.h"


int main() {
	LightsC car;
	LightsH human;

	car.print_color();
	human.print_color();
	std::cout << "---------------------" << std::endl;
	car.switch_light();
	human.switch_light();
	car.print_color();
	human.print_color();
	std::cout << "---------------------" << std::endl;
	car.switch_light();
	human.switch_light();
	car.print_color();
	human.print_color();
	std::cout << "---------------------" << std::endl;
	car.switch_light();
	human.switch_light();
	car.print_color();
	human.print_color();
	std::cout << "---------------------" << std::endl;
	car.switch_light();
	human.switch_light();
	car.print_color();
	human.print_color();
	std::cout << "---------------------" << std::endl;
	car.switch_light();
	human.switch_light();
	car.print_color();
	human.print_color();
	std::cout << "---------------------" << std::endl;
	car.switch_light();
	human.switch_light();
	car.print_color();
	human.print_color();
}