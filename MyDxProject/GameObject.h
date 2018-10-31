#pragma once
#include"ObjectTransform.h"

//ゲーム内表示オブジェクトの基底クラス
class GameObject {
public:
	GameObject() : isDestroy(false) {

	}
	virtual ~GameObject(){}
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	//破棄
	virtual void Destroy() {
		isDestroy = true;
	}
	//デストロイフラグ取得
	bool HasDestroy() {
		return isDestroy;
	}

	//衝突検知
	virtual void OnHitBox(GameObject* other){}

public:
	ObjectTransform _transform;
	bool isDestroy;
};