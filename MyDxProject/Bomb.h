#pragma once
#include "DxLib.h"
#include "GameObject.h"
#include <math.h>

class Bomb : public GameObject {
public:
	Bomb(ObjectTransform* transform);

	virtual ~Bomb();

	void Start();
	void Update();
	void Draw();

private:
	int _grp[8];	//�摜�n���h��
	int _sound;		//���ʉ��n���h��
	int _index;		//�A�j���[�V�����̃C���f�b�N�X
};