#pragma once
#include "DxLib.h"
#include "GameObject.h"

//スコア
class Score : public GameObject {
public:
	Score();
	~Score();

	void Start();
	void Update();
	void Draw();
	
	//スコア加算
	void AddScore();

private:
	int _score;
};
