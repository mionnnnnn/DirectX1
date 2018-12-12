#include "Logo.h"

void Logo::Initialize() {
	_timer = new Timer();
	GameObjectContainer::GetInstance()->AddGameObject(_timer);
}

void Logo::MainLoop() {
	DrawString(260, 200, "ƒƒS ©ƒƒS", GetColor(255, 255, 255));
	_timer->Update();
	if (_timer->TimeCheck())
		SceneManager::GetInstance()->LoadScene(new TitleScene());
}

void Logo::Release(){}