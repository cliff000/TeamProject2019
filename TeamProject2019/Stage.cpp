#include "Stage.h"
#include "DxLib.h"
#include "keyboard.h"


Stage::Stage()
{

	pos[0] = 1;							//Y���W
	pos[1] = 0;							//X���W
	table[pos[0]][pos[1]] = 1;			//���j�b�g�z�u

	isAbleToMove = true;				//�s���\�ɂ��Ă���
	isMoved = true;						//�s���ς݉���

	color = GetColor(0, 0, 255);		//debug
}

Stage::~Stage()
{
}

void Stage::update() {
	if (isAbleToMove && !(isMoved))		//�s���\���s���ς݂łȂ��Ȃ画������
	{
		//�e�L�[���͂ɑ΂��鏈��
		if (isKeyUp() && pos[0] >= 1)
		{
			movePosition(0, -1);
			isMoved = true;
		}
		else if (isKeyDown() && pos[0] <= 1)
		{
			movePosition(0, 1);
			isMoved = true;
		}

		if (isKeyLeft() && pos[1] >= 1)
		{
			movePosition(-1, 0);
			isMoved = true;
		}
		else if (isKeyRight() && pos[1] <= 1)
		{
			movePosition(1, 0);
			isMoved = true;
		}
	}
	else if (!(isAbleToMove))			//�s���\�łȂ��Ȃ�
	{
		isMoved = false;				//�s���ςݏ�Ԃ����Z�b�g����
	}
	if (Key[KEY_INPUT_R])				//debug
	{
		isMoved = false;
	}
}

void Stage::draw()
{

	DrawBox(
		pos[1] * 40,
		pos[0] * 40,
		(pos[1] + 1) * 40,
		(pos[0] + 1) * 40,
		color,
		true
	);

}

int Stage::getX()
{
	return pos[1];
}

int Stage::getY()
{
	return pos[0];
}

void Stage::movePosition(int x, int y)
{
	table[pos[0]][pos[1]] = 0;
	if (x > 0)
		pos[1]++;
	else if (x < 0)
		pos[1]--;
	if (y > 0)
		pos[0]++;
	else if (y < 0)
		pos[0]--;
	table[pos[0]][pos[1]] = 1;
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

void Stage::printPosition()
{
	printfDx("position: %d, %d\n", pos[0], pos[1]);
}
