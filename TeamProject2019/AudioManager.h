#pragma once

class AudioManager{
public :
	enum Se { High, Low };
	void load();
	bool IsMovable();

private:
	void LoadAudio();
	void InitializeSoundSpan(int bpm);
	void Sound(Se se);

	int ses[2];
	double soundSpan;
};