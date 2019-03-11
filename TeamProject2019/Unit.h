#pragma once
#include "Node.h"
class Unit :
	public Node
{
public:
	Unit();
	~Unit();

	virtual void load();
	virtual void update();
	virtual void draw();
};

