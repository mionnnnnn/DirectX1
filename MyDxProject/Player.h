#pragma once
#include"DxLib.h"
#include <math.h>
#include "Vector2D.h"
#include "GameObject.h"
// #define 定義文 値or式(C#でいうconstとかreadonly的な)
// ToRadianが呼ばれると			↓ が実行される　的な？
#define ToRadian(degree) ((degree)*(3.14159265359f/180.0f))
#define SHOT_DELAYFRAME 10//次の弾を打つまでの最大待機時間

//playerクラス
class Player : public GameObject {
public:
	Player();//コンストラクタ
	~Player();//デストラクタ
	void Start();//スタート
	void Update();//更新
	void Draw();//描画

private:
	
	int _grp;
	//次の弾を打つまでの待機時間
	int _waitFrame;
};