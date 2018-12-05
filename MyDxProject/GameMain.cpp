#include"GameMain.h"
#include <random>
#include "Bullet.h"
#include "Particle.h"
#include "Background.h"

// new したら delete する。

//初期化
void GameMain::Initialize() {
	//最初に背景を追加
	_background = new Background();
	GameObjectContainer::GetInstance()->AddGameObject(_background);

	//player
	{
		_player = new Player("Player");
		//プレイヤーがボタンを押した場合の処理をサブスクライブする(追加)
		_player->OnShotButton()->Subscribe([this](ObjectTransform transform) {
			GameObjectContainer::GetInstance()->AddGameObject(new Bullet(&transform));
		});
		GameObjectContainer::GetInstance()->AddGameObject(_player);
	}

	//enemy
	{
		//スポーン位置設定
		_enemySpawn = new SpawnController();
		//一か所スポーン位置追加
		_enemySpawn->AddSpaenPoint(320, -32);
		_enemySpawn->AddSpaenPoint(320, 480 + 32);
		_enemySpawn->AddSpaenPoint(-32, 240);
		_enemySpawn->AddSpaenPoint(640 + 32, 240);
		//生成時通知を受け取る
		_enemySpawn->OnSpawn()->Subscribe([this](Vector2D<float> pos) {
			//敵生成
			Enemy* enemy = new Enemy(pos, "Enemy");
			enemy->SetTarget(_player);
			//弾衝突時のイベント登録
			enemy->OnHit()->Subscribe([this](ObjectTransform transform) {
				_score->AddScore();
				GameObjectContainer::GetInstance()->AddGameObject(new Particle(&transform));
			});
			//登録
			GameObjectContainer::GetInstance()->AddGameObject(enemy);
		});
		GameObjectContainer::GetInstance()->AddGameObject(_enemySpawn);
	}

	//スコア
	_score = new Score();
	GameObjectContainer::GetInstance()->AddGameObject(_score);

	//タイマー
	_timer = new Timer();
	GameObjectContainer::GetInstance()->AddGameObject(_timer);

	//もういらねえ
	{
		//std::random_device rand;//enemy発生位置ランダム用
		//_enemy = new Enemy(Vector2D<float>(rand() % 640, rand() % 480), "Enemy");
		//_enemy->SetTarget(_player);
		//敵に当たった時にパーティクル通知される
		//_enemy->OnHit()->Subscribe([this](ObjectTransform transform) {
		//GameObjectContainer::GetInstance()->AddGameObject(new Particle(&transform));
		//});
	//Container
			//GameObjectContainer::GetInstance()->AddGameObject(_enemy);
			//箱
			//GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(100, 100), "Box"));
			//GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(400, 300), "Box"));
			//GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(100, 300), "Box"));
			//GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(400, 400), "Box"));

		//test用particle
		//GameObjectContainer::GetInstance()->AddGameObject(
		//	new Particle(Vector2D<float>(rand() % 640, rand() % 480)));
	}
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