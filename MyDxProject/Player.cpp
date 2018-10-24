#include "Player.h"
#include "Vector2D.h"

//コンストラクタ
Player::Player() :_x(320), _y(240), _moveVecX(5), _moveVecY(0), _angle(0) {

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
		_x += _moveVecX;
		_y += _moveVecY;
	}

	//右キーで右回転させる
	if (key && PAD_INPUT_RIGHT)
		_angle += ToRadian(4);

	//左キーで左回転
	if (key && PAD_INPUT_LEFT)
		_angle -= ToRadian(4);

	//アフィン変換
	float moveX = 3;
	float moveY = 0;
	_moveVecX = moveX * static_cast<float>(cos(_angle)) -
		moveY * static_cast<float>(sin(_angle));
	_moveVecY = moveX * static_cast<float>(cos(_angle)) +
		moveY * static_cast<float>(sin(_angle));
}

void Player::Draw() {
	DrawRotaGraph(static_cast<int>(_x), static_cast<int>(_y),
		1.0f, _angle, _grp, TRUE, FALSE);
}