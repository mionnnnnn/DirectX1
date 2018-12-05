#include "Enemy.h"
#include "GameObjectContainer.h"
#include <random>

//コンストラクタ
Enemy::Enemy() {
	_transform._position = Vector2D<float>(0, 0);
	_transform._angle = 0;
	_transform._size = Vector2D<float>(64, 64);
	_target = NULL;
}

//引数付き
Enemy::Enemy(Vector2D <float> pos) {
	_transform._position = pos;
	_transform._size = Vector2D<float>(64, 64);
	_target = NULL;
}

//引数&タグ付き
Enemy::Enemy(Vector2D <float> pos, std::string tag) {
	_transform._position = pos;
	_transform._size = Vector2D<float>(64, 64);
	_tag = tag;
	_target = NULL;
}

Enemy::~Enemy() {

}

void Enemy::Start() {
	_grp = LoadGraph("Resource\\img\\virus.png");
}

void Enemy::Update() {
	//追跡するターゲットが存在しなければ、何もしない
	if (_target == NULL)
		return;

	//ターゲットと自信の座標差を計算
	float y = _target->_transform._position._y - _transform._position._y;
	float x = _target->_transform._position._x - _transform._position._x;

	//atan2を使用して2点間の角度を計算
	_transform._angle = atan2(y, x);

	//アフィン変換 速さ
	float moveX = 2;
	float moveY = 0;
	_transform._moveVec._x = 
		moveX * static_cast<float>(cos(_transform._angle)) -
		moveY * static_cast<float>(sin(_transform._angle));
	_transform._moveVec._y = 
		moveX * static_cast<float>(sin(_transform._angle)) +
		moveY * static_cast<float>(cos(_transform._angle));

	//移動量計算
	_transform._position += _transform._moveVec;
}

void Enemy::Draw() {
	DrawRotaGraph(
		static_cast<int>(_transform._position._x),
		static_cast<int>(_transform._position._y),
		1.0f, _transform._angle, _grp, TRUE, FALSE);
}

//追跡するターゲット追加
void Enemy::SetTarget(GameObject* target) {
	_target = target;
}

void Enemy::OnHitBox(GameObject* other) {
	//衝突したオブジェクトがBulletだった場合
	if (other->_tag == "Bullet") {
		ObjectTransform transform;
		transform._position = this->_transform._position;
		_hitSubject.OnNext(transform);
		Destroy();
	}
	if (other->_tag == "Player") {

	}
}

//Subjectを返す
IObservable<ObjectTransform>* Enemy::OnHit() {
	return &_hitSubject;
}