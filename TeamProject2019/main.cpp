#include "DxLib.h"
//#include "Node.h"
#include "keyboard.h"
#include "stage.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	//debug
	Stage* stage = new Stage();
	//debug


	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {

		//debug
		stage->update();
		stage->draw();
		//debug

	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}