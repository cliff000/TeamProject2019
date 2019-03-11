#include "Unit1P.h"

void Unit1P::update() {
	state->update();
}

void Unit1P::draw() {
	state->draw(100, 200, 64, 64);
}