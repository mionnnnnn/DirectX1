#pragma once
#include "Timer.h"
#include "IScene.h"
#include "SceneManager.h"
#include "GameObjectContainer.h"
#include "TitleScene.h"

class Logo : public IScene {
public:
	void Initialize();
	void MainLoop();
	void Release();

private: 
	Timer* _timer;
	int _se;
	int _font;
};