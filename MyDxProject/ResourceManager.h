#pragma once
#include<string>
#include<map>
#include"DxLib.h"

//列挙型を宣言
enum RESOURCE_TYPE : int {
	TYPE_IMAGE, TYPE_SOUND
};

//Flyweightパターンを使用したリソース管理クラス
class ResourceManager {
public:
	//インスタンス取得
	static ResourceManager* GetInstance();

	//インスタンス破棄
	static void DestroyInstance();

	//リソースをロード
	int LoadResource(std::string filename, RESOURCE_TYPE type = TYPE_IMAGE);

private:
	//リソースのハンドラを格納するDB
	std::map <std::string, int>_resourceDB;
	//インスタンス
	static ResourceManager* _instance;
};