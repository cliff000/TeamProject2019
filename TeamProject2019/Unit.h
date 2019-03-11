#pragma once
#include "Node.h"

#define MAXUNITS 2


class Unit :
	public Node
{
	enum Coordinate { X, Y };

private:
	bool isAbleToMove = false;			//行動可能か否か（リズムマネージャーより）
	bool isMoved = false;				//行動済みか否か
	int existUnitCount = 0;				//現在自機ユニット数

	int position[2] = { 0, 0 };			//現在座標（Y, X）

public:
	Unit();
	~Unit();

	virtual void load();
	virtual void update();
	virtual void draw();
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