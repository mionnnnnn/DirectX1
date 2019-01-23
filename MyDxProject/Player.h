#pragma once
#include"DxLib.h"
#include <math.h>
#include "Vector2D.h"
#include "GameObject.h"
#include"Subject.h"
// #define ��`�� �lor��(C#�ł���const�Ƃ�readonly�I��)
// ToRadian���Ă΂���			�� �����s�����@�I�ȁH
#define ToRadian(degree) ((degree)*(3.14159265359f/180.0f))
#define SHOT_DELAYFRAME 8//���̒e��ł܂ł̍ő�ҋ@����

//player�N���X
class Player : public GameObject {
public:
	Player();
	Player(std::string tag);
	~Player();
	void Start();
	void Update();
	void Draw();

	//�e������(�ǉ�)
	void Shot();

	//�e���������ۂɎ��s����C�x���g��o�^����(�ǉ�)
	IObservable<ObjectTransform>* OnShotButton();

	//�Փ˔���
	void OnHitBox(GameObject* other);

	//�Փˎ�����
	IObservable<ObjectTransform>* OnHit();

private:
	//�摜�p
	int _grp;
	int _grp2;

	//���̒e��ł܂ł̑ҋ@����
	int _waitFrame;

	//�T�u�W�F�N�g��錾(�ǉ�)
	Subject<ObjectTransform>_shotSubject;

	//�Փˎ��ɒʒm������
	Subject<ObjectTransform> _hitSubject;
};