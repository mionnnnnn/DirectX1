#pragma once
#include"DxLib.h"
#include <math.h>
#include "Vector2D.h"
#include "GameObject.h"
//#define ��`�� �lor��(C#�ł���const�Ƃ�readonly�I��)
//ToRadian���Ă΂���			�� �����s�����@�I�ȁH
#define ToRadian(degree) ((degree)*(3.14159265359f/180.0f))

//player�N���X
class Player : public GameObject {
public:
	Player();//�R���X�g���N�^
	~Player();//�f�X�g���N�^
	void Start();//�X�^�[�g
	void Update();//�X�V
	void Draw();//�`��

private:
	
	int _grp;
	//float _moveVecX, _moveVecY;
	//float _angle;
	//Vector2D<float> _pos;
	//Vector2D<float> _moveVec;
};