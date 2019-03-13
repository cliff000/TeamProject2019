#pragma once
#include "Panel.h"
#include "Unit.h"
#include "Unit1P.h"
#include "Unit2P.h"
#include <vector>


class Stage
{

private:
	int table[3][9] = {						//二次元配列（１が自機位置）
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	//Unit* unit1;
	Unit1P* unit1p;
	Unit2P* unit2p;

	unsigned int color = 0;					//debug

	const int imageSize = 512;
	const double imageScale = 70.0 / imageSize;
	const double imageInterval = imageSize * imageScale;
	int image;
	int leftTopX = 40;
	int leftTopY = 160;

public:
	Stage();
	~Stage();

	virtual void update();
	virtual void draw();

	bool isAbleToMove(int cy, int cx, int y, int x, int player);	//移動可能かの確認
	void moveStage(int x, int y, int player);						//テーブルでの移動処理
	int getActualX(int x); //テーブル上のx座標を実際のx座標に変換する
	int getActualY(int y); //テーブル上のy座標を実際のy座標に変換する
	double getImageScale() { return imageScale; }


	//debug
	void printPosition();
	void printTable();
	//debug
};
