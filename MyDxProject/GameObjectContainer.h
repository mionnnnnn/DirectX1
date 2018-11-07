#pragma once
#include"GameObject.h"
#include<list>

class GameObjectContainer {
private:
	//コンストラクタ群をprivateにし、
	//外からインスタンスが生成できないようにする
	GameObjectContainer(){}
	GameObjectContainer(const GameObjectContainer&){}

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
	//インスタンス取得用のstaticメンバ関数を宣言
	static GameObjectContainer* GetInstance();
	//インスタンス解放用のstaticメンバ関数を宣言
	static void DestroyInstance();

private: 
	//オブジェクトコンテナ
	std::list<GameObject*> _container;
	//インスタンス（実体）格納用のstatic変数
	static GameObjectContainer* _instance;
};