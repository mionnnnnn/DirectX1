#include "SpawnController.h"

SpawnController::SpawnController() {
	_wait = 0;
}

SpawnController::~SpawnController() {

}

//�J�n
void SpawnController::Start() {
	_wait = 0;
}

//�X�V
void SpawnController::Update() {
	_wait++;

	//�C���^�[�o���ɓ��B���Ă��Ȃ��ꍇ�ȍ~�̏����͎��s���Ȃ�
	if (_wait < SPAWN_INTERVAL)
		return;

	//��������X�|�[���|�C���g��ݒ�
	std::random_device rand;
	int index = rand() % _spawnPoints.size();
	Vector2D<float> spawnPos = _spawnPoints[index];

	//�X�|�[���ʒm
	_spawnSubject.OnNext(spawnPos);

	//�ҋ@���ԃ��Z�b�g
	_wait = 0;
}

//�`��
void SpawnController::Draw() {

}

//�X�|�[���ꏊ�o�^
void SpawnController::AddSpaenPoint(float x, float y) {
	//vector�N���X��
	_spawnPoints.push_back(Vector2D<float>(x, y));
}

//�X�|�[���ʒm
IObservable<Vector2D<float>>* SpawnController::OnSpawn() {
	return &_spawnSubject;
}