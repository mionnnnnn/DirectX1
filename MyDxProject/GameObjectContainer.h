#pragma once
#include"GameObject.h"
#include<list>

class GameObjectContainer {
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

private: 
	std::list<GameObject*> _container;//�I�u�W�F�N�g�R���e�i
};