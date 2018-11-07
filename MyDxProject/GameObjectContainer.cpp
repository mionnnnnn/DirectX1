#include"GameObjectContainer.h"

//	10/31
//コンテナにgameobjectを追加
//	11/07
//GameObjectContainerのインスタンスを格納するstatic変数を宣言
//staticメンバ変数を定義するには、「クラス名＋"::"＋静的メンバ変数名」という
//グローバル変数を宣言する

GameObjectContainer* GameObjectContainer::_instance = NULL;

void GameObjectContainer::AddGameObject(GameObject* object) {
	//nullなら処理しない
	if (object == NULL)
		return;
	object->Start();//GameObjectが追加されると勝手にStart()が呼ばれる
	_container.push_back(object);
}

//コンテナに格納されているgamoebjectクラスのstart()呼び出し
void GameObjectContainer::Start() {
	for (auto itr = _container.begin(); itr != _container.end(); itr++) {
		//nullは実行しない
		if ((*itr) == NULL)
			continue;
		(*itr)->Start();
	}
}

//Draw()呼び出し
void GameObjectContainer::Draw() {
	for (auto itr = _container.begin(); itr != _container.end(); itr++) {
		//nullは実行しない
		if ((*itr) == NULL)
			continue;
		(*itr)->Draw();
	}
}
void GameObjectContainer::Update() {
	for (auto itr = _container.begin(); itr != _container.end(); itr++) {
		//nullは実行しない
		if ((*itr) == NULL)
			continue;
		(*itr)->Update();
	}
}

//解放
void GameObjectContainer::Release() {
	for (auto itr = _container.begin(); itr != _container.end(); itr++) {
		//nullは実行しない
		if ((*itr) == NULL)
			continue;
		delete(*itr);
	}
}

//衝突判定
void GameObjectContainer::HitCheck() {
	for (auto itr = _container.begin(); itr != _container.end(); itr++) {
		//既に破棄済みなら処理スキップ
		if ((*itr)->HasDestroy())
			continue;

		for (auto tgt = _container.begin(); tgt != _container.end(); tgt++) {
			if ((*tgt)->HasDestroy())
				continue;
			if (tgt == itr)
				continue;

			//おぶじぇくとの矩形情報を取得
			float srcLeft = (*itr)->_transform._position._x -
				((*itr)->_transform._size._x / 2);
			float srcTop = (*itr)->_transform._position._y -
				((*itr)->_transform._size._y / 2);
			float srcRight = (*itr)->_transform._position._x +
				((*itr)->_transform._size._x / 2);
			float srcBottom = (*itr)->_transform._position._y +
				((*itr)->_transform._size._y / 2);

			//衝突対称オブジェクトの矩形情報を取得
			float tgtLeft = (*tgt)->_transform._position._x -
				((*tgt)->_transform._size._x / 2);
			float tgtTop = (*tgt)->_transform._position._y -
				((*tgt)->_transform._size._y / 2);
			float tgtRight = (*tgt)->_transform._position._x +
				((*tgt)->_transform._size._x / 2);
			float tgtBottom = (*tgt)->_transform._position._y +
				((*tgt)->_transform._size._y / 2);

			//バウンディングボックス判定
			if (srcLeft < tgtRight &&
				srcTop < tgtBottom &&
				tgtLeft < srcRight&&
				tgtTop < srcBottom)
				(*itr)->OnHitBox((*tgt));//衝突検知のメソッド呼び出し
		}
	}
}

//コンテナに格納されているobjがdestroy状態か確認
void GameObjectContainer::DestroyCheck() {
	for (auto itr = _container.begin(); itr != _container.end();) {
		//既に破棄済みなら処理スキップ
		if ((*itr)->HasDestroy()) {
			delete (*itr);
			itr = _container.erase(itr);
			continue;
		}
		itr++;
	}
}

//インスタンス取得用のstaticメンバ関数を宣言
GameObjectContainer* GameObjectContainer::GetInstance()
{
	if (_instance == NULL)
		_instance = new GameObjectContainer();
	return _instance;
}

//インスタンス解放用のstaticメンバ関数を宣言
void GameObjectContainer::DestroyInstance() {
	if (_instance != NULL) {
		delete _instance;
		_instance = NULL;
	}
}
