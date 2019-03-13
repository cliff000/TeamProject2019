#include "Unit1P.h"
#include "DxLib.h"
#include "keyboard.h"

void Unit1P::update() {
	state->update();
	if (isAbleToMove && !(isMoved))		//�s���\���s���ς݂łȂ��Ȃ画������
	{
		if (Key[KEY_INPUT_W] >= 1)
		{
			addPos(-1, 0, player);
		}
		else if (Key[KEY_INPUT_S] >= 1)
		{
			addPos(1, 0, player);
		}
		else if (Key[KEY_INPUT_A] >= 1)
		{
			addPos(0, -1, player);
		}
		else if (Key[KEY_INPUT_D] >= 1)
		{
			addPos(0, 1, player);
		}
	}
	else if (!(isAbleToMove))			//�s���\�łȂ��Ȃ�
	{
		isMoved = false;				//�s���ςݏ�Ԃ����Z�b�g����
	}

	//debug
	if (Key[KEY_INPUT_R])
	{
		isMoved = false;
	}
	//debug
}

void Unit1P::draw() {
	state->draw(100 + pos[1] * 64, 200 + pos[0] * 64, 64, 64);
}

/*int Unit1P::isPlayer()
{
	return 1;
}*/
