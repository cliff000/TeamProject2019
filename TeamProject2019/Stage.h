#pragma once
#include <vector>


class Stage	// :	public Node
{

private:
	int table[3][3] = {						//二次元配列
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	int pos[2] = {0, 0};					//座標管理（Y,X）
	bool isAbleToMove = true;				//行動可能か否か（リズム的に）
	bool isMoved = true;					//行動済みか否か

	unsigned int color = 0;					//debug

public:
	Stage();
	~Stage();

	virtual void update();
	virtual void draw();

};
