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
	table[1][0] += 1;									//ユニット配置

	unit2p = new Unit2P();
	unit2p->setStage(this);
	table[1][0] += 2;									//ユニット配置

	color = GetColor(0, 0, 255);		//debug

	image = Image::read("TeamProject2019/Assets/Image/frame.png");
}

Stage::~Stage()
{
}

void Stage::update()
{
	if (Key[KEY_INPUT_Z] == 1) {
		unit1p->changeState(new AttackState());
		unit2p->changeState(new AttackState());
	}
	if (Key[KEY_INPUT_X] == 1) {
		unit1p->changeState(new DefenseState());
		unit2p->changeState(new DefenseState());
	}
	if (Key[KEY_INPUT_C] == 1) {
		unit1p->changeState(new ThrowState());
		unit2p->changeState(new ThrowState());
	}
	if (Key[KEY_INPUT_V] == 1) {
		unit1p->changeState(new BlockState());
		unit2p->changeState(new BlockState());
	}

	unit1p->update();
	unit2p->update();
}

void Stage::draw()
{
	const double imageInterval = imageSize * imageScale;
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
	table[unit1p->getY()][unit1p->getX()] -= player;
	table[unit1p->getY() + y][unit1p->getX() + x] += player;
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



