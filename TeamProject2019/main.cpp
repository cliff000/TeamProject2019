#include "DxLib.h"
#include "Node.h"
#include "keyboard.h"


<<<<<<< HEAD
//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
//	DxLib_Init();	// DXライブラリ初期化処理
//	WaitKey();	// キー入力待ち
//	DxLib_End();	// DXライブラリ終了処理
//	return 0;
//}
=======
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
		if (Key[KEY_INPUT_LEFT] == 1) {

		}
	}

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}
>>>>>>> master
