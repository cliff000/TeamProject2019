#include "DxLib.h"
#include "Node.h"
#include "keyboard.h"


<<<<<<< HEAD
//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
//	DxLib_Init();	// DX���C�u��������������
//	WaitKey();	// �L�[���͑҂�
//	DxLib_End();	// DX���C�u�����I������
//	return 0;
//}
=======
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
		if (Key[KEY_INPUT_LEFT] == 1) {

		}
	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}
>>>>>>> master
