#pragma once
#include "State.h"
#define MAXUNITS 2

class Unit
{
	enum Coordinate { X, Y };

private:
	int existUnitCount = 0;				//���ݎ��@���j�b�g��
	bool isAbleToMove = true;			//�s���\���ۂ��i���Y���}�l�[�W���[���j
	bool isMoved = false;				//�s���ς݂��ۂ�
	int pos[2] = { 0, 0 };			//���ݍ��W�iY, X�j
	
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
	����Ȋ����H
*/