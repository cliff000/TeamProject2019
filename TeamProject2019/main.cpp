#include "DxLib.h"
#include "keyboard.h"
//debug
#include "stage.h"
//debug


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	//debug
	Stage* stage = new Stage();
	int frame = 0;
	//debug


	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {

		//debug
		clsDx();

		frame++;

		stage->update();
		stage->draw();

		printfDx("frame count: %d\n", frame);
		stage->printPosition();
		//debug

	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}