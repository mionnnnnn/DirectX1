#include"GameMain.h"

// new ������ delete ����B

//������
void GameMain::Initialize() {

	_player = new Player();

	_container.AddGameObject(_player);
	_container.AddGameObject(new Box(Vector2D<float>(100, 100)));
	_container.AddGameObject(new Box(Vector2D<float>(400, 300)));
	_container.AddGameObject(new Box(Vector2D<float>(100, 300)));
	_container.AddGameObject(new Box(Vector2D<float>(400, 400)));
	_container.Start();

	//_player->Start();
	//_box = new Box();
	//_box->Start();
}
//���s
void GameMain::MainLoop() {
	_container.Update();
	_container.Draw();
	_container.HitCheck();
	_container.DestroyCheck();
	//_player->Update();
	//_player->Draw();
	//_box->Update();
	//_box->Draw();
}
//���
void GameMain::Release() {
	_container.Release();
	//delete _player;
	//delete _box;
}