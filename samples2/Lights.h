#include <iostream>

#include "tset.h"
#pragma once
class Lights {
protected:
	TSet set;
public:
	Lights(int cnt_condition) : set(TSet(cnt_condition))
	{ 	}
	virtual void switch_light() = 0;
	virtual void print_color() = 0;
};