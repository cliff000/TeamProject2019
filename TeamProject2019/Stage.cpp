#include "Stage.h"
#include "Image.h"
#include "DxLib.h"
#include "keyboard.h"

#include "AttackState.h"
#include "DefenseState.h"
#include "ThrowState.h"


Stage::Stage()
{
	unit1p = new Unit1P();
	unit1p->setStage(this);
	table[1][1] += 1;									//ユニット配置

	unit2p = new Unit2P();
	unit2p->setStage(this);
	table[1][7] += 2;									//ユニット配置

	color = GetColor(0, 0, 255);		//debug

	image = Image::read("Assets/Image/frame.png");
}

Stage::~Stage()
{
	delete unit1p;
	unit1p = nullptr;
	delete unit2p;
	unit2p = nullptr;
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
	unit2p->draw();
}

bool Stage::isAbleToMove(int cy, int cx, int y, int x, int player)
{
	if ((cy + y >= 0) && (cy + y <= 2) && (cx + x >= 1) && (cx + x <= 7) && (cx + x != 4))
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

int Stage::getActualX(int x) {
	return leftTopX + imageInterval * x;
}

int Stage::getActualY(int y) {
	return leftTopY + imageInterval * y;
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



