#include "SpawnController.h"

SpawnController::SpawnController() {
	_wait = 0;
}

SpawnController::~SpawnController() {

}

//開始
void SpawnController::Start() {
	_wait = 0;
}

//更新
void SpawnController::Update() {
	_wait++;

	//インターバルに到達していない場合以降の処理は実行しない
	if (_wait < SPAWN_INTERVAL)
		return;

	//発生するスポーンポイントを設定
	std::random_device rand;
	int index = rand() % _spawnPoints.size();
	Vector2D<float> spawnPos = _spawnPoints[index];

	//スポーン通知
	_spawnSubject.OnNext(spawnPos);

	//待機時間リセット
	_wait = 0;
}

//描画
void SpawnController::Draw() {

}

//スポーン場所登録
void SpawnController::AddSpaenPoint(float x, float y) {
	//vectorクラスへ
	_spawnPoints.push_back(Vector2D<float>(x, y));
}

//スポーン通知
IObservable<Vector2D<float>>* SpawnController::OnSpawn() {
	return &_spawnSubject;
}