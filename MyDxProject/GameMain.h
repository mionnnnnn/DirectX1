#pragma once
#include"DxLib.h"
#include "Player.h"

class GameMain {
public:
	void Initialize();
	void MainLoop();
	void Release();
private:
	Player _player;
	int key;
	int playerX = 0;
	int playerY = 0;
	int playerGraph;
};
