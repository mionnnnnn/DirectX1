#pragma once
#include"DxLib.h"
#include "GameObject.h"
#include<math.h>

//�e�I�u�W�F�N�g
class Bullet : public GameObject {
public:
	Bullet(ObjectTransform* transform);
	virtual ~Bullet();
	void Start();
	void Update();
	void Draw();

private:
	int _grp;
};