#include "Unit2P.h"

void Unit2P::update() {
	state->update();
}

void Unit2P::draw() {
	state->draw(400, 200, -64, 64);
}