#pragma once
#include "DxLib.h"
#include "GameObject.h"
#include <math.h>

//�w�i�\���N���X
class Background : public GameObject
{
public:
	Background();
	~Background();
	void Start();
	void Update();
	void Draw();
	void stopBGM();

private:
	int _grp;
	int _jukensei;
	int _snd;
};