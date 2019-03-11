#pragma once
#include "Node.h"

class Scene
{
public:
	Scene();
	~Scene();

	virtual void load() {}
	virtual void update() {}
	virtual void draw() {}
};

