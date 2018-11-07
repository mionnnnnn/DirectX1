#include"GameMain.h"

// new したら delete する。

//初期化
void GameMain::Initialize() {
	_player = new Player();
	GameObjectContainer::GetInstance()->AddGameObject(_player);
	GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(100, 100)));
	GameObjectContainer::GetInstance()-> AddGameObject(new Box(Vector2D<float>(400, 300)));
	GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(100, 300)));
	GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(400, 400)));
	//GameObjectContainer::GetInstance()->Start();
}
//実行
void GameMain::MainLoop() {
	GameObjectContainer::GetInstance()->Update();
	GameObjectContainer::GetInstance()->Draw();
	GameObjectContainer::GetInstance()->HitCheck();
	GameObjectContainer::GetInstance()->DestroyCheck();
}
//解放
void GameMain::Release() {
	GameObjectContainer::GetInstance()->Release();
	GameObjectContainer::GetInstance()->DestroyInstance();
	ResourceManager::DestroyInstance();
}