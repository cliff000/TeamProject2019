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
	if (AudioManager::IsMovable() && !(isMoved))		//�s���\���s���ς݂łȂ��Ȃ画������
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

void Unit1P::draw() {
	state->draw(stage->getActualX(pos[1]), stage->getActualY(pos[0]), stage->getImageScale(), false);
}

/*int Unit1P::isPlayer()
{
	return 1;
}*/
