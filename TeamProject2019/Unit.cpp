#include "DxLib.h"
#include "Unit.h"
#include "keyboard.h"
#include "Stage.h"

int Unit::existUnitCount = 0;

Unit::Unit()
{
	existUnitCount++;					//自機数カウント
	isAbleToMove = true;				//行動可能にしておく
	isMoved = false;					//行動済み解除
	stage->initialPossession(player);	//ユニット配置初期処理
}


Unit::~Unit()
{
	delete state;
	state = nullptr;

	existUnitCount--;
}

int Unit::getX()
{
	return pos[1];
}

int Unit::getY()
{
	return pos[0];
}

int Unit::getPlayer()
{
	return player;
}


void Unit::addPos(int y, int x, int player)
{
	if (stage->isAbleToMove(pos[0], pos[1], y, x, player)) {
		stage->moveStage(y, x, player);
		pos[0] += y;
		pos[1] += x;
	}

	isMoved = true;
}

void Unit::setPos(int y, int x, int player)
{
	stage->setStage(y, x, player);
	pos[0] = y;
	pos[1] = x;
}

void Unit::changeState(State* state) {
	delete this->state;
	this->state = state;
	this->state->setOwner(this);
}

void Unit::hitAction(Unit* other) {
	this->state->hitAction(other->state);
}
void Unit::setStage(Stage* stage) {
	this->stage = stage;
}
