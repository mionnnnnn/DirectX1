#pragma once
#include"DxLib.h"
#include <math.h>
#include "Vector2D.h"
#define ToRadian(degree) ((degree)*(3.14159265359f/180.0f))

//playerクラス
//素材
class Player {
public:
	Player();//コンストラクタ
	virtual ~Player();//デストラクタ
	void Start();//スタート
	void Update();//更新
	void Draw();//描画

private:
	float _x, _y;
	float _moveVecX, _moveVecY;
	float _angle;
	float _grp;
	Vector2D<float> _vector2D;//追加
};