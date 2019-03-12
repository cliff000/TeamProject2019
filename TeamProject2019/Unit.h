#pragma once
#include "State.h"

#define MAXUNITS 2

class Stage;

class Unit
{
private:
	static int existUnitCount;			//���ݎ��@���j�b�g��
	bool isAbleToMove;					//�s���\���ۂ��i���Y���}�l�[�W���[���j
	bool isMoved;						//�s���ς݂��ۂ�
	int pos[2] = { 0, 0 };				//���ݍ��W�iY, X�j
	
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
	����Ȋ����H
*/
	void setStage(Stage* stage);
};

