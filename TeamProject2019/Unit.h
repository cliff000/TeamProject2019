#pragma once
#include "State.h"

#define MAXUNITS 2

class Stage;

class Unit
{
private:
	static int existUnitCount;			//現在自機ユニット数
	bool isAbleToMove;					//行動可能か否か（リズムマネージャーより）
	bool isMoved;						//行動済みか否か
	int pos[2] = { 0, 0 };				//現在座標（Y, X）
	
protected:
	Stage* stage;
	State* state = new State();
	unsigned int color;					//debug

public:
	Unit();
	~Unit();

	int getX();
	int getY();

	void addPos(int x , int y);

	virtual void load();
	virtual void update();
	virtual void draw();

	void changeState(State* state);
	void hitAction(Unit* other);

/*
	  0 1 2
	 -------
	0| | | |
	1| | | |
	2| | | |
	 -------
	こんな感じ？
*/
	void setStage(Stage* stage);
};

