#include"ResourceManager.h"

//ResourceManager�̃C���X�^���X
ResourceManager* ResourceManager::_instance = NULL;

//�C���X�^���X���擾
ResourceManager* ResourceManager::GetInstance() {
	if (_instance == NULL)
		_instance = new ResourceManager();
	return _instance;
}

//�C���X�^���X�j��
void ResourceManager::DestroyInstance() {
	if (_instance != NULL) {
		delete _instance;
		_instance = NULL;
	}
}

//���\�[�X�����[�h
int ResourceManager::LoadResource(std::string filename, RESOURCE_TYPE type){
	//DB�Ɋi�[����Ă��Ȃ��ꍇ�ALoadGraph���g�p���Ď擾
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
	//DB�ɓo�^����Ă��郊�\�[�X��ID��Ԃ�
	return _resourceDB[filename.c_str()];
}