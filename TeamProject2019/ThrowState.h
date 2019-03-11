#pragma once
#include "State.h"

class ThrowState
{
public:
	ThrowState();
	~ThrowState();

	virtual void update() {}
	virtual void draw() {}
	virtual void drawFlip() {}
};