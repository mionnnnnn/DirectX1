#include "Player.h"
#include "Vector2D.h"

//コンストラクタ
Player::Player() :_pos(320,240), _moveVec(0,0), _angle(0) {

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
		_pos += _moveVec;
	}

	if (key & PAD_INPUT_DOWN) {
		_pos -= _moveVec;
	}

	//右キーで右回転させる
	if (key & PAD_INPUT_RIGHT)
		_angle += ToRadian(4);

	//左キーで左回転
	if (key & PAD_INPUT_LEFT)
		_angle -= ToRadian(4);

	//アフィン変換
	float moveX = 3;
	float moveY = 0;
	_moveVec._x = moveX * static_cast<float>(cos(_angle)) -
		moveY * static_cast<float>(sin(_angle));
	_moveVec._y = moveX * static_cast<float>(cos(_angle)) +
		moveY * static_cast<float>(sin(_angle));
}

void Player::Draw() {
	DrawRotaGraph(static_cast<int>(_pos._x), static_cast<int>(_pos._y),
		1.0f, _angle, _grp, TRUE, FALSE);
}