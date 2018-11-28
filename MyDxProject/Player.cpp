#include "Player.h"
//#include "Vector2D.h"
//#include"Bullet.h" //�폜
#include"GameObjectContainer.h"

//�R���X�g���N�^
Player::Player()// :_pos(320,240), _moveVec(0,0), _angle(0) 
{
	_transform._position = Vector2D<float>(320, 240);
	_transform._size = Vector2D<float>(64, 64);
	_waitFrame = 0;
}

Player::Player(std::string tag) {
	_transform._position = Vector2D<float>(320, 240);
	_transform._size = Vector2D<float>(64, 64);
	_waitFrame = 0;
	_tag = tag;
}

//�f�X�g���N�^
Player::~Player() {

}
//�J�n����
void Player::Start() {
	_grp = LoadGraph("Resource\\img\\playerorigin.png");
	
}

//�X�V
void Player::Update() {
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//��������Ă�����O�ɐi��
	if (key & PAD_INPUT_UP) {
		_transform._position += _transform._moveVec;
	}

	if (key & PAD_INPUT_DOWN) {
		_transform._position -= _transform._moveVec;
	}

	//�E�L�[�ŉE��]������
	if (key & PAD_INPUT_RIGHT)
		_transform._angle += ToRadian(4);

	//���L�[�ō���]
	if (key & PAD_INPUT_LEFT)
		_transform._angle -= ToRadian(4);

	//�ҋ@�t���[����0
	if (_waitFrame == 0) {
		//�{�^���������ƒe���ˁiSpace�j
		if (key & PAD_INPUT_10) {
			//GameObjectContainer::GetInstance()->AddGameObject(new Bullet(&_transform));
			Shot();//�ǉ�
			_waitFrame = 1;//�t���[���̒l��1�ɂ���
		}
	}
	else
	{
		//�ҋ@���Ԃ����Z
		_waitFrame++;
		//�ҋ@���Ԃ����𒴂�����
		if (_waitFrame > SHOT_DELAYFRAME) 
			_waitFrame = 0;
	}

	//�A�t�B���ϊ�
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

// ���� �ǉ� ����
// �e�𔭎˂����{�^�������ꂽ���Ƃ�Subscribe���ꂽ�����ɒʒm����
void Player::Shot() {
	ObjectTransform transform;
	transform._position = this->_transform._position;
	transform._angle = this->_transform._angle;
	_shotSubject.OnNext(transform);
}

// �e�𔭎˂���{�^���������ꂽ�ۂɎ��s����Subject��Ԃ�
IObservable<ObjectTransform>* Player::OnShotButton() {
	return &_shotSubject;
}