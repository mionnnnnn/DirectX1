#include"GameMain.h"
#include <random>
#include "Bullet.h"
#include "Particle.h"
#include "Background.h"

// new ������ delete ����B

//������
void GameMain::Initialize() {
	//�ŏ��ɔw�i��ǉ�
	GameObjectContainer::GetInstance()->AddGameObject(new Background());

	//player
	{
		_player = new Player("Player");

		//�v���C���[���{�^�����������ꍇ�̏������T�u�X�N���C�u����(�ǉ�)
		_player->OnShotButton()->Subscribe([this](ObjectTransform transform) {
			GameObjectContainer::GetInstance()->AddGameObject(new Bullet(&transform));
		});
	}

	//enemy
	{
		std::random_device rand;//enemy�����ʒu�����_���p
		_enemy = new Enemy(Vector2D<float>(rand() % 640, rand() % 480), "Enemy");
		_enemy->SetTarget(_player);
		//�G�ɓ����������Ƀp�[�e�B�N���ʒm�����
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

	//test�pparticle
	//GameObjectContainer::GetInstance()->AddGameObject(
	//	new Particle(Vector2D<float>(rand() % 640, rand() % 480)));
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