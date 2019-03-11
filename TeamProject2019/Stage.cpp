#include "Stage.h"


Stage::Stage()
{
	panel.resize(3);
	for (auto&e : panel)
		e = std::vector<Panel*>(3);
}


Stage::~Stage()
{
}
