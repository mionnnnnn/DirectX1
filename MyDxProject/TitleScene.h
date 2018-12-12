#pragma once
#include"IScene.h"
#include"SceneManager.h"

class TitleScene : public IScene {
public:
	void Initialize();
	void MainLoop();
	void Release();
};