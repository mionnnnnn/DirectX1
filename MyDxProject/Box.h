#pragma once
#include "DxLib.h"
#include"GameObject.h"
#include <math.h>

//�{�b�N�X�N���X
//�f��
class Box : public GameObject {
public:
	Box();
	Box(Vector2D<float> pos);
	Box(Vector2D<float>pos, std::string tag);
	~Box();
	void Start();
	void Update();
	void Draw();
	void OnHitBox(GameObject* other);
};