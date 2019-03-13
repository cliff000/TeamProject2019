#pragma once
#include "State.h"

#define MAXUNITS 2

class Stage;

class Unit
{
private:
	int player;

protected:
	Stage* stage;
	State* state = new State();

	static int existUnitCount;			//現在自機ユニット数
	bool isMoved;						//行動済みか否か
	int pos[2] = { 0, 0 };				//現在座標（Y, X）

public:
	Unit();
	~Unit();

	int getX();
	int getY();

	int getPlayer();

	void addPos(int x , int y, int player);
	void setPos(int x , int y, int player, int index);

	virtual void load(){}
	virtual void update(){}
	virtual void draw(){}

	void changeState(State* state);
	void hitAction(Unit* other);
	void setStage(Stage* stage);
};

