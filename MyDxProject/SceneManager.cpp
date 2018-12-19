#include"SceneManager.h"
#include "ResourceManager.h"

//インスタンス
SceneManager* SceneManager::_instance = NULL;

//次のシーン確認
void SceneManager::CheckNextScene() {
	if (_nextScene != NULL) {
		delete _currentScene;
		_currentScene = NULL;
		_currentScene = _nextScene;
		_nextScene = NULL;
	}
}

//インスタンス取得用static
SceneManager* SceneManager::GetInstance() {
	if (_instance == NULL)
		_instance = new SceneManager();
	return _instance;
}

//更新
void SceneManager::Update() {
	FPS fps;
	
	//メインループ
	while (ProcessMessage()==0&&CheckHitKey(KEY_INPUT_ESCAPE)==0) {
		ClearDrawScreen();
		switch (_sceneState) {
			//初期化
		case SCENE_INITIALIZE:
			_currentScene->Initialize();
			_sceneState = SCENE_UPDATE;
			break;
			//ループ
		case SCENE_UPDATE:
			_currentScene->MainLoop();
			break;
			//解放
		case SCENE_RELEASE:
			_currentScene->Release();
			CheckNextScene();
			_sceneState = SCENE_INITIALIZE;
			break;
		}

		//裏画面の内容表画面に反映させる
		fps.Update();
		fps.Draw();
		ScreenFlip();
		fps.Wait();
	}

	//ここでリソース消す(GameSceneから移動)
	ResourceManager::DestroyInstance();

	//シーンのオブジェクトを解放
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

//次のシーンのポインタを渡す
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
