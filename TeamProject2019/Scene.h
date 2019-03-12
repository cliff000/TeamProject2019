#pragma once

class Scene
{
public:
	Scene();
	~Scene();

	virtual void load();
	virtual void update();
	virtual void draw();
};

