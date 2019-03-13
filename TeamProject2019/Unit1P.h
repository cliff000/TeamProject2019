#pragma once
#include "Unit.h"

class Unit1P : public Unit
{
private:
	int player = 1;

public :
	Unit1P();
	~Unit1P() {}

	virtual void update();
	virtual void draw();
};