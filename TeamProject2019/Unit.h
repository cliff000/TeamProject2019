#pragma once
#include "State.h"
#define MAXUNITS 2

class Unit
{
	enum Coordinate { X, Y };

private:
	int existUnitCount = 0;				//現在自機ユニット数
	bool isAbleToMove = true;			//行動可能か否か（リズムマネージャーより）
	bool isMoved = false;				//行動済みか否か
	int pos[2] = { 0, 0 };			//現在座標（Y, X）
	
protected:
	State* state = new State();

	unsigned int color = 0;				//debug

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
};

/*
	  0 1 2
	 -------
	0| | | |
	1| | | |
	2| | | |
	 -------
	こんな感じ？
*/