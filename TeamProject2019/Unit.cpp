#include "Unit.h"
#include "keyboard.h"
#include "Dxlib.h"

Unit::Unit()
{
	existUnitCount++;					//自機数カウント
	position[0] = 1;					//Y座標
	position[1] = 0;					//X座標
	isMoved = true;						//行動可能にする
}


Unit::~Unit()
{
	existUnitCount--;

	delete state;
	state = nullptr;
}

void Unit::load() {

}


void Unit::update() {
	if (isAbleToMove && !(isMoved))		//行動可能かつ行動済みでないなら判定を取る
	{
		if (Key[KEY_INPUT_UP] >= 1 and position[0] >= 1)
		{
			position[0]--;
			isMoved = false;
		}
		else if (Key[KEY_INPUT_DOWN] >= 1 and position[0] <= 1)
		{
			position[0]++;
			isMoved = false;
		}
		if (Key[KEY_INPUT_LEFT] >= 1 and position[0] >= 1)
		{
			position[1]--;
			isMoved = false;
		}
		else if (Key[KEY_INPUT_RIGHT] >= 1 and position[0] <= 1)
		{
			position[1]++;
			isMoved = false;
		}
	}
	else if (!(isAbleToMove))			//行動可能でないなら
	{
		isMoved = true;					//行動済み状態をリセットする
	}
}

void Unit::draw() {

}


void Unit::changeState(State* state) {
	delete this->state;
	this->state = state;
	this->state->setOwner(this);
}
