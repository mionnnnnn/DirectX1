#pragma once

//�V�[���̊��N���X�@�C���^�[�t�F�[�X
class IScene {
public:
	//������
	virtual void Initialize() = 0;
	//���C�����[�v
	virtual void MainLoop() = 0;
	//���
	virtual void Release() = 0;
};