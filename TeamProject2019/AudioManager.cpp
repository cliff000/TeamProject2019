#include "DxLib.h"
#include "AudioManager.h"

bool AudioManager::IsMovable()
{
	if (soundWaitElapsed < movableRange || soundSpan - movableRange < soundWaitElapsed)return true;
	else return false;
}

void AudioManager::load() 
{
	ses[Se::High] = LoadSoundMem("TeamProject2019/Assets/Sound/click_03-high.wav");
	ses[Se::Low] = LoadSoundMem("TeamProject2019/Assets/Sound/click_03-low.wav");
	circleImage = LoadGraph("TeamProject2019/Assets/Image/Circle.png");
	prevTime = GetNowCount();
	InitializeSoundSpan(120);
}

void AudioManager::update()
{
	CheckSound();
}

void AudioManager::draw()
{
	const double defaultCircleSize = 0.11;
	const int circlePosX = 320;
	const int circlePosY = 70;
	DrawRotaGraph(circlePosX, circlePosY, defaultCircleSize, 0, circleImage, true);
	DrawRotaGraph(circlePosX, circlePosY,  
				  0.14 * (soundSpan - soundWaitElapsed) / soundSpan + defaultCircleSize,
				  0, circleImage, true);
}

void AudioManager::InitializeSoundSpan(int bpm)
{
	double bps = bpm / 60.0;
	soundSpan = 1 / bps;
}

void AudioManager::CheckSound()
{
	soundWaitElapsed += UpdateDeltaTime();
	if (soundWaitElapsed > soundSpan)
	{
		if (soundNumPerMeasure == 0)
		{
			PlaySoundMem(ses[Se::High], DX_PLAYTYPE_BACK);
		}
		else
		{
			PlaySoundMem(ses[Se::Low], DX_PLAYTYPE_BACK);
		}
		soundNumPerMeasure = (soundNumPerMeasure + 1) % 4;
		soundWaitElapsed -= soundSpan;
	}
}

//1フレームに2回以上呼ぶとバグるぞ
double AudioManager::UpdateDeltaTime()
{
	double deltaTime = GetNowCount() - prevTime;
	prevTime = GetNowCount();
	return deltaTime / 1000;
}