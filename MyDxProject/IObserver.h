#pragma once

// �I�u�U�[�o�[�C���^�[�t�F�[�X
// observe : �Ď�����
template<typename T>
class IObserver {
public:
	//���z�f�X�g���N�^
	virtual ~IObserver(){}

	//�I�u�U�[�o�[�ɓo�^���ꂽ���u�̎��s
	virtual void OnNext(T value) = 0;
};