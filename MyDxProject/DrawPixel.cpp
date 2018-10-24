#include"DxLib.h"
#include"FPS.h"
#include"GameMain.h"

//プログラムはWinMainから始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance, LPSTR lpCmdLine, int nCmdShow) {
	
	GameMain gamemain;
	FPS fps;

	ChangeWindowMode(true);//ウィンドウモードに変更
	SetGraphMode(640, 480, 16);//画面解像度を変更
	//このif文は絶対書く！
	if (DxLib_Init() == -1)//DXライブラリ初期化処理
		return -1;//エラーが起きたら直ちに終了

	SetDrawScreen(DX_SCREEN_BACK);
	gamemain.Initialize();

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
	DxLib_End();//DXライブラリ使用の終了処理

	return 0;//ソフトの終了
}
