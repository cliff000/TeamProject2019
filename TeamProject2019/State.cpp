#include "State.h"
#include "DxLib.h"


State::State()
{
}


State::~State()
{
}

void State::draw(double x, double y, double width, double height) {
	if (width >= 0) {
		DrawExtendGraph(x, y, x + width, y + height, img, true);
	}
	else {
		DrawExtendGraph(x - width, y, x, y + height, img, true);
	}
}