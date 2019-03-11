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
		if (Key[KEY_INPUT_UP] == 1 && pos[0] >= 1)
		{
			table[pos[0]][pos[1]] = 0;
			pos[0]--;
			table[pos[0]][pos[1]] = 1;
			isMoved = false;
		}
		else if (Key[KEY_INPUT_DOWN] == 1 && pos[0] <= 1)
		{
			table[pos[0]][pos[1]] = 0;
			pos[0]++;
			table[pos[0]][pos[1]] = 1;
			isMoved = false;
		}

		if (Key[KEY_INPUT_LEFT] == 1 && pos[1] >= 1)
		{
			table[pos[0]][pos[1]] = 0;
			pos[1]--;
			table[pos[0]][pos[1]] = 1;
			isMoved = false;
		}
		else if (Key[KEY_INPUT_RIGHT] == 1 && pos[1] <= 1)
		{
			table[pos[0]][pos[1]] = 0;
			pos[1]++;
			table[pos[0]][pos[1]] = 1;
			isMoved = false;
		}
	}
	else if (!(isAbleToMove))			//�s���\�łȂ��Ȃ�
	{
		isMoved = true;					//�s���ςݏ�Ԃ����Z�b�g����
	}
	if (Key[KEY_INPUT_R])				//debug
	{
		isAbleToMove = false;
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

void Stage::printPosition()
{
	printfDx("position: %d, %d\n", pos[0], pos[1]);
}
