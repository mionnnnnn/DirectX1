#pragma once
#include"DxLib.h"
#include "GameObject.h"
#include<math.h>

//弾オブジェクト
class Bullet : public GameObject {
public:
	Bullet(ObjectTransform* transform);
	virtual ~Bullet();
	void Start();
	void Update();
	void Draw();
	void OnHitBox(GameObject* other);
private:
	int _grp;
	int _snd;
};