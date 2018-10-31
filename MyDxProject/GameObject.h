#pragma once
#include"ObjectTransform.h"

//�Q�[�����\���I�u�W�F�N�g�̊��N���X
class GameObject {
public:
	GameObject() : isDestroy(false) {

	}
	virtual ~GameObject(){}
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	//�j��
	virtual void Destroy() {
		isDestroy = true;
	}
	//�f�X�g���C�t���O�擾
	bool HasDestroy() {
		return isDestroy;
	}

	//�Փˌ��m
	virtual void OnHitBox(GameObject* other){}

public:
	ObjectTransform _transform;
	bool isDestroy;
};