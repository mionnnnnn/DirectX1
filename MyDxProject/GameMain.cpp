#include"GameMain.h"

//初期化
void GameMain::Initialize() {

	_player.Start();
}
//実行
void GameMain::MainLoop() {
	_player.Update();
	_player.Draw();

}
//解放
void GameMain::Release() {

}