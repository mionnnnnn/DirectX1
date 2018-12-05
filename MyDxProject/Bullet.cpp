#include"Bullet.h"
#include "ResourceManager.h"
#include <random>

//引数で発射位置の座標と角度を受け取り更新
Bullet::Bullet(ObjectTransform* transform) {
	_transform._position = transform->_position;
	_transform._angle = transform->_angle;
	_transform._size = Vector2D<float>(16, 16);//画像サイズを設定
	_tag = "Bullet";
}

Bullet::~Bullet() {

}

//開始処理
void Bullet::Start() {
	//弾画像
	std::random_device rand;
	_grp = ResourceManager::GetInstance()->LoadResource("Resource\\img\\bulletorigin.png");

	//サウンドロード
	_snd = ResourceManager::GetInstance()->LoadResource("Resource\\sound\\laser2.mp3", TYPE_SOUND);
	_damagesnd = ResourceManager::GetInstance()->LoadResource("Resource\\sound\\damage1.mp3", TYPE_SOUND);

	//サウンド再生
	PlaySoundMem(_snd, DX_PLAYTYPE_BACK);
}

//更新処理
void Bullet::Update() {
	//アフィン変換 速さ？
	float moveX = 3;
	float moveY = 0;

	_transform._moveVec._x = moveX * static_cast<float>(cos(_transform._angle)) -
		moveY*static_cast<float>(sin(_transform._angle));
	_transform._moveVec._y = moveX * static_cast<float>(sin(_transform._angle)) +
		moveY*static_cast<float>(cos(_transform._angle));
	_transform._position += _transform._moveVec;

	//画面からはみ出たら
	//左
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

//衝突検知: 弾が消える
void Bullet::OnHitBox(GameObject* other) {
	if (other->_tag == "Box")
		Destroy();
	//敵と弾が消える(はず)
	if (other->_tag == "Enemy") {
		PlaySoundMem(_damagesnd, DX_PLAYTYPE_BACK);
		other->Destroy();
		Destroy();
	}
}