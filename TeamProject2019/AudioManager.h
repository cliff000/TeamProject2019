#pragma once

class AudioManager{
public :
	enum Se { High, Low };
	void load();
	void update();
	void draw();
	bool IsMovable();

private:
	const double movableRange = 0.1;
	int circleImage;
	int ses[2];
	int soundNumPerMeasure;
	double soundSpan = 0;
	double soundWaitElapsed = 0;
	double prevTime;

	void InitializeSoundSpan(int bpm);
	void CheckSound();
	double UpdateDeltaTime();
};