#pragma once
#include "Image.h"

//�O���錾
class Unit;
class AttackState;
class DefenseState;
class ThrowState;
class BlockState;

class State
{
protected:
	int img;
	Unit* owner; //����state�̏�����

public:
	State();
	~State();

	virtual void update() {}
	virtual void draw(int x, int y, double extRate, bool turnFlag);

	void setOwner(Unit* owner);

	//���j�b�g���m���Փ˂������̏���
	void hitAction(State* other);
	//�ȉ��̃N���X���I�[�o�[���C�h���Ďg��
	virtual void hitAction(AttackState* other){}
	virtual void hitAction(DefenseState* other){}
	virtual void hitAction(ThrowState* other){}
	virtual void hitAction(BlockState* other){}
};

