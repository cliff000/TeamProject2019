#include "DxLib.h"
#include "AudioManager.h"

void AudioManager::load() 
{
	ses[Se::High] = LoadSoundMem("Assets/Sound/click_03-high.wav");
	ses[Se::Low] = LoadSoundMem("Assets/Sound/click_03-low.wav");
}

void AudioManager::InitializeSoundSpan(int bpm)
{
	const int fps = 60;
	double bps = bpm / 60.0;
	soundSpan = 1 / bps;
}

void AudioManager::Sound(AudioManager::Se se) 
{
	PlaySoundMem(ses[se], DX_PLAYTYPE_NORMAL);
}