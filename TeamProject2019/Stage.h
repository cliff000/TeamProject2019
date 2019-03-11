#pragma once
#include "Node.h"
#include "Panel.h"
#include "Unit.h"
#include <vector>


class Stage :
	public Node
{
	std::vector<std::vector<Panel*>> panel;

public:
	Stage();
	~Stage();

	void setUnit(Unit* unit, int row, int );
};
