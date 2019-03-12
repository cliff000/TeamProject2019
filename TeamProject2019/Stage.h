#pragma once
#include "Panel.h"
#include "Unit.h"
#include <vector>


class Stage
{

private:
	int table[3][3] = {						//二次元配列（１が自機位置）
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	Unit* unit1;

	unsigned int color = 0;					//debug
	
public:
	Stage();
	~Stage();

	void update();
	void draw();

	bool isAbleToMove(int cy, int cx, int y, int x);	//移動可能かの確認
	void moveStage(int x, int y);						//テーブルでの移動処理

	//debug
	void printPosition();
	void printTable();
	//debug
};
