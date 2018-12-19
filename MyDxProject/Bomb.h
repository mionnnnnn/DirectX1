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
	int _grp[8];	//画像ハンドル
	int _sound;		//効果音ハンドル
	int _index;		//アニメーションのインデックス
};