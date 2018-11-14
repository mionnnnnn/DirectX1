#include"GameMain.h"
#include <random>

// new ������ delete ����B

//������
void GameMain::Initialize() {
	_player = new Player();
	std::random_device rand;//enemy�����ʒu�����_���p
	_enemy = new Enemy(Vector2D<float>(rand() % 640, rand() % 480), "Enemy");
	_enemy->SetTarget(_player);
	GameObjectContainer::GetInstance()->AddGameObject(_player);
	GameObjectContainer::GetInstance()->AddGameObject(_enemy);
	GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(100, 100), "Box"));
	GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(400, 300), "Box"));
	GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(100, 300), "Box"));
	GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(400, 400), "Box"));
	//GameObjectContainer::GetInstance()->Start();
}
//���s
void GameMain::MainLoop() {
	GameObjectContainer::GetInstance()->Update();
	GameObjectContainer::GetInstance()->Draw();
	GameObjectContainer::GetInstance()->HitCheck();
	GameObjectContainer::GetInstance()->DestroyCheck();
}
//���
void GameMain::Release() {
	GameObjectContainer::GetInstance()->Release();
	GameObjectContainer::GetInstance()->DestroyInstance();
	ResourceManager::DestroyInstance();
}