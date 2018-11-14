#include "Box.h"

Box::Box() {
	_transform._position = Vector2D<float>(0, 0);
	_transform._size = Vector2D<float>(32, 32);
}

Box::Box(Vector2D<float> pos) {
	_transform._position = pos;
	_transform._size = Vector2D<float>(32, 32);
}

Box::Box(Vector2D<float>pos, std::string tag) {
	_transform._position = pos;
	_transform._size = Vector2D<float>(32, 32);
	_tag = tag;
}

Box:: ~Box() {

}
void Box::Start() {

}
void Box::Update() {

}
//��`�`��
//�f�t�H���g�͍���Ȃ̂ŁA�I�u�W�F�N�g�̒��S�ɂȂ�悤�ɁB
//�\�����W�̒������s���Ă���
void Box::Draw() {
	DrawBox(
		static_cast<int>(_transform._position._x - _transform._size._x / 2),
		static_cast<int>(_transform._position._y - _transform._size._y / 2),
		static_cast<int>(_transform._position._x + _transform._size._x / 2),
		static_cast<int>(_transform._position._y + _transform._size._y / 2),
		GetColor(255, 255, 255), TRUE);
}

void Box::OnHitBox(GameObject* other) {
	//�Փ˂�����I�u�W�F�N�g�j��
	Destroy();
}
