#include "Player.h"
#include "Vector2D.h"
#include"Bullet.h"
#include"GameObjectContainer.h"

//コンストラクタ
Player::Player()// :_pos(320,240), _moveVec(0,0), _angle(0) 
{
	_transform._position = Vector2D<float>(320, 240);
	_transform._size = Vector2D<float>(64, 64);
	_waitFrame = 0;

}

//デストラクタ
Player::~Player() {

}
//開始処理

void Player::Start() {
	_grp = LoadGraph("Resource\\img\\player.png");
	
}

//更新
void Player::Update() {
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//上を押していたら前に進む
	if (key & PAD_INPUT_UP) {
		_transform._position += _transform._moveVec;
	}

	if (key & PAD_INPUT_DOWN) {
		_transform._position -= _transform._moveVec;
	}

	//右キーで右回転させる
	if (key & PAD_INPUT_RIGHT)
		_transform._angle += ToRadian(4);

	//左キーで左回転
	if (key & PAD_INPUT_LEFT)
		_transform._angle -= ToRadian(4);

	//待機フレームが0
	if (_waitFrame == 0) {
		//ボタンを押すと弾発射（Space）
		if (key & PAD_INPUT_10) {
			GameObjectContainer::GetInstance()->AddGameObject(new Bullet(&_transform));
			_waitFrame = 1;//フレームの値を1にする
		}
	}
	else
	{
		//待機時間を加算
		_waitFrame++;
		//待機時間が一定を超えたら
		if (_waitFrame > SHOT_DELAYFRAME) 
			_waitFrame = 0;
	}

	//アフィン変換
	float moveX = 3;
	float moveY = 3;
	_transform._moveVec._x = 
		moveX * static_cast<float>(cos(_transform._angle)) -
		moveY * static_cast<float>(sin(_transform._angle));
	_transform._moveVec._y = 
		moveX * static_cast<float>(cos(_transform._angle)) +
		moveY * static_cast<float>(sin(_transform._angle));
}

void Player::Draw() {
	DrawRotaGraph(
		static_cast<int>(_transform._position._x), 
		static_cast<int>(_transform._position._y),
		1.0f, _transform._angle, _grp, TRUE, FALSE);
}