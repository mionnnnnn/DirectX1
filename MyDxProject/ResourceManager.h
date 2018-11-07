#pragma once
#include<string>
#include<map>
#include"DxLib.h"

//Flyweightパターンを使用したリソース管理クラス
class ResourceManager {
public:
	//インスタンス取得
	static ResourceManager* GetInstance();

	//インスタンス破棄
	static void DestroyInstance();

	//リソースをロード
	int LoadResource(std::string filename);

private:
	//リソースのハンドラを格納するDB
	std::map <std::string, int>_resourceDB;
	//インスタンス
	static ResourceManager* _instance;
};