#include"DxLib.h"
#include"SceneManager.h"
#include "Logo.h"

//プログラムはWinMainから始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance, LPSTR lpCmdLine, int nCmdShow) {
	
	//ウィンドウモードに変更
	ChangeWindowMode(true);
	//画面解像度を変更
	SetGraphMode(640, 480, 16);
	//このif文は絶対書く！
	//DXライブラリ初期化処理
	if (DxLib_Init() == -1)
		//エラーが起きたら直ちに終了
		return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	//1212追加
	SceneManager::GetInstance()->LoadScene(new Logo());
	SceneManager::GetInstance()->Update();

	/*
	//1212削除
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen();//画面初期化
		gamemain.MainLoop();

		//fps関係
		fps.Update();
		fps.Draw();
		ScreenFlip();//裏画面の内容を表画面に反映させる
		fps.Wait();
	}

	//WaitKey();//キー入力待ち

	gamemain.Release();
	*/

	//DXライブラリ使用の終了処理
	DxLib_End();

	//ソフトの終了
	return 0;
}