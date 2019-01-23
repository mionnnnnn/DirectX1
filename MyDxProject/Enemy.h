#pragma once
#include"DxLib.h"
#include "GameObject.h"
#include "Subject.h"
#include <math.h>

class Enemy : public GameObject {
public:
	Enemy();
	Enemy(Vector2D<float>pos);
	Enemy(Vector2D<float> pos, std::string tag);
	~Enemy();
	void Start();
	void Update();
	void Draw();
	void SetTarget(GameObject* target);//�^�[�Q�b�g�ݒ�
	void OnHitBox(GameObject* other);
	IObservable<ObjectTransform>* OnHit(); //���S���̃C�x���g��o�^

private:
	int _grp;
	int cake;
	int _virus;
	int _utu;
	int _game;
	//int juken1;
	//int juken2;
	GameObject* _target;//�ǐՂ���^�[�Q�b�g��ݒ�
	Subject<ObjectTransform> _hitSubject;
};