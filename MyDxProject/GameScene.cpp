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
		_enemyspawn2 = new SpawnController();
		_enemyspawn3 = new SpawnController();
		_enemyspawn4 = new SpawnController();
		//一か所スポーン位置追加
		_enemySpawn->AddSpaenPoint(320, -32);//上
		_enemyspawn2->AddSpaenPoint(640 + 32, 240);//右
		_enemyspawn3->AddSpaenPoint(640 + 32, -32);//右上
		_enemyspawn4->AddSpaenPoint(640 + 32, 240 + 32);//右下
		//_enemySpawn->AddSpaenPoint(320, 480 + 32);//下
		//_enemySpawn->AddSpaenPoint(-32, 240);//左

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

		_enemyspawn2->OnSpawn()->Subscribe([this](Vector2D<float> pos) {
			//敵生成
			Enemy* enemy2 = new Enemy(pos, "Enemy");
			enemy2->SetTarget(_player);
			//敵に弾が衝突したとき
			enemy2->OnHit()->Subscribe([this](ObjectTransform transform) {
				_score->AddScore();
				//パーティクル
				GameObjectContainer::GetInstance()->AddGameObject(new Particle(&transform));
				//爆発
				GameObjectContainer::GetInstance()->AddGameObject(new Bomb(&transform));
			});
			//登録
			GameObjectContainer::GetInstance()->AddGameObject(enemy2);
		});

		_enemyspawn3->OnSpawn()->Subscribe([this](Vector2D<float> pos) {
			//敵生成
			Enemy* enemy3 = new Enemy(pos, "Enemy");
			enemy3->SetTarget(_player);
			//敵に弾が衝突したとき
			enemy3->OnHit()->Subscribe([this](ObjectTransform transform) {
				_score->AddScore();
				//パーティクル
				GameObjectContainer::GetInstance()->AddGameObject(new Particle(&transform));
				//爆発
				GameObjectContainer::GetInstance()->AddGameObject(new Bomb(&transform));
			});
			//登録
			GameObjectContainer::GetInstance()->AddGameObject(enemy3);
		});

		_enemyspawn4->OnSpawn()->Subscribe([this](Vector2D<float> pos) {
			//敵生成
			Enemy* enemy4 = new Enemy(pos, "Enemy");
			enemy4->SetTarget(_player);
			//敵に弾が衝突したとき
			enemy4->OnHit()->Subscribe([this](ObjectTransform transform) {
				_score->AddScore();
				//パーティクル
				GameObjectContainer::GetInstance()->AddGameObject(new Particle(&transform));
				//爆発
				GameObjectContainer::GetInstance()->AddGameObject(new Bomb(&transform));
			});
			//登録
			GameObjectContainer::GetInstance()->AddGameObject(enemy4);
		});


		//スポーン登録
		GameObjectContainer::GetInstance()->AddGameObject(_enemySpawn);
		GameObjectContainer::GetInstance()->AddGameObject(_enemyspawn2);
		GameObjectContainer::GetInstance()->AddGameObject(_enemyspawn3);
		GameObjectContainer::GetInstance()->AddGameObject(_enemyspawn4);

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