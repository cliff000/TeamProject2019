#include "DxLib.h"
#include "keyboard.h"
#include "stage.h"
#include "AudioManager.h"
//#include "Ui.h"
//debug


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetBackgroundColor(230, 230, 230);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	//debug
	Stage* stage = new Stage();
	int frame = 0;
	//debug

	AudioManager* audioManager = new AudioManager();
	audioManager->load();

	//Ui* ui = new Ui();
	//ui->load();

	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {

		//debug
		clsDx();

		audioManager->update();
		audioManager->draw();

		//ui->draw();

		frame++;

		stage->update();
		stage->draw();

		printfDx("frame count: %d\n", frame);
		stage->printPosition();
		stage->printTable();
		//debug
	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}
