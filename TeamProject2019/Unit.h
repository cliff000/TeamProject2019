#pragma once
#include "State.h"
#include "DefenseState.h"

#define MAXUNITS 2

class Stage;

class Unit
{
private:
	int player;

protected:
	Stage* stage;
	State* state = new DefenseState();

	static int existUnitCount;			//���ݎ��@���j�b�g��
	bool isAbleToMove;					//�s���\���ۂ��i���Y���}�l�[�W���[���j
	bool isMoved;						//�s���ς݂��ۂ�
	int pos[2] = { 0, 0 };				//���ݍ��W�iY, X�j

	unsigned int color;					//debug

public:
	Unit();
	~Unit();

	int getX();
	int getY();

	int getPlayer();

	void addPos(int x , int y, int player);

	virtual void load(){}
	virtual void update(){}
	virtual void draw(){}

	void changeState(State* state);
	void hitAction(Unit* other);
	void setStage(Stage* stage);
};

