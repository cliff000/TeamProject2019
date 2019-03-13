#include "Unit1P.h"
#include "DxLib.h"
#include "keyboard.h"
#include "Stage.h"
#include "AudioManager.h"

Unit1P::Unit1P()
{
	Unit::Unit();
	pos[0] = 1;
	pos[1] = 1;
}

void Unit1P::update() {
	state->update();
	if (AudioManager::IsMovable() && !(isMoved))		//行動可能かつ行動済みでないなら判定を取る
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
	else if (!(AudioManager::IsMovable()))			//行動可能でないなら
	{
		isMoved = false;				//行動済み状態をリセットする
	}

	/*debug
	if (AudioManager::IsMovable())
	{
		isMoved = false;
	}
	//debug*/
}

void Unit1P::draw() {
	state->draw(stage->getActualX(pos[1]), stage->getActualY(pos[0]), stage->getImageScale(), false);
}

/*int Unit1P::isPlayer()
{
	return 1;
}*/
