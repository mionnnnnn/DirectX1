#pragma once
#include"DxLib.h"

class FPS {
	int startTime;//����J�n����
	int count;//�J�E���^�[
	float fps;//fps
	static const int N = 60;//���ς��Ƃ�T���v����
	static const int staticFps = 60;//�ݒ肵��fps

public:
	FPS() {//�R���X�g���N�^
		startTime = 0;
		count = 0;
		fps = 0;
	}
	//�X�V
	bool Update() {
		if(count == 0)//1�t���[���ڂȂ�
			startTime = GetNowCount();//�������L��
		if (count == N) {//60�t���[���ڂȂ畽�ς��v�Z����
			int t = GetNowCount();
			fps = 1000.0f / ((t - startTime) / (float)N);
			count = 0;
			startTime = t;
		}
		count++;
		return true;
	}
	//�`��
	void Draw() {
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", fps);
	}
	//������҂�
	void Wait() {
		int tookTime = GetNowCount() - startTime;//������������
		int waitTime = count * 1000 / staticFps - tookTime;//�҂ׂ�����
		if (waitTime > 0)
			Sleep(waitTime);//�ҋ@
	}
};