#pragma once
#include"DxLib.h"
#include "GameObject.h"
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

private:
	int _grp;
	GameObject* _target;//�ǐՂ���^�[�Q�b�g��ݒ�
};