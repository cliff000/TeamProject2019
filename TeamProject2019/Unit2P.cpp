#include "Unit2P.h"
#include "DxLib.h"
#include "keyboard.h"
#include "Stage.h"
#include "AudioManager.h"

Unit2P::Unit2P()
{
	Unit::Unit();
	pos[0] = 1;
	pos[1] = 7;
}

void Unit2P::update() {
	state->update();
	if (AudioManager::IsMovable() && !(isMoved))		//行動可能かつ行動済みでないなら判定を取る
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

void Unit2P::draw() {
	state->draw(stage->getActualX(pos[1]), stage->getActualY(pos[0]), stage->getImageScale(), true);
}

/*int Unit2P::isPlayer()
{
	return 2;
}*/
