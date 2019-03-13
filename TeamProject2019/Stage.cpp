#include "Stage.h"
#include "Image.h"
#include "DxLib.h"
#include "keyboard.h"

#include "AttackState.h"
#include "DefenseState.h"
#include "ThrowState.h"
#include "BlockState.h"


Stage::Stage()
{
	unit1p = new Unit1P();
	unit1p->setStage(this);
	unit1p->setPos(1, 1, 1);
	unit1p->changeState(new DefenseState());

	block1p_1 = new Unit1P();
	block1p_1->setStage(this);
	block1p_1->setPos(0, 0, 1);
	block1p_1->changeState(new BlockState());

	block1p_2 = new Unit1P();
	block1p_2->setStage(this);
	block1p_2->setPos(1, 0, 1);
	block1p_2->changeState(new BlockState());

	block1p_3 = new Unit1P();
	block1p_3->setStage(this);
	block1p_3->setPos(2, 0, 1);
	block1p_3->changeState(new BlockState());


	unit2p = new Unit2P();
	unit2p->setStage(this);
	unit2p->setPos(1, 7, 2);
	unit2p->changeState(new DefenseState());

	block2p_1 = new Unit2P();
	block2p_1->setStage(this);
	block2p_1->setPos(0, 8, 2);
	block2p_1->changeState(new BlockState());

	block2p_2 = new Unit2P();
	block2p_2->setStage(this);
	block2p_2->setPos(1, 8, 2);
	block2p_2->changeState(new BlockState());

	block2p_3 = new Unit2P();
	block2p_3->setStage(this);
	block2p_3->setPos(2, 8, 2);
	block2p_3->changeState(new BlockState());

	image = Image::read("Assets/Image/frame.png");
}

Stage::~Stage()
{
	delete unit1p;
	delete unit2p;
	delete block1p_1;
	delete block1p_2;
	delete block1p_3;
	delete block2p_1;
	delete block2p_2;
	delete block2p_3;
}

void Stage::update()
{
	unit1p->update();
	unit2p->update();
}

void Stage::draw()
{
	//ステージの描画
	for (int i = 0;i < 3;i++)
	{
		for (int k = 0;k < 9;k++)
		{
			if (k != 0 && k != 4 && k != 8)
			{
				DrawRotaGraph(leftTopX + imageInterval * k,
					leftTopY + imageInterval * i,
					imageScale, 0, image, true);
			}
		}
	}

	unit1p->draw();
	block1p_1->draw();
	block1p_2->draw();
	block1p_3->draw();

	unit2p->draw();
	block2p_1->draw();
	block2p_2->draw();
	block2p_3->draw();
}

bool Stage::isAbleToMove(int cy, int cx, int y, int x, int player)
{
	if ((cx == 0) || (cx == 8))				//ブロックは動けないようにする
		return false;
	else if ((cy + y >= 0) && (cy + y <= 2) && (cx + x >= 1) && (cx + x <= 7) && (cx + x != 4))
	{
		if (table[cy + y][cx + x] == 0 || table[cy + y][cx + x] != player)
			return true;
		else if ((table[cy + y][cx + x] == player))
			return false;
		else
			return false;
	}
	else
		return false;
}

void Stage::moveStage(int y, int x, int player)
{
	Unit* u = unit1p;
	if (player == 1) {
		u = unit1p;
	}
	else if (player == 2){
		u = unit2p;
	}

	//共通の処理
	table[u->getY()][u->getX()] -= player;
	table[u->getY() + y][u->getX() + x] += player;

	if (u->getX() + x == 3 || u->getX() + x == 5) {
		u->changeState(new AttackState());
	}
	else if (u->getX() + x == 2 || u->getX() + x == 6) {
		u->changeState(new ThrowState());
	}
	else if (u->getX() + x == 1 || u->getX() + x == 7) {
		u->changeState(new DefenseState());
	}
}

void Stage::setStage(int y, int x, int player)
{
	if (player == 1) {
		table[unit1p->getY()][unit1p->getX()] -= player;
		table[y][x] += player;
	}
	else if (player == 2)
	{
		table[unit2p->getY()][unit2p->getX()] -= player;
		table[y][x] += player;
	}
}

void Stage::initialPossession(int player)
{
	if (player == 1) {
		table[unit1p->getY()][unit1p->getX()] += player;
	}
	else if (player == 2)
	{
		table[unit2p->getY()][unit2p->getX()] += player;
	}
}

double Stage::getActualX(double x) {
	return leftTopX + imageInterval * x;
}

double Stage::getActualY(double y) {
	return leftTopY + imageInterval * y;
}

//debug
void Stage::printPosition()
{
	printfDx("position1P: %d, %d\n", unit1p->getX(), unit1p->getY());
}

void Stage::printTable()
{
	printfDx("table:\n %d %d %d %d %d %d %d %d %d\n %d %d %d %d %d %d %d %d %d\n %d %d %d %d %d %d %d %d %d\n",
		table[0][0], table[0][1], table[0][2], table[0][3], table[0][4], table[0][5], table[0][6], table[0][7], table[0][8],
		table[1][0], table[1][1], table[1][2], table[1][3], table[1][4], table[1][5], table[1][6], table[1][7], table[1][8],
		table[2][0], table[2][1], table[2][2], table[2][3], table[2][4], table[2][5], table[2][6], table[2][7], table[2][8]
	);
}



