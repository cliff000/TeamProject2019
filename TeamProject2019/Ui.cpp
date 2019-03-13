#include "Ui.h"
#include "DxLib.h"

void Ui::load()
{
	triangle = LoadGraph("Assets/Image/Triangle.png");
}

void Ui::draw()
{
	DrawRotaGraph(320, 400, 0.2, 0, triangle, true);
}