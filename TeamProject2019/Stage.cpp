#include "Stage.h"
#include "DxLib.h"
#include "keyboard.h"


Stage::Stage()
{
	unit1p = new Unit1P();
	unit1p->setStage(this);
	table[1][0] += 1;									//ユニット配置

	unit2p = new Unit2P();
	unit2p->setStage(this);
	table[1][0] += 2;									//ユニット配置

	color = GetColor(0, 0, 255);						//debug
}

Stage::~Stage()
{
}

void Stage::update()
{
	unit1p->update();
	unit2p->update();
}

void Stage::draw()
{
	unit1p->draw();
	unit2p->draw();
}

bool Stage::isAbleToMove(int cy, int cx, int y, int x, int player)
{
	if ((cy + y >= 0) && (cy + y <= 2) && (cx + x >= 0) && (cx + x <= 2))
	{
		if (table[cy + y][cx + x] == 0 || table[cy + y][cx + x] != player)
			return true;
		else if ((table[cy + y][cx + x] == player))
			return false;
	}
	else
		return false;
	
}

void Stage::moveStage(int y, int x, int player)
{
	if (player == 1) {
		table[unit1p->getY()][unit1p->getX()] -= player;
		table[unit1p->getY() + y][unit1p->getX() + x] += player;
	}
	else if (player == 2)
	{
		table[unit2p->getY()][unit2p->getX()] -= player;
		table[unit2p->getY() + y][unit2p->getX() + x] += player;
	}
}

//debug
void Stage::printPosition()
{
	printfDx("position1P: %d, %d\n", unit1p->getX(), unit1p->getY());
}

void Stage::printTable()
{
	printfDx("table:\n %d %d %d\n %d %d %d\n %d %d %d\n",
		table[0][0], table[0][1], table[0][2],
		table[1][0], table[1][1], table[1][2],
		table[2][0], table[2][1], table[2][2]
	);
}



