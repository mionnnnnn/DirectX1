#pragma once
#include "DxLib.h"
#include "FPS.h"
#include "IScene.h"

//�V�[���Ǘ��N���X(�V���O���g��)
class SceneManager {
private:
	//�R���X�g���N�^���f�X�g���N�^
	SceneManager() : _sceneState(SCENE_INITIALIZE), _currentScene(NULL), _nextScene(NULL){}
	SceneManager(const SceneManager&){}
	//���̃V�[���m�F
	void CheckNextScene();

public:
	//�C���X�^���X�擾�p��static�����o�֐�
	static SceneManager* GetInstance();
	//�X�V
	void Update();
	//���̃V�[����ݒ�
	void LoadScene(IScene* scene);

private:
	enum SCENE_STATE {
		SCENE_INITIALIZE, SCENE_UPDATE, SCENE_RELEASE
	};
	//���̃V�[��
	IScene* _currentScene;
	//���̃V�[��
	IScene* _nextScene;
	//�V�[���̎��s���
	SCENE_STATE _sceneState;
	//�C���X�^���X
	static SceneManager* _instance;
};