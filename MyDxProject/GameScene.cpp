//GameMain����R�s�y
#include "GameScene.h"
#include <random>
#include "Bullet.h"
#include "Particle.h"
#include "Background.h"
#include "Bomb.h"

void GameScene::Initialize() {
	//�ŏ��ɔw�i��ǉ�
	_background = new Background();
	GameObjectContainer::GetInstance()->AddGameObject(_background);

	//player
	{
		_player = new Player("Player");
		//�v���C���[���{�^�����������ꍇ�̏������T�u�X�N���C�u����(�ǉ�)
		_player->OnShotButton()->Subscribe([this](ObjectTransform transform) {
			GameObjectContainer::GetInstance()->AddGameObject(new Bullet(&transform));
		});
		//�v���C���[�Փˎ�
		_player->OnHit()->Subscribe([this](ObjectTransform transform) {
			//����
			GameObjectContainer::GetInstance()->AddGameObject(new Bomb(&transform));
			//BGM��~
			_background->stopBGM();
			_over = new GameOver();
			//GameOver��GO
			GameObjectContainer::GetInstance()->AddGameObject(_over);
		});
		//player�C���X�^���X�o�^
		GameObjectContainer::GetInstance()->AddGameObject(_player);
	}

	//enemy
	{
		//�X�|�[���ʒu�ݒ�
		_enemySpawn = new SpawnController();
		//�ꂩ���X�|�[���ʒu�ǉ�
		_enemySpawn->AddSpaenPoint(320, -32);
		_enemySpawn->AddSpaenPoint(320, 480 + 32);
		_enemySpawn->AddSpaenPoint(-32, 240);
		_enemySpawn->AddSpaenPoint(640 + 32, 240);
		//�������ʒm���󂯎��
		_enemySpawn->OnSpawn()->Subscribe([this](Vector2D<float> pos) {
			//�G����
			Enemy* enemy = new Enemy(pos, "Enemy");
			enemy->SetTarget(_player);
			//�G�ɒe���Փ˂����Ƃ�
			enemy->OnHit()->Subscribe([this](ObjectTransform transform) {
				_score->AddScore();
				//�p�[�e�B�N��
				GameObjectContainer::GetInstance()->AddGameObject(new Particle(&transform));
				//����
				GameObjectContainer::GetInstance()->AddGameObject(new Bomb(&transform));
			});
			//�o�^
			GameObjectContainer::GetInstance()->AddGameObject(enemy);
		});
		//�X�|�[���o�^
		GameObjectContainer::GetInstance()->AddGameObject(_enemySpawn);
	}

	//�X�R�A
	_score = new Score();
	GameObjectContainer::GetInstance()->AddGameObject(_score);

	//�^�C�}�[
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
	//��SceneManager�ֈړ�
	//ResourceManager::DestroyInstance();
}