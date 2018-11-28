#include"ResourceManager.h"

//ResourceManagerのインスタンス
ResourceManager* ResourceManager::_instance = NULL;

//インスタンスを取得
ResourceManager* ResourceManager::GetInstance() {
	if (_instance == NULL)
		_instance = new ResourceManager();
	return _instance;
}

//インスタンス破棄
void ResourceManager::DestroyInstance() {
	if (_instance != NULL) {
		delete _instance;
		_instance = NULL;
	}
}

//リソースをロード
int ResourceManager::LoadResource(std::string filename, RESOURCE_TYPE type){
	//DBに格納されていない場合、LoadGraphを使用して取得
	if (_resourceDB.find(filename.c_str()) == _resourceDB.end()) {
		switch (type)
		{
		case TYPE_IMAGE:
			_resourceDB[filename.c_str()] = LoadGraph(filename.c_str());
			break;
		case TYPE_SOUND:
			_resourceDB[filename.c_str()] = LoadSoundMem(filename.c_str());
			break;
		}
	}
	//DBに登録されているリソースのIDを返す
	return _resourceDB[filename.c_str()];
}