#pragma once
#include "Image.h"

class State
{
protected:
	int img;

public:
	State();
	~State();

	virtual void update() {}
	virtual void draw(double x, double y, double width, double height);
};

