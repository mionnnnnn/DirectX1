#include"Bullet.h"
#include "ResourceManager.h"

//引数で発射位置の座標と角度を受け取り更新
Bullet::Bullet(ObjectTransform* transform) {
	_transform._position = transform->_position;
	_transform._angle = transform->_angle;
	//画像サイズを設定
	_transform._size = Vector2D<float>(16, 16);
}

Bullet::~Bullet() {

}

//開始処理
void Bullet::Start() {
	_grp = ResourceManager::GetInstance()->LoadResource("Resource\\img\\bullet.png");
}

//更新処理
void Bullet::Update() {
	//アフィン変換
	float moveX = 3;
	float moveY = 0;

	_transform._moveVec._x = moveX * static_cast<float>(cos(_transform._angle)) -
		moveY*static_cast<float>(sin(_transform._angle));
	_transform._moveVec._y = moveX * static_cast<float>(sin(_transform._angle)) +
		moveY*static_cast<float>(cos(_transform._angle));
	_transform._position += _transform._moveVec;

	//画面左からはみ出たら
	if (_transform._position._x < 0)
		Destroy();
	//右
	if (_transform._position._x > 640)
		Destroy();
	//上
	if (_transform._position._y < 0)
		Destroy();
	//下
	if (_transform._position._y > 480)
		Destroy();
}

void Bullet::Draw() {
	DrawGraph(
		static_cast<int>(_transform._position._x - (_transform._size._x / 2)),
		static_cast<int>(_transform._position._y - (_transform._size._y / 2)),
		_grp, TRUE);
}

