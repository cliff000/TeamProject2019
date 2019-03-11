#include "DxLib.h"
#include "keyboard.h"
#include "MainScene.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	Scene* m = new MainScene();
	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
		m->update();
		m->draw();
	}

	delete m;

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}
