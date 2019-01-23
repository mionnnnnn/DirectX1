#pragma once
#include"IScene.h"
#include"SceneManager.h"

class TitleScene : public IScene {
public:
	void Initialize();
	void MainLoop();
	void Release();

private:
	//BGM用
	int _sound;
	//フォント用
	int _font;
	int _image;
};