#pragma once
#include"GameObject.h"
#include<list>

class GameObjectContainer {
private:
	//�R���X�g���N�^�Q��private�ɂ��A
	//�O����C���X�^���X�������ł��Ȃ��悤�ɂ���
	GameObjectContainer(){}
	GameObjectContainer(const GameObjectContainer&){}

public:
	//�R���e�i��GameObject��ǉ�
	void AddGameObject(GameObject* object);
	//�R���e�i�Ɋi�[����Ă���GameObject�N���X��Start()���Ăяo��
	void Start();
	//Draw()�Ăяo��
	void Draw();
	//Update()�Ăяo��
	void Update();
	//�������
	void Release();
	//gameobject���m�̏Փ˔�������s
	void HitCheck();
	//destroy��Ԃ��m�F
	void DestroyCheck();
	//�C���X�^���X�擾�p��static�����o�֐���錾
	static GameObjectContainer* GetInstance();
	//�C���X�^���X����p��static�����o�֐���錾
	static void DestroyInstance();

private: 
	//�I�u�W�F�N�g�R���e�i
	std::list<GameObject*> _container;
	//�C���X�^���X�i���́j�i�[�p��static�ϐ�
	static GameObjectContainer* _instance;
};