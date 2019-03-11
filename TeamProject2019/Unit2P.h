#pragma once
#include "Unit.h"

class Unit2P : public Unit
{
public:
	Unit2P() {}
	~Unit2P() {}

	virtual void update();
	virtual void draw();
};