#include "MainScene.h"

#include "State.h"
#include "AttackState.h"
#include "DefenseState.h"
#include "ThrowState.h"
#include "keyboard.h"
#include "DxLib.h"


MainScene::MainScene()
{
	phase = attackPhase;
	one->changeState(new AttackState());
	two->changeState(new AttackState());
}


MainScene::~MainScene()
{
}

void MainScene::load() {

}

void MainScene::update() {
	if (phase == postPhase) {

	}
	else if (phase == attackPhase) {
		if (Key[KEY_INPUT_Z] == 1) {
			one->changeState(new AttackState());
			two->changeState(new AttackState());
		}
		if (Key[KEY_INPUT_X] == 1) {
			one->changeState(new DefenseState());
			two->changeState(new DefenseState());
		}
		if (Key[KEY_INPUT_C] == 1) {
			one->changeState(new ThrowState());
			two->changeState(new ThrowState());
		}
	}
}
void MainScene::draw() {
	if (phase == postPhase) {

	}
	else if (phase == attackPhase) {
		one->draw();
		two->draw();
	}
}