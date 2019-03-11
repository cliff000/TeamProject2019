#pragma once
#include "Scene.h"
class MainScene :
	public Scene
{
	enum {postPhase, attackPhase};

public:
	MainScene();
	~MainScene();

	virtual void load() {}
	virtual void update() {}
	virtual void draw() {}
};

