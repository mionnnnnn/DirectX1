#pragma once
#include "DxLib.h"
#include"GameObject.h"
#include <math.h>

//ボックスクラス
//素材
class Box : public GameObject {
public:
	Box();
	Box(Vector2D<float> pos);
	~Box();
	void Start();
	void Update();
	void Draw();
	void OnHitBox(GameObject* other);
};