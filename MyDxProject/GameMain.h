#pragma once
//#include"DxLib.h"
//#include "Player.h"
//#include "GameObject.h"
//#include "Box.h"
//#include "GameObjectContainer.h"
#include "ResourceManager.h"
#include"DxLib.h"
#include "Player.h"
#include"Enemy.h"
#include "Background.h"
#include "SpawnController.h"
#include "Score.h"
#include "Timer.h"

class GameMain {
public:
	void Initialize();
	void MainLoop();
	void Release();
private:
	//Player* _player;
	//GameObject* _box;
	//Background* _background;
	//SpawnController* _enemySpawn;
	//Score* _score;
	//Timer* _timer;
	//GameObject* _player;
	//Enemy* _enemy;
};
