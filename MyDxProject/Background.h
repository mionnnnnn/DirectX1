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

private:
	int _grp;
	int _snd;
};