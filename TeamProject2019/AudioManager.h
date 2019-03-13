#pragma once

class AudioManager{
public :
	enum Se { High, Low };
	static void load();
	static void update();
	static void draw();
	static bool IsMovable();

private:
	static const double movableRange;
	static int circleImage;
	static int ses[2];
	static int soundNumPerMeasure;
	static double soundSpan;
	static double soundWaitElapsed;
	static double prevTime;

	static void InitializeSoundSpan(int bpm);
	static void CheckSound();
	static double UpdateDeltaTime();
};