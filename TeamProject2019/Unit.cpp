#include "DxLib.h"
#include "Unit.h"
#include "keyboard.h"

Unit::Unit()
{
	existUnitCount++;					//���@���J�E���g
	pos[0] = 1;					//Y���W
	pos[1] = 0;					//X���W
	isAbleToMove = true;				//�s���\�ɂ��Ă���
	isMoved = false;					//�s���ς݉���

	color = GetColor(0, 0, 255);		//debug
}


Unit::~Unit()
{
	delete state;
	state = nullptr;
}

void Unit::load() {
}

void Unit::update() {
	if (isAbleToMove && !(isMoved))		//�s���\���s���ς݂łȂ��Ȃ画������
	{
		if (Key[KEY_INPUT_UP] >= 1 && pos[0] >= 1)
		{
			pos[0]--;
			isMoved = false;
		}
		else if (Key[KEY_INPUT_DOWN] >= 1 && pos[0] <= 1)
		{
			pos[0]++;
			isMoved = false;
		}

		if (Key[KEY_INPUT_LEFT] >= 1 && pos[0] >= 1)
		{
			pos[1]--;
			isMoved = false;
		}
		else if (Key[KEY_INPUT_RIGHT] >= 1 && pos[0] <= 1)
		{
			pos[1]++;
			isMoved = false;
		}
	}
	else if (!(isAbleToMove))			//�s���\�łȂ��Ȃ�
	{
		isMoved = false;				//�s���ςݏ�Ԃ����Z�b�g����
	}
	if (Key[KEY_INPUT_R])				//debug
	{
		isMoved = false;
	}
}

void Unit::draw() {
	
	DrawBox(
		pos[1] * 40,
		pos[0] * 40,
		(pos[1] + 1) * 40,
		(pos[0] + 1) * 40,
		color,
		true
	);									//debug

}

int Unit::getX()
{
	return pos[1];
}

int Unit::getY()
{
	return pos[0];
}

void Unit::addPos(int x, int y)
{
	pos[1] += x;
	pos[0] += y;
}


void Unit::changeState(State* state) {
	delete this->state;
	this->state = state;
	this->state->setOwner(this);
}


void Unit::hitAction(Unit* other) {
	this->state->hitAction(other->state);
}
