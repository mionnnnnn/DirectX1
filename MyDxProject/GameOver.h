#pragma once
#include "DxLib.h"
#include "GameObject.h"
#include <math.h>

class GameOver : public GameObject {
public:
	GameOver();
	virtual ~GameOver();

	void Start();
	void Update();
	void Draw();

private:
	int _grp;
	int _snd;
};