#pragma once
#include"DxLib.h"
#include "Player.h"
#include "GameObject.h"
#include "Box.h"
#include "GameObjectContainer.h"
#include "ResourceManager.h"
#include"DxLib.h"
#include "Player.h"
#include"Enemy.h"

class GameMain {
public:
	void Initialize();
	void MainLoop();
	void Release();
private:
	//GameObject* _player;
	Player* _player;
	Enemy* _enemy;
	GameObject* _box;
};
