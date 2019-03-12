#pragma once
#include "Unit.h"

class Unit2P : public Unit
{
private:
	int player = 2;

public:
	Unit2P() {}
	~Unit2P() {}

	virtual void update();
	virtual void draw();

	int isPlayer();
};