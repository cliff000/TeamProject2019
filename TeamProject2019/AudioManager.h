#pragma once
#include "Node.h"

class AudioManager : Node {
public :
	enum Se { High, Low };
	void load();
	void update();
	void draw();
	bool IsMovable();

private:
	const double movableRange = 0.2;
	int circleImage;
	int ses[2];
	int soundNumPerMeasure;
	double soundSpan = 0;
	double soundWaitElapsed = 0;
	double prevTime;

	void InitializeSoundSpan(int bpm);
	void CheckSound();
	void CircleCount();
	double UpdateDeltaTime();
};