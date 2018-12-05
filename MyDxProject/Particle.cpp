#include"Particle.h"
#include "ResourceManager.h"

//�R���X�g���N�^
//�����ō��W���󂯎��X�V
Particle::Particle(Vector2D<float> pos) {
	_transform._position = pos;
}

//�����ō��W���󂯎��X�V
Particle::Particle(ObjectTransform* transform) {
	_transform._position = transform->_position;
	_transform._angle = transform->_angle;
	_transform._size = Vector2D<float>(1, 1);
}

//�f�X�g���N�^
Particle::~Particle() {

}

void Particle::Start() {
	//�ԉ΂̑��݂�������
	int i;
	for (i = 0; i < MAX_SPARK; i++)
		Spark[i].Valid = 0;

	//�ԉ΂��쐬
	CreateSpark();
}

void Particle::Update() {
	//�ԉ΂̈ړ�����
	int i;
	for (i = 0; i < MAX_SPARK; i++) {
		//�ԉ΃f�[�^��������������X�L�b�v
		if (Spark[i].Valid == 0)
			continue;

		//�ʒu���ړ��͂ɉ����ăY����
		Spark[i].X += Spark[i].Sx;
		Spark[i].Y += Spark[i].Sy;

		//�ړ��͂�ύX
		Spark[i].Sy += Spark[i].G;

		//���邳��������
		Spark[i].Bright -= 2;

		//�ԉ΂̖��邳��0�ȉ��ɂȂ�����ԉ΃f�[�^�𖳌��ɂ���
		if (Spark[i].Bright < 0)
			Spark[i].Valid = 0;
	}

	for (int i = 0; i < MAX_SPARK; i++)
		if (Spark[i].Valid != 0)
			return;
	Destroy();
}

void Particle::Draw() {
	//�ԉ΂�`��
	for (int i = 0; i < MAX_SPARK; i++)
		//�ԉ΃f�[�^���L���Ȏ��̂ݕ`��
		if (Spark[i].Valid == 1)
			DrawPixel(Spark[i].X / 100, Spark[i].Y / 100,
				GetColor(Spark[i].Bright, Spark[i].Bright, Spark[i].Bright));
}

//�ԉ΂��쐬
void Particle::CreateSpark() {
	for (int i = 0; i < MAX_SPARK; i++) {
		//�ԉ΂̈ʒu�ݒ�
		Spark[i].X = static_cast<int>(_transform._position._x) * 100;
		Spark[i].Y = static_cast<int>(_transform._position._y) * 100;

		//�ړ��͂�ݒ�(DxLib��Rand�g�p)
		Spark[i].Sx = GetRand(1000) - 500;
		Spark[i].Sy = -GetRand(500);

		//�d��
		Spark[i].G = GetRand(10);

		//���邳
		Spark[i].Bright = 255;

		//�ԉ΃f�[�^���g�p���ɃZ�b�g
		Spark[i].Valid = 1;
	}
}