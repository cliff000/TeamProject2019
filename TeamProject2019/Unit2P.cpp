#include "Unit2P.h"
#include "DxLib.h"
#include "keyboard.h"

void Unit2P::update() {
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

void Unit2P::draw() {
	state->draw(400, 200, -64, 64);
	DrawBox(
		400 + pos[1] * 64,
		200 + pos[0] * 64,
		464 + (pos[1] + 1) * 64,
		264 + (pos[0] + 1) * 64,
		color,
		true
	);
}

int Unit2P::isPlayer()
{
	return 2;
}
