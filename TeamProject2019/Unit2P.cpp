#include "Unit2P.h"
#include "DxLib.h"
#include "keyboard.h"

void Unit2P::update() {
	state->update();
	if (isAbleToMove && !(isMoved))		//行動可能かつ行動済みでないなら判定を取る
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
	state->draw(400 + pos[1] * 64, 200 + pos[0] * 64, -64, 64);
}

/*int Unit2P::isPlayer()
{
	return 2;
}*/
