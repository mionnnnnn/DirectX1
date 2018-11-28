#pragma once
#include<functional> // �����_���g�p�̂���

//�ώ@����鑤:player�N���X
//�ώ@���鑤:gamemain�N���X
//����:�I�u�U�[�o�[

//IObservable�C���^�[�t�F�[�X
//�Ď�����N���X��ǉ�����C���^�[�t�F�[�X
//https://qiita.com/mattak/items/106dfd0974653aa06fbc
template<typename T>
class IObservable {
public:
	//���z�f�X�g���N�^
	virtual ~IObservable(){}

	//�����̓o�^
	virtual void Subscribe(std::function<void(T)>func) = 0;
};