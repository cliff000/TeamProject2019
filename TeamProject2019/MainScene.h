#pragma once
#include "Scene.h"

#include "Unit.h"
#include "Unit1P.h"
#include "Unit2P.h"

class MainScene :
	public Scene
{
	enum {postPhase, attackPhase};	
	int phase = postPhase;

	Unit* one = new Unit1P();
	Unit* two = new Unit2P();

public:
	MainScene();
	~MainScene();

	virtual void load();
	virtual void update();
	virtual void draw();
};

