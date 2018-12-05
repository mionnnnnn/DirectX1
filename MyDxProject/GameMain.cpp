#include"GameMain.h"
#include <random>
#include "Bullet.h"
#include "Particle.h"
#include "Background.h"

// new ������ delete ����B

//������
void GameMain::Initialize() {
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

	//��������˂�
	{
		//std::random_device rand;//enemy�����ʒu�����_���p
		//_enemy = new Enemy(Vector2D<float>(rand() % 640, rand() % 480), "Enemy");
		//_enemy->SetTarget(_player);
		//�G�ɓ����������Ƀp�[�e�B�N���ʒm�����
		//_enemy->OnHit()->Subscribe([this](ObjectTransform transform) {
		//GameObjectContainer::GetInstance()->AddGameObject(new Particle(&transform));
		//});
	//Container
			//GameObjectContainer::GetInstance()->AddGameObject(_enemy);
			//��
			//GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(100, 100), "Box"));
			//GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(400, 300), "Box"));
			//GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(100, 300), "Box"));
			//GameObjectContainer::GetInstance()->AddGameObject(new Box(Vector2D<float>(400, 400), "Box"));

		//test�pparticle
		//GameObjectContainer::GetInstance()->AddGameObject(
		//	new Particle(Vector2D<float>(rand() % 640, rand() % 480)));
	}
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