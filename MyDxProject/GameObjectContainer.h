#pragma once
#include"GameObject.h"
#include<list>

class GameObjectContainer {
public:
	//コンテナにGameObjectを追加
	void AddGameObject(GameObject* object);
	//コンテナに格納されているGameObjectクラスのStart()を呼び出す
	void Start();
	//Draw()呼び出し
	void Draw();
	//Update()呼び出し
	void Update();
	//解放する
	void Release();
	//gameobject同士の衝突判定を実行
	void HitCheck();
	//destroy状態か確認
	void DestroyCheck();

private: 
	std::list<GameObject*> _container;//オブジェクトコンテナ
};