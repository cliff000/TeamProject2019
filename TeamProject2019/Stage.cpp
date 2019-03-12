#include "Stage.h"
#include "DxLib.h"
#include "keyboard.h"


Stage::Stage()
{
	unit1 = new Unit();
	table[unit1->getY()][unit1->getX()] = 1;			//���j�b�g�z�u

	

	color = GetColor(0, 0, 255);		//debug
}

Stage::~Stage()
{
}

void Stage::update() {
	unit1->update();
	/*if (isAbleToMove && !(isMoved))		//�s���\���s���ς݂łȂ��Ȃ画������
	{
		//�e�L�[���͂ɑ΂��鏈��
		if (isKeyUp() && pos[0] >= 1)
		{
			movePosition(0, -1);
		}
		else if (isKeyDown() && pos[0] <= 1)
		{
			movePosition(0, 1);
		}else if (isKeyLeft() && pos[1] >= 1)
		{
			movePosition(-1, 0);
		}
		else if (isKeyRight() && pos[1] <= 1)
		{
			movePosition(1, 0);
		}
	}
	else if (!(isAbleToMove))			//�s���\�łȂ��Ȃ�
	{
		isMoved = false;				//�s���ςݏ�Ԃ����Z�b�g����
	}
	if (Key[KEY_INPUT_R])				//debug
	{
		isMoved = false;
	}*/
}

void Stage::draw()
{
	unit1->draw();
}



void Stage::movePosition(int x, int y)
{
	table[unit1->getX()][unit1->getY()] = 0;
	if (x > 0)
		unit1->addPos(1, 0);
	else if (x < 0)
		unit1->addPos(-1, 0);
	if (y > 0)
		unit1->addPos(0, 1);
	else if (y < 0)
		unit1->addPos(0, -1);
	table[unit1->getX()][unit1->getY()] = 1;

	//isMoved = true;
}

bool Stage::isKeyUp()
{
	if (Key[KEY_INPUT_UP] == 1 || Key[KEY_INPUT_W] == 1)
		return true;
	else
		return false;
}

bool Stage::isKeyDown()
{
	if (Key[KEY_INPUT_DOWN] == 1 || Key[KEY_INPUT_S] == 1)
		return true;
	else
		return false;
}

bool Stage::isKeyLeft()
{
	if (Key[KEY_INPUT_LEFT] == 1 || Key[KEY_INPUT_A] == 1)
		return true;
	else
		return false;
}

bool Stage::isKeyRight()
{
	if (Key[KEY_INPUT_RIGHT] == 1 || Key[KEY_INPUT_D] == 1)
		return true;
	else
		return false;
}

//debug
void Stage::printPosition()
{
	printfDx("position: %d, %d\n", unit1->getX(), unit1->getY());
}
