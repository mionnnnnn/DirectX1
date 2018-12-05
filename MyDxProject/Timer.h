#pragma once
#include "DxLib.h"
#include "GameObject.h"

class Timer : public GameObject {
public:
	Timer();
	~Timer();

	void  Start();
	void Update();
	void Draw();

private:
	int _time;
};
