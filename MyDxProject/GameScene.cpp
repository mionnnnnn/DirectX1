//GameMainからコピペ
#include "GameScene.h"
#include <random>
#include "Bullet.h"
#include "Particle.h"
#include "Background.h"
#include "Bomb.h"

void GameScene::Initialize() {
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
		//プレイヤー衝突時
		_player->OnHit()->Subscribe([this](ObjectTransform transform) {
			//爆発
			GameObjectContainer::GetInstance()->AddGameObject(new Bomb(&transform));
			//BGM停止
			_background->stopBGM();
			_over = new GameOver();
			//GameOverへGO
			GameObjectContainer::GetInstance()->AddGameObject(_over);
		});
		//playerインスタンス登録
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
			//敵に弾が衝突したとき
			enemy->OnHit()->Subscribe([this](ObjectTransform transform) {
				_score->AddScore();
				//パーティクル
				GameObjectContainer::GetInstance()->AddGameObject(new Particle(&transform));
				//爆発
				GameObjectContainer::GetInstance()->AddGameObject(new Bomb(&transform));
			});
			//登録
			GameObjectContainer::GetInstance()->AddGameObject(enemy);
		});
		//スポーン登録
		GameObjectContainer::GetInstance()->AddGameObject(_enemySpawn);
	}

	//スコア
	_score = new Score();
	GameObjectContainer::GetInstance()->AddGameObject(_score);

	//タイマー
	_timer = new Timer();
	GameObjectContainer::GetInstance()->AddGameObject(_timer);
}

void GameScene::MainLoop() {
	GameObjectContainer::GetInstance()->Update();
	GameObjectContainer::GetInstance()->Draw();
	GameObjectContainer::GetInstance()->HitCheck();
	GameObjectContainer::GetInstance()->DestroyCheck();
}

void GameScene::Release() {
	GameObjectContainer::GetInstance()->Release();
	GameObjectContainer::GetInstance()->DestroyInstance();
	//↓SceneManagerへ移動
	//ResourceManager::DestroyInstance();
}