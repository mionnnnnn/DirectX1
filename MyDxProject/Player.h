#pragma once
#include"DxLib.h"
#include <math.h>
#include "Vector2D.h"
//#define ��`�� �lor��(C#�ł���const�Ƃ�readonly�I��)
//ToRadian���Ă΂���			�� �����s�����@�I�ȁH
#define ToRadian(degree) ((degree)*(3.14159265359f/180.0f))

//player�N���X
//�f��
class Player {
public:
	Player();//�R���X�g���N�^
	virtual ~Player();//�f�X�g���N�^
	void Start();//�X�^�[�g
	void Update();//�X�V
	void Draw();//�`��

private:
	
	float _moveVecX, _moveVecY;
	float _angle;
	int _grp;
	Vector2D<float> _pos;
	Vector2D<float> _moveVec;
};