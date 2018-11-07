#include"GameObjectContainer.h"

//	10/31
//�R���e�i��gameobject��ǉ�
//	11/07
//GameObjectContainer�̃C���X�^���X���i�[����static�ϐ���錾
//static�����o�ϐ����`����ɂ́A�u�N���X���{"::"�{�ÓI�����o�ϐ����v�Ƃ���
//�O���[�o���ϐ���錾����

GameObjectContainer* GameObjectContainer::_instance = NULL;

void GameObjectContainer::AddGameObject(GameObject* object) {
	//null�Ȃ珈�����Ȃ�
	if (object == NULL)
		return;
	object->Start();//GameObject���ǉ������Ə����Start()���Ă΂��
	_container.push_back(object);
}

//�R���e�i�Ɋi�[����Ă���gamoebject�N���X��start()�Ăяo��
void GameObjectContainer::Start() {
	for (auto itr = _container.begin(); itr != _container.end(); itr++) {
		//null�͎��s���Ȃ�
		if ((*itr) == NULL)
			continue;
		(*itr)->Start();
	}
}

//Draw()�Ăяo��
void GameObjectContainer::Draw() {
	for (auto itr = _container.begin(); itr != _container.end(); itr++) {
		//null�͎��s���Ȃ�
		if ((*itr) == NULL)
			continue;
		(*itr)->Draw();
	}
}
void GameObjectContainer::Update() {
	for (auto itr = _container.begin(); itr != _container.end(); itr++) {
		//null�͎��s���Ȃ�
		if ((*itr) == NULL)
			continue;
		(*itr)->Update();
	}
}

//���
void GameObjectContainer::Release() {
	for (auto itr = _container.begin(); itr != _container.end(); itr++) {
		//null�͎��s���Ȃ�
		if ((*itr) == NULL)
			continue;
		delete(*itr);
	}
}

//�Փ˔���
void GameObjectContainer::HitCheck() {
	for (auto itr = _container.begin(); itr != _container.end(); itr++) {
		//���ɔj���ς݂Ȃ珈���X�L�b�v
		if ((*itr)->HasDestroy())
			continue;

		for (auto tgt = _container.begin(); tgt != _container.end(); tgt++) {
			if ((*tgt)->HasDestroy())
				continue;
			if (tgt == itr)
				continue;

			//���Ԃ������Ƃ̋�`�����擾
			float srcLeft = (*itr)->_transform._position._x -
				((*itr)->_transform._size._x / 2);
			float srcTop = (*itr)->_transform._position._y -
				((*itr)->_transform._size._y / 2);
			float srcRight = (*itr)->_transform._position._x +
				((*itr)->_transform._size._x / 2);
			float srcBottom = (*itr)->_transform._position._y +
				((*itr)->_transform._size._y / 2);

			//�ՓˑΏ̃I�u�W�F�N�g�̋�`�����擾
			float tgtLeft = (*tgt)->_transform._position._x -
				((*tgt)->_transform._size._x / 2);
			float tgtTop = (*tgt)->_transform._position._y -
				((*tgt)->_transform._size._y / 2);
			float tgtRight = (*tgt)->_transform._position._x +
				((*tgt)->_transform._size._x / 2);
			float tgtBottom = (*tgt)->_transform._position._y +
				((*tgt)->_transform._size._y / 2);

			//�o�E���f�B���O�{�b�N�X����
			if (srcLeft < tgtRight &&
				srcTop < tgtBottom &&
				tgtLeft < srcRight&&
				tgtTop < srcBottom)
				(*itr)->OnHitBox((*tgt));//�Փˌ��m�̃��\�b�h�Ăяo��
		}
	}
}

//�R���e�i�Ɋi�[����Ă���obj��destroy��Ԃ��m�F
void GameObjectContainer::DestroyCheck() {
	for (auto itr = _container.begin(); itr != _container.end();) {
		//���ɔj���ς݂Ȃ珈���X�L�b�v
		if ((*itr)->HasDestroy()) {
			delete (*itr);
			itr = _container.erase(itr);
			continue;
		}
		itr++;
	}
}

//�C���X�^���X�擾�p��static�����o�֐���錾
GameObjectContainer* GameObjectContainer::GetInstance()
{
	if (_instance == NULL)
		_instance = new GameObjectContainer();
	return _instance;
}

//�C���X�^���X����p��static�����o�֐���錾
void GameObjectContainer::DestroyInstance() {
	if (_instance != NULL) {
		delete _instance;
		_instance = NULL;
	}
}
