#pragma once
#include "Vector2D.h"

//2Dスプライト情報をまとめたクラス
class ObjectTransform {
public:
	ObjectTransform() : _position(0, 0), _angle(0), _scale(1, 1), _moveVec(0, 0), _size(0, 0) {

	}
	ObjectTransform(Vector2D<float> pos) : _position(pos), _angle(0), _scale(1, 1), _moveVec(0, 0), _size(0, 0) {

	}

public:
	Vector2D<float> _position;//座標
	float _angle;//回転角度
	Vector2D<float> _scale;//拡大率
	Vector2D<float> _moveVec;//移動量
	Vector2D<float> _size;//スプライトサイズ
};