//GameMain����R�s�y
#include "GameScene.h"
#include <random>
#include "Bullet.h"
#include "Particle.h"
#include "Background.h"

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
			//�e�Փˎ��̃C�x���g�o�^
			enemy->OnHit()->Subscribe([this](ObjectTransform transform) {
				_score->AddScore();
				GameObjectContainer::GetInstance()->AddGameObject(new Particle(&transform));
			});
			//�o�^
			GameObjectContainer::GetInstance()->AddGameObject(enemy);
		});
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
	ResourceManager::DestroyInstance();
}