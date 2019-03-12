#include "Unit2P.h"
#include "DxLib.h"
#include "keyboard.h"

void Unit2P::update() {
	state->update();
	if (isAbleToMove && !(isMoved))		//行動可能かつ行動済みでないなら判定を取る
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
	else if (!(isAbleToMove))			//行動可能でないなら
	{
		isMoved = false;				//行動済み状態をリセットする
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
