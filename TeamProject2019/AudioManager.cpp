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
	InitializeSoundSpan(90);
}

void AudioManager::update()
{
	CheckSound();
	printfDx("%lf\n%lf\n%d\n%d", soundWaitElapsed, soundSpan, ses[Se::Low], IsMovable());
}

void AudioManager::draw()
{
	DrawRotaGraph(200, 200, (soundSpan - soundWaitElapsed) / soundSpan, 0, circleImage, true);
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

void AudioManager::CircleCount()
{

}

//1フレームに2回以上呼ぶとバグるぞ
double AudioManager::UpdateDeltaTime()
{
	double deltaTime = GetNowCount() - prevTime;
	prevTime = GetNowCount();
	return deltaTime / 1000;
}