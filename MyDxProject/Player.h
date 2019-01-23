#pragma once
#include"DxLib.h"
#include <math.h>
#include "Vector2D.h"
#include "GameObject.h"
#include"Subject.h"
// #define 定義文 値or式(C#でいうconstとかreadonly的な)
// ToRadianが呼ばれると			↓ が実行される　的な？
#define ToRadian(degree) ((degree)*(3.14159265359f/180.0f))
#define SHOT_DELAYFRAME 8//次の弾を打つまでの最大待機時間

//playerクラス
class Player : public GameObject {
public:
	Player();
	Player(std::string tag);
	~Player();
	void Start();
	void Update();
	void Draw();

	//弾を撃つ(追加)
	void Shot();

	//弾を撃った際に実行するイベントを登録する(追加)
	IObservable<ObjectTransform>* OnShotButton();

	//衝突判定
	void OnHitBox(GameObject* other);

	//衝突時挙動
	IObservable<ObjectTransform>* OnHit();

private:
	//画像用
	int _grp;
	int _grp2;

	//次の弾を打つまでの待機時間
	int _waitFrame;

	//サブジェクトを宣言(追加)
	Subject<ObjectTransform>_shotSubject;

	//衝突時に通知するやつ
	Subject<ObjectTransform> _hitSubject;
};