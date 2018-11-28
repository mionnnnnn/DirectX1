#pragma once
#include"DxLib.h"
#include"GameMain.h"
#include<math.h>
#define MAX_SPARK 50 //�p�[�e�B�N���ő吔

//�p�[�e�B�N���I�u�W�F�N�g
class Particle : public GameObject {
public:
	Particle(Vector2D<float> pos);
	Particle(ObjectTransform* transform);
	virtual ~Particle();

	void Start();
	void Update();
	void Draw();

	//�p�[�e�B�N������
	void CreateSpark();

private:
	//�Ήԃf�[�^�^
	typedef struct tagSPARK {
		int Valid;//���̃f�[�^���g�p�����̃t���O
		int X, Y;//�ԉ΂̈ʒu
		int Sx, Sy;//�ړ���
		int G;//�d��
		int Bright;//���邳
	} SPARK;

	//�ԉ΃f�[�^
	SPARK Spark[MAX_SPARK];
};