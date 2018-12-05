#include"Bullet.h"
#include "ResourceManager.h"
#include <random>

//�����Ŕ��ˈʒu�̍��W�Ɗp�x���󂯎��X�V
Bullet::Bullet(ObjectTransform* transform) {
	_transform._position = transform->_position;
	_transform._angle = transform->_angle;
	_transform._size = Vector2D<float>(16, 16);//�摜�T�C�Y��ݒ�
	_tag = "Bullet";
}

Bullet::~Bullet() {

}

//�J�n����
void Bullet::Start() {
	//�e�摜
	std::random_device rand;
	_grp = ResourceManager::GetInstance()->LoadResource("Resource\\img\\bulletorigin.png");

	//�T�E���h���[�h
	_snd = ResourceManager::GetInstance()->LoadResource("Resource\\sound\\laser2.mp3", TYPE_SOUND);
	_damagesnd = ResourceManager::GetInstance()->LoadResource("Resource\\sound\\damage1.mp3", TYPE_SOUND);

	//�T�E���h�Đ�
	PlaySoundMem(_snd, DX_PLAYTYPE_BACK);
}

//�X�V����
void Bullet::Update() {
	//�A�t�B���ϊ� �����H
	float moveX = 3;
	float moveY = 0;

	_transform._moveVec._x = moveX * static_cast<float>(cos(_transform._angle)) -
		moveY*static_cast<float>(sin(_transform._angle));
	_transform._moveVec._y = moveX * static_cast<float>(sin(_transform._angle)) +
		moveY*static_cast<float>(cos(_transform._angle));
	_transform._position += _transform._moveVec;

	//��ʂ���͂ݏo����
	//��
	if (_transform._position._x < 0)
		Destroy();
	//�E
	if (_transform._position._x > 640)
		Destroy();
	//��
	if (_transform._position._y < 0)
		Destroy();
	//��
	if (_transform._position._y > 480)
		Destroy();
}

void Bullet::Draw() {
	DrawGraph(
		static_cast<int>(_transform._position._x - (_transform._size._x / 2)),
		static_cast<int>(_transform._position._y - (_transform._size._y / 2)),
		_grp, TRUE);
}

//�Փˌ��m: �e��������
void Bullet::OnHitBox(GameObject* other) {
	if (other->_tag == "Box")
		Destroy();
	//�G�ƒe��������(�͂�)
	if (other->_tag == "Enemy") {
		PlaySoundMem(_damagesnd, DX_PLAYTYPE_BACK);
		other->Destroy();
		Destroy();
	}
}