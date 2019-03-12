#include "DxLib.h"
#include "Unit.h"
#include "keyboard.h"
#include "Stage.h"

int Unit::existUnitCount = 0;

Unit::Unit()
{
	existUnitCount++;					//自機数カウント
	pos[0] = 1;							//Y座標
	pos[1] = 0;							//X座標
	isAbleToMove = true;				//行動可能にしておく
	isMoved = false;					//行動済み解除

	color = GetColor(0, 0, 255);		//debug
}


Unit::~Unit()
{
	delete state;
	state = nullptr;

	existUnitCount--;
}

void Unit::load() {
}

void Unit::update() {
	if (isAbleToMove && !(isMoved))		//行動可能かつ行動済みでないなら判定を取る
	{
		if (Key[KEY_INPUT_UP] >= 1)
		{
			addPos(-1, 0);
		}
		else if (Key[KEY_INPUT_DOWN] >= 1)
		{
			addPos(1, 0);
		}
		else if (Key[KEY_INPUT_LEFT] >= 1)
		{
			addPos(0, -1);
		}
		else if (Key[KEY_INPUT_RIGHT] >= 1)
		{
			addPos(0, 1);
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

void Unit::addPos(int y, int x)
{
	if (stage->isAbleToMove(pos[0], pos[1], y, x)) {
		stage->moveStage(y, x);
		pos[0] += y;
		pos[1] += x;
	}

	isMoved = true;
}


void Unit::changeState(State* state) {
	delete this->state;
	this->state = state;
	this->state->setOwner(this);
}

void Unit::setStage(Stage* stage) {
	this->stage = stage;
}
