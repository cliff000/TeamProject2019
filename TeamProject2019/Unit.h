#pragma once
#include "State.h"

#define MAXUNITS 2

class Stage;

class Unit
{
protected:
	Stage* stage;
	State* state = new State();

	static int existUnitCount;			//現在自機ユニット数
	bool isAbleToMove;					//行動可能か否か（リズムマネージャーより）
	bool isMoved;						//行動済みか否か
	int pos[2] = { 0, 0 };				//現在座標（Y, X）

	unsigned int color;					//debug

public:
	Unit();
	~Unit();

	int getX();
	int getY();

	void addPos(int x , int y, int player);

	virtual void load();
	virtual void update();
	virtual void draw();

	void changeState(State* state);
	void hitAction(Unit* other);
	void setStage(Stage* stage);
};

