#pragma once
#include "Vector2D.h"

//2D�X�v���C�g�����܂Ƃ߂��N���X
class ObjectTransform {
public:
	ObjectTransform() : _position(0, 0), _angle(0), _scale(1, 1), _moveVec(0, 0), _size(0, 0) {

	}
	ObjectTransform(Vector2D<float> pos) : _position(pos), _angle(0), _scale(1, 1), _moveVec(0, 0), _size(0, 0) {

	}

public:
	Vector2D<float> _position;//���W
	float _angle;//��]�p�x
	Vector2D<float> _scale;//�g�嗦
	Vector2D<float> _moveVec;//�ړ���
	Vector2D<float> _size;//�X�v���C�g�T�C�Y
};