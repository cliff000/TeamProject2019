#pragma once
#include "Panel.h"
#include "Unit.h"
#include "Unit1P.h"
#include "Unit2P.h"
#include <vector>


class Stage
{

private:
	int table[3][3] = {						//�񎟌��z��i�P�����@�ʒu�j
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	//Unit* unit1;
	Unit1P* unit1p;
	Unit2P* unit2p;

	unsigned int color = 0;					//debug

	const int imageSize = 512;
	const double imageScale = 70.0 / imageSize;
	int image;
	int leftTopX = 40;
	int leftTopY = 160;

public:
	Stage();
	~Stage();

	virtual void update();
	virtual void draw();

	bool isAbleToMove(int cy, int cx, int y, int x, int player);	//�ړ��\���̊m�F
	void moveStage(int x, int y, int player);						//�e�[�u���ł̈ړ�����
	int getActualX(int x); //�e�[�u�����x���W�����ۂ�x���W�ɕϊ�����
	int getActualY(int y); //�e�[�u�����y���W�����ۂ�y���W�ɕϊ�����


	//debug
	void printPosition();
	void printTable();
	//debug
};
