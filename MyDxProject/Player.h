#pragma once
#include"DxLib.h"
#include <math.h>
#include "Vector2D.h"
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
	float _x, _y;
	float _moveVecX, _moveVecY;
	float _angle;
	float _grp;
	Vector2D<float> _vector2D;//�ǉ�
};