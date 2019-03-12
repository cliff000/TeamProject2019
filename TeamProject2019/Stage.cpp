#include "Stage.h"
#include "Image.h"
#include "DxLib.h"
#include "keyboard.h"


Stage::Stage()
{
	unit1 = new Unit();
	unit1->setStage(this);
	table[1][0] = 1;									//ユニット配置

	color = GetColor(0, 0, 255);		//debug

	image = Image::read("TeamProject2019/Assets/Image/frame.png");
	unitUi[0] = Image::read("TeamProject2019/Assets/Image/attack.png");
	unitUi[1] = Image::read("TeamProject2019/Assets/Image/throw.png");
	unitUi[2] = Image::read("TeamProject2019/Assets/Image/defense.png");
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


