#include"GameMain.h"

//������
void GameMain::Initialize() {

	_player.Start();
}
//���s
void GameMain::MainLoop() {
	_player.Update();
	_player.Draw();

}
//���
void GameMain::Release() {

}