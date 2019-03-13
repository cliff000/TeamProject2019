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
	if (AudioManager::IsMovable() && !(isMoved))		//�s���\���s���ς݂łȂ��Ȃ画������
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
	else if (!(AudioManager::IsMovable()))			//�s���\�łȂ��Ȃ�
	{
		isMoved = false;				//�s���ςݏ�Ԃ����Z�b�g����
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
