#pragma once
#include"DxLib.h"
#include "GameObject.h"
#include "Subject.h"
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
	void SetTarget(GameObject* target);//ターゲット設定
	void OnHitBox(GameObject* other);
	IObservable<ObjectTransform>* OnHit(); //死亡時のイベントを登録

private:
	int _grp;
	GameObject* _target;//追跡するターゲットを設定
	Subject<ObjectTransform> _hitSubject;
};