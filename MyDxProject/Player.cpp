#include "Player.h"
#include "Vector2D.h"

//�R���X�g���N�^
Player::Player() :_pos(320,240), _moveVec(0,0), _angle(0) {

}

//�f�X�g���N�^
Player::~Player() {

}
//�J�n����

void Player::Start() {
	_grp = LoadGraph("Resource\\img\\player.png");
	
}

//�X�V
void Player::Update() {
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//��������Ă�����O�ɐi��
	if (key & PAD_INPUT_UP) {
		_pos += _moveVec;
	}

	if (key & PAD_INPUT_DOWN) {
		_pos -= _moveVec;
	}

	//�E�L�[�ŉE��]������
	if (key & PAD_INPUT_RIGHT)
		_angle += ToRadian(4);

	//���L�[�ō���]
	if (key & PAD_INPUT_LEFT)
		_angle -= ToRadian(4);

	//�A�t�B���ϊ�
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