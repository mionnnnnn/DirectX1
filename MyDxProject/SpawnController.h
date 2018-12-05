#pragma once
#include "GameObject.h"
#include "Subject.h"
#include <vector>
#include<random>
#define SPAWN_INTERVAL 60 //1回のスポーンの待機時間

//スポーンコントローラクラス
class SpawnController : public GameObject {
public:
	SpawnController();
	~SpawnController();

	void Start();
	void Update();
	void Draw();
	void AddSpaenPoint(float x, float y); //スポーン場所登録
	IObservable<Vector2D<float>>* OnSpawn(); //スポーン通知

private:
	//スポーンサブジェクト
	Subject<Vector2D<float>> _spawnSubject;

	//スポーン場所をリストで管理
	std::vector<Vector2D<float>> _spawnPoints;

	//スポーンまでの待機時間
	float _wait;
};