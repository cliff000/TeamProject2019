#pragma once
#include "Panel.h"
#include "Unit.h"
#include <vector>
#include "Unit.h"


class Stage	// :	public Node
{

private:
	int table[3][3] = {						//�񎟌��z��i�P�����@�ʒu�j
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	Unit* unit1;

	unsigned int color = 0;					//debug
	

public:
	Stage();
	~Stage();

	virtual void update();
	virtual void draw();

	

	void movePosition(int x, int y);		//�ړ����̃}�X���Z�b�g

	bool isKeyUp();
	bool isKeyDown();
	bool isKeyLeft();
	bool isKeyRight();


	//debug
	virtual void printPosition();
	//debug
};
