#pragma once
#include "GameObject.h"
#include "Subject.h"
#include <vector>
#include<random>
#define SPAWN_INTERVAL 60 //1��̃X�|�[���̑ҋ@����

//�X�|�[���R���g���[���N���X
class SpawnController : public GameObject {
public:
	SpawnController();
	~SpawnController();

	void Start();
	void Update();
	void Draw();
	void AddSpaenPoint(float x, float y); //�X�|�[���ꏊ�o�^
	IObservable<Vector2D<float>>* OnSpawn(); //�X�|�[���ʒm

private:
	//�X�|�[���T�u�W�F�N�g
	Subject<Vector2D<float>> _spawnSubject;

	//�X�|�[���ꏊ�����X�g�ŊǗ�
	std::vector<Vector2D<float>> _spawnPoints;

	//�X�|�[���܂ł̑ҋ@����
	float _wait;
};