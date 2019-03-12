#include "Stage.h"
#include "DxLib.h"
#include "keyboard.h"


Stage::Stage()
{
	unit1 = new Unit();
	unit1->setStage(this);
	table[1][0] = 1;									//ユニット配置

	color = GetColor(0, 0, 255);						//debug
}

Stage::~Stage()
{
}

void Stage::update()
{
	unit1->update();
}

void Stage::draw()
{
	unit1->draw();
}

bool Stage::isAbleToMove(int cy, int cx, int y, int x)
{
	if ((cy + y >= 0) && (cy + y <= 2) && (cx + x >= 0) && (cx + x <= 2))
	{
		if (table[cy + y][cx + x] == 0)
			return true;
		else if (table[cy + y][cx + x] == 1)
			return false;
	}
	else
		return false;
	
}

void Stage::moveStage(int y, int x)
{
	table[unit1->getY()][unit1->getX()] = 0;
	table[unit1->getY() + y][unit1->getX() + x] = 1;
}

//debug
void Stage::printPosition()
{
	printfDx("position: %d, %d\n", unit1->getX(), unit1->getY());
}

void Stage::printTable()
{
	printfDx("table:\n %d %d %d\n %d %d %d\n %d %d %d\n",
		table[0][0], table[0][1], table[0][2],
		table[1][0], table[1][1], table[1][2],
		table[2][0], table[2][1], table[2][2]
	);
}


