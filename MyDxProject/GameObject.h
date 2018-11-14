#pragma once
#include"ObjectTransform.h"
#include <string>

//ゲーム内表示オブジェクトの基底クラス
class GameObject {
public:
	GameObject() : isDestroy(false) {

	}
	virtual ~GameObject(){}
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	//座標等の情報
	ObjectTransform _transform;
	//タグの追加
	std::string _tag;
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
	bool isDestroy;
};