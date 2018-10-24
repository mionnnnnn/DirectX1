#include"GameMain.h"

//‰Šú‰»
void GameMain::Initialize() {

	_player.Start();
}
//Às
void GameMain::MainLoop() {
	_player.Update();
	_player.Draw();

}
//‰ğ•ú
void GameMain::Release() {

}