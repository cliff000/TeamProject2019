#pragma once
#include "State.h"

class AttackState
{
public:
	AttackState();
	~AttackState();

	virtual void update() {}
	virtual void draw() {}
	virtual void drawFlip() {}
};