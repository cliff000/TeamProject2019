#pragma once
#include "State.h"

class DefenseState
{
public:
	DefenseState();
	~DefenseState();

	virtual void update() {}
	virtual void draw() {}
	virtual void drawFlip() {}
};