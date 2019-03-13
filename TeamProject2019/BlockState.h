#pragma once
#include "State.h"

class Stage;

class BlockState :
	public State
{
protected:
	Stage * stage;

public:
	BlockState();
	~BlockState();
};

