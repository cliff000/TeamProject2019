#pragma once
#include "Node.h"

class Scene : public Node
{
public:
	Scene();
	~Scene();

	virtual void load() {}
	virtual void update() {}
	virtual void draw() {}
};

