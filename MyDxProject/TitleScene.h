#pragma once
#include"IScene.h"
#include"SceneManager.h"

class TitleScene : public IScene {
public:
	void Initialize();
	void MainLoop();
	void Release();

private:
	//BGM�p
	int _sound;
	//�t�H���g�p
	int _font;
	int _image;
};