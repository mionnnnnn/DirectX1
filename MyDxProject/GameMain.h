#pragma once
#include"DxLib.h"
#include "Player.h"
#include "GameObject.h"
#include "Box.h"
#include "GameObjectContainer.h"

class GameMain {
public:
	void Initialize();
	void MainLoop();
	void Release();
private:
	GameObject* _player;
	GameObject* _box;
	GameObjectContainer _container;
	//Player _player;
	//int key;
	//int playerX = 0;
	//int playerY = 0;
	//int playerGraph;
};
