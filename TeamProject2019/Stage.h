#pragma once
#include "Panel.h"
#include "Unit.h"
#include "Unit1P.h"
#include "Unit2P.h"
#include <vector>

class Stage
{

private:
	int table[3][9] = { //�񎟌��z��i�P�����@�ʒu�j
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0}};
	Unit1P *unit1p;
	Unit1P *block1p_1;
	Unit1P *block1p_2;
	Unit1P *block1p_3;

	Unit2P *unit2p;
	Unit2P *block2p_1;
	Unit2P *block2p_2;
	Unit2P *block2p_3;

	unsigned int color = 0; //debug

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

	bool isAbleToMove(int cy, int cx, int y, int x, int player); //�ړ��\���̊m�F
	void moveStage(int x, int y, int player);					 //�e�[�u���ł̈ړ�����
	void setStage(int x, int y, int player);					 //�e�[�u���ł̔z�u�����i�����j
	void initialPossession(int player);							 //�e�[�u����������
	double getActualX(double x);								 //�e�[�u�����x���W�����ۂ�x���W�ɕϊ�����
	double getActualY(double y);								 //�e�[�u�����y���W�����ۂ�y���W�ɕϊ�����
	double getImageScale() { return imageScale; }

	//debug
	void printPosition();
	void printTable();
	//debug
};
