#pragma once
#include <vector>


class Stage	// :	public Node
{

private:
	int table[3][3] = {						//�񎟌��z��
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	int pos[2] = {0, 0};					//���W�Ǘ��iY,X�j
	bool isAbleToMove = true;				//�s���\���ۂ��i���Y���I�Ɂj
	bool isMoved = true;					//�s���ς݂��ۂ�

	unsigned int color = 0;					//debug

public:
	Stage();
	~Stage();

	virtual void update();
	virtual void draw();

};
