#include "Unit1P.h"
#include "DxLib.h"
#include "keyboard.h"

void Unit1P::update() {
	state->update();
	if (isAbleToMove && !(isMoved))		//�s���\���s���ς݂łȂ��Ȃ画������
	{
		if (Key[KEY_INPUT_UP] >= 1)
		{
			addPos(-1, 0, player);
		}
		else if (Key[KEY_INPUT_DOWN] >= 1)
		{
			addPos(1, 0, player);
		}
		else if (Key[KEY_INPUT_LEFT] >= 1)
		{
			addPos(0, -1, player);
		}
		else if (Key[KEY_INPUT_RIGHT] >= 1)
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
	state->draw(100, 200, 64, 64);
	DrawBox(
		100 + pos[1] * 64,
		200 + pos[0] * 64,
		164 + (pos[1] + 1) * 64,
		264 + (pos[0] + 1) * 64,
		color,
		true
	);
}