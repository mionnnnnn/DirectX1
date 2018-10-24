#pragma once

template<typename T>
class Vector2D {
public:
	//�R���X�g���N�^
	Vector2D() : _x(0), _y(0) {

	}

	//�����t���R���X�g���N�^
	Vector2D(float x, float y) :_x(x), _y(y) {

	}

	//���Z�q�I�[�o�[���[�h�u+�v
	Vector2D & operator + (const Vector2D& vec) {
		Vector2D t(this->_x + vec._x, this->_y + vec._y);
		return t;
	}

	//���Z�q�I�[�o�[���[�h�u+=�v
	Vector2D& operator +=(const Vector2D& vec) {
		this->_x += vec._x;
		this->_y += vec._y;
		return *this;
	}

	//�u-�v
	Vector2D & operator - (const Vector2D& vec) {
		Vector2D t(this->_x - vec._x, this->_y - vec._y);
		return t;
	}

	//�u-=�v
	Vector2D& operator -=(const Vector2D& vec) {
		this->_x -= vec._x;
		this->_y -= vec._y;
		return *this;
	}

	//�x�N�g���̒���
	float length() {
		return std::sqrt(_x*_x, _y*_y);
	}

	//����
	T dot(const Vector2D& vec) {
		return (_x*vec._x) + (_y*vec._y);
	}

	//�x�N�g���̐��K��
	Vector2D normalize() {
		return{ _x / length(), _y / length() };
	}

public:
	T _x;
	T _y;
};
