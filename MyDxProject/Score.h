#pragma once
#include "DxLib.h"
#include "GameObject.h"

//�X�R�A
class Score : public GameObject {
public:
	Score();
	~Score();

	void Start();
	void Update();
	void Draw();
	
	//�X�R�A���Z
	void AddScore();

private:
	int _score;
};
