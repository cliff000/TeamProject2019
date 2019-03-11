#pragma once
#include "Node.h"

#define MAXUNITS 2


class Unit :
	public Node
{
	enum Coordinate { X, Y };

private:
	bool isAbleToMove = false;			//�s���\���ۂ��i���Y���}�l�[�W���[���j
	bool isMoved = false;				//�s���ς݂��ۂ�
	int existUnitCount = 0;				//���ݎ��@���j�b�g��

	int position[2] = { 0, 0 };			//���ݍ��W�iY, X�j

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
����Ȋ����H
*/