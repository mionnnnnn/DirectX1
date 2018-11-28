#pragma once
#include"DxLib.h"
#include"GameMain.h"
#include<math.h>
#define MAX_SPARK 50 //パーティクル最大数

//パーティクルオブジェクト
class Particle : public GameObject {
public:
	Particle(Vector2D<float> pos);
	Particle(ObjectTransform* transform);
	virtual ~Particle();

	void Start();
	void Update();
	void Draw();

	//パーティクル生成
	void CreateSpark();

private:
	//火花データ型
	typedef struct tagSPARK {
		int Valid;//このデータが使用中かのフラグ
		int X, Y;//花火の位置
		int Sx, Sy;//移動量
		int G;//重さ
		int Bright;//明るさ
	} SPARK;

	//花火データ
	SPARK Spark[MAX_SPARK];
};