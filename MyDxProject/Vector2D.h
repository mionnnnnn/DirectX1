#pragma once

template<typename T>
class Vector2D {
public:
	//コンストラクタ
	Vector2D() : _x(0), _y(0) {

	}

	//引数付きコンストラクタ
	Vector2D(float x, float y) :_x(x), _y(y) {

	}

	//演算子オーバーロード「+」
	Vector2D & operator + (const Vector2D& vec) {
		Vector2D t(this->_x + vec._x, this->_y + vec._y);
		return t;
	}

	//演算子オーバーロード「+=」
	Vector2D& operator +=(const Vector2D& vec) {
		this->_x += vec._x;
		this->_y += vec._y;
		return *this;
	}

	//「-」
	Vector2D & operator - (const Vector2D& vec) {
		Vector2D t(this->_x - vec._x, this->_y - vec._y);
		return t;
	}

	//「-=」
	Vector2D& operator -=(const Vector2D& vec) {
		this->_x -= vec._x;
		this->_y -= vec._y;
		return *this;
	}

	//ベクトルの長さ
	float length() {
		return std::sqrt(_x*_x, _y*_y);
	}

	//内積
	T dot(const Vector2D& vec) {
		return (_x*vec._x) + (_y*vec._y);
	}

	//ベクトルの正規化
	Vector2D normalize() {
		return{ _x / length(), _y / length() };
	}

public:
	T _x;
	T _y;
};
