#include "Stage.h"
#include "DxLib.h"
#include "keyboard.h"


Stage::Stage()
{

	pos[0] = 1;							//Y座標
	pos[1] = 0;							//X座標
	table[pos[0]][pos[1]] = 1;			//ユニット配置

	isAbleToMove = true;				//行動可能にしておく
	isMoved = true;						//行動済み解除

	color = GetColor(0, 0, 255);		//debug
}

Stage::~Stage()
{
}

void Stage::update() {
	if (isAbleToMove && !(isMoved))		//行動可能かつ行動済みでないなら判定を取る
	{
		//各キー入力に対する処理
		if (Key[KEY_INPUT_UP] == 1 && pos[0] >= 1)
		{
			table[pos[0]][pos[1]] = 0;
			pos[0]--;
			table[pos[0]][pos[1]] = 1;
			isMoved = false;
		}
		else if (Key[KEY_INPUT_DOWN] == 1 && pos[0] <= 1)
		{
			table[pos[0]][pos[1]] = 0;
			pos[0]++;
			table[pos[0]][pos[1]] = 1;
			isMoved = false;
		}

		if (Key[KEY_INPUT_LEFT] == 1 && pos[1] >= 1)
		{
			table[pos[0]][pos[1]] = 0;
			pos[1]--;
			table[pos[0]][pos[1]] = 1;
			isMoved = false;
		}
		else if (Key[KEY_INPUT_RIGHT] == 1 && pos[1] <= 1)
		{
			table[pos[0]][pos[1]] = 0;
			pos[1]++;
			table[pos[0]][pos[1]] = 1;
			isMoved = false;
		}
	}
	else if (!(isAbleToMove))			//行動可能でないなら
	{
		isMoved = true;					//行動済み状態をリセットする
	}
	if (Key[KEY_INPUT_R])				//debug
	{
		isAbleToMove = false;
	}
}

void Stage::draw()
{

	DrawBox(
		pos[1] * 40,
		pos[0] * 40,
		(pos[1] + 1) * 40,
		(pos[0] + 1) * 40,
		color,
		true
	);

}

void Stage::printPosition()
{
	printfDx("position: %d, %d\n", pos[0], pos[1]);
}
