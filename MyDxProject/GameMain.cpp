#include"GameMain.h"

//初期化
void GameMain::Initialize() {
	//画像読み込み
	playerGraph = LoadGraph("white.png");
	_player.Start();
}
//実行
void GameMain::MainLoop() {
	_player.Update();
	_player.Draw();
	//入力処理
	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);//キー入力取得
	if (key & KEY_INPUT_UP)
		playerY -= 3;
	if (key & PAD_INPUT_DOWN)
		playerY += 3;
	if (key & PAD_INPUT_RIGHT)
		playerX += 3;
	if (key & PAD_INPUT_LEFT)
		playerX -= 3;

	//DrawPixel(320, 240, GetColor(255, 255, 255));//点を打つ
	DrawGraph(300, 200, playerGraph, TRUE);//画像を描画
}
//解放
void GameMain::Release() {

}