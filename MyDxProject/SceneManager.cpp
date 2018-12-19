#include"SceneManager.h"
#include "ResourceManager.h"

//�C���X�^���X
SceneManager* SceneManager::_instance = NULL;

//���̃V�[���m�F
void SceneManager::CheckNextScene() {
	if (_nextScene != NULL) {
		delete _currentScene;
		_currentScene = NULL;
		_currentScene = _nextScene;
		_nextScene = NULL;
	}
}

//�C���X�^���X�擾�pstatic
SceneManager* SceneManager::GetInstance() {
	if (_instance == NULL)
		_instance = new SceneManager();
	return _instance;
}

//�X�V
void SceneManager::Update() {
	FPS fps;
	
	//���C�����[�v
	while (ProcessMessage()==0&&CheckHitKey(KEY_INPUT_ESCAPE)==0) {
		ClearDrawScreen();
		switch (_sceneState) {
			//������
		case SCENE_INITIALIZE:
			_currentScene->Initialize();
			_sceneState = SCENE_UPDATE;
			break;
			//���[�v
		case SCENE_UPDATE:
			_currentScene->MainLoop();
			break;
			//���
		case SCENE_RELEASE:
			_currentScene->Release();
			CheckNextScene();
			_sceneState = SCENE_INITIALIZE;
			break;
		}

		//����ʂ̓��e�\��ʂɔ��f������
		fps.Update();
		fps.Draw();
		ScreenFlip();
		fps.Wait();
	}

	//�����Ń��\�[�X����(GameScene����ړ�)
	ResourceManager::DestroyInstance();

	//�V�[���̃I�u�W�F�N�g�����
	if (_currentScene != NULL) {
		_currentScene->Release();
		delete _currentScene;
		_currentScene = NULL;
	}

	if (_nextScene != NULL) {
		delete _nextScene;
		_nextScene = NULL;
	}
}

//���̃V�[���̃|�C���^��n��
void SceneManager::LoadScene(IScene* scene) {
	if (_currentScene == NULL) {
		_currentScene = scene;
		_sceneState = SCENE_INITIALIZE;
	}
	else {
		_nextScene = scene;
		_sceneState = SCENE_RELEASE;
	}
}
