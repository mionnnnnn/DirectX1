#include "Enemy.h"
#include "GameObjectContainer.h"
#include <random>

//�R���X�g���N�^
Enemy::Enemy() {
	_transform._position = Vector2D<float>(0, 0);
	_transform._angle = 0;
	_transform._size = Vector2D<float>(64, 64);
	_target = NULL;
}

//�����t��
Enemy::Enemy(Vector2D <float> pos) {
	_transform._position = pos;
	_transform._size = Vector2D<float>(64, 64);
	_target = NULL;
}

//����&�^�O�t��
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
	//�ǐՂ���^�[�Q�b�g�����݂��Ȃ���΁A�������Ȃ�
	if (_target == NULL)
		return;

	//�^�[�Q�b�g�Ǝ��M�̍��W�����v�Z
	float y = _target->_transform._position._y - _transform._position._y;
	float x = _target->_transform._position._x - _transform._position._x;

	//atan2���g�p����2�_�Ԃ̊p�x���v�Z
	_transform._angle = atan2(y, x);

	//�A�t�B���ϊ� ����
	float moveX = 2;
	float moveY = 0;
	_transform._moveVec._x = 
		moveX * static_cast<float>(cos(_transform._angle)) -
		moveY * static_cast<float>(sin(_transform._angle));
	_transform._moveVec._y = 
		moveX * static_cast<float>(sin(_transform._angle)) +
		moveY * static_cast<float>(cos(_transform._angle));

	//�ړ��ʌv�Z
	_transform._position += _transform._moveVec;
}

void Enemy::Draw() {
	DrawRotaGraph(
		static_cast<int>(_transform._position._x),
		static_cast<int>(_transform._position._y),
		1.0f, _transform._angle, _grp, TRUE, FALSE);
}

//�ǐՂ���^�[�Q�b�g�ǉ�
void Enemy::SetTarget(GameObject* target) {
	_target = target;
}

void Enemy::OnHitBox(GameObject* other) {
	//�Փ˂����I�u�W�F�N�g��Bullet�������ꍇ
	if (other->_tag == "Bullet") {
		ObjectTransform transform;
		transform._position = this->_transform._position;
		_hitSubject.OnNext(transform);
		Destroy();
	}
	if (other->_tag == "Player") {

	}
}

//Subject��Ԃ�
IObservable<ObjectTransform>* Enemy::OnHit() {
	return &_hitSubject;
}