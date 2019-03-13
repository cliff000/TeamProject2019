#include "State.h"
#include "DxLib.h"


State::State()
{
}


State::~State()
{
}

void State::draw(int x, int y, double extRate, bool turnFlag) {
	DrawRotaGraph(x, y, extRate, 0, img, true, turnFlag);
}

void State::setOwner(Unit* owner) {
	this->owner = owner;
}

void State::hitAction(State* other) {
	other->hitAction(this);
}