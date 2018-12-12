#pragma once
#include "DxLib.h"
#include "FPS.h"
#include "IScene.h"

//シーン管理クラス(シングルトン)
class SceneManager {
private:
	//コンストラクタ＆デストラクタ
	SceneManager() : _sceneState(SCENE_INITIALIZE), _currentScene(NULL), _nextScene(NULL){}
	SceneManager(const SceneManager&){}
	//次のシーン確認
	void CheckNextScene();

public:
	//インスタンス取得用のstaticメンバ関数
	static SceneManager* GetInstance();
	//更新
	void Update();
	//次のシーンを設定
	void LoadScene(IScene* scene);

private:
	enum SCENE_STATE {
		SCENE_INITIALIZE, SCENE_UPDATE, SCENE_RELEASE
	};
	//今のシーン
	IScene* _currentScene;
	//次のシーン
	IScene* _nextScene;
	//シーンの実行状態
	SCENE_STATE _sceneState;
	//インスタンス
	static SceneManager* _instance;
};