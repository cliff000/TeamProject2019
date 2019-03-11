#pragma once
#include "Panel.h"
#include "Unit.h"
#include <vector>


class Stage
{
	std::vector<std::vector<Panel*>> panel;

public:
	Stage();
	~Stage();

};
