#include "DxLib.h"
#include "keyboard.h"
#include "stage.h"
#include "AudioManager.h"
#include "Ui.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SetBackgroundColor(0, 0, 0);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	Stage *stage = new Stage();

	AudioManager *audioManager = new AudioManager();
	audioManager->load();

	Ui *ui = new Ui();
	ui->load();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0)
	{
		// updates
		audioManager->update();
		stage->update();

		// draws
		audioManager->draw();
		stage->draw();
		ui->draw();
	}

	// destruct
	delete stage;
	delete audioManager;
	delete ui;

	DxLib_End();
	return 0;
}
