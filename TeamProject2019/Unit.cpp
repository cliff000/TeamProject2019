#include "DxLib.h"
#include "Unit.h"
#include "keyboard.h"


Unit::Unit()
{
	existUnitCount++;					//���@���J�E���g
	position[0] = 1;					//Y���W
	position[1] = 0;					//X���W
	isMoved = true;						//�s���\�ɂ��Ă���

	color = GetColor(0, 0, 255);		//debug
}


Unit::~Unit()
{
	existUnitCount--;
}

void Unit::load() {
}

void Unit::update() {
	if (isAbleToMove && !(isMoved))		//�s���\���s���ς݂łȂ��Ȃ画������
	{
		if (Key[KEY_INPUT_UP] >= 1 && position[0] >= 1)
		{
			position[0]--;
			isMoved = false;
		}
		else if (Key[KEY_INPUT_DOWN] >= 1 && position[0] <= 1)
		{
			position[0]++;
			isMoved = false;
		}

		if (Key[KEY_INPUT_LEFT] >= 1 && position[0] >= 1)
		{
			position[1]--;
			isMoved = false;
		}
		else if (Key[KEY_INPUT_RIGHT] >= 1 && position[0] <= 1)
		{
			position[1]++;
			isMoved = false;
		}
	}
	else if (!(isAbleToMove))			//�s���\�łȂ��Ȃ�
	{
		isMoved = true;					//�s���ςݏ�Ԃ����Z�b�g����
	}
}

void Unit::draw() {
	
	DrawBox(
		position[1] * 40,
		position[0] * 40,
		(position[1] + 1) * 40,
		(position[0] + 1) * 40,
		color,
		true
	);									//debug

}
