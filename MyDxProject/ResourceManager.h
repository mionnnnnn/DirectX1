#pragma once
#include<string>
#include<map>
#include"DxLib.h"

//�񋓌^��錾
enum RESOURCE_TYPE : int {
	TYPE_IMAGE, TYPE_SOUND
};

//Flyweight�p�^�[�����g�p�������\�[�X�Ǘ��N���X
class ResourceManager {
public:
	//�C���X�^���X�擾
	static ResourceManager* GetInstance();

	//�C���X�^���X�j��
	static void DestroyInstance();

	//���\�[�X�����[�h
	int LoadResource(std::string filename, RESOURCE_TYPE type = TYPE_IMAGE);

private:
	//���\�[�X�̃n���h�����i�[����DB
	std::map <std::string, int>_resourceDB;
	//�C���X�^���X
	static ResourceManager* _instance;
};