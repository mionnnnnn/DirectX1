#include"GameMain.h"
#include <random>
#include "Bullet.h"
#include "Particle.h"
#include "Background.h"

// new したら delete する。

//初期化
void GameMain::Initialize() {
	//最初に背景を追加
	GameObjectContainer::GetInstance()->AddGameObject(new Background());

	//player
	{
		_player = new Player("Player");

		//プレイヤーがボタンを押した場合の処理をサブスクライブする(追加)
		_player->OnShotButton()->Subscribe([this](ObjectTransform transform) {
			GameObjectContainer::GetInstance()->AddGameObject(new Bullet(&transform));
		});
	}

	//enemy
	{
		std::random_device rand;//enemy発生位置ランダム用
		_enemy = new Enemy(Vector2D<float>(rand() % 640, rand() % 480), "Enemy");
		_enemy->SetTarget(_player);
		//敵に当たった時にパーティクル通知される
		_enemy->OnHit()->Subscribe([this](ObjectTransform transform) {
			GameObjectContainer::GetInstance()->AddGameObject(new Particle(&transform));
		});
	}

	//Container
	{
		GameObjectContainer::GetInstance()->AddGameObject(_player);
		GameObjectContainer::GetInstance()->AddGameObject(_enemy);
		GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(100, 100), "Box"));
		GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(400, 300), "Box"));
		GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(100, 300), "Box"));
		GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(400, 400), "Box"));
	}

	//test用particle
	//GameObjectContainer::GetInstance()->AddGameObject(
	//	new Particle(Vector2D<float>(rand() % 640, rand() % 480)));
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