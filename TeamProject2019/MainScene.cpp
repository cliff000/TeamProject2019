#include "MainScene.h"

#include "State.h"
#include "AttackState.h"
#include "DefenseState.h"
#include "ThrowState.h"
#include "BlockState.h"
#include "keyboard.h"
#include "DxLib.h"


MainScene::MainScene()
{
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
	}
}
void MainScene::draw() {
	if (phase == postPhase) {

	}
	else if (phase == attackPhase) {
	}
}