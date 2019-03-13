#pragma once
#include "Image.h"

//前方宣言
class Unit;
class AttackState;
class DefenseState;
class ThrowState;
class BlockState;

class State
{
protected:
	int img;
	Unit* owner; //このstateの所持者

public:
	State();
	~State();

	virtual void update() {}
	virtual void draw(int x, int y, double extRate, bool turnFlag);

	void setOwner(Unit* owner);

	//ユニット同士が衝突した時の処理
	void hitAction(State* other);
	//以下のクラスをオーバーライドして使う
	virtual void hitAction(AttackState* other){}
	virtual void hitAction(DefenseState* other){}
	virtual void hitAction(ThrowState* other){}
	virtual void hitAction(BlockState* other){}
};

