#include "Logo.h"
#include "ResourceManager.h"

void Logo::Initialize() {
	_se = ResourceManager::GetInstance()->LoadResource(
		"Resource\\sound\\onepoint05.wav", TYPE_SOUND);
	PlaySoundMem(_se, DX_PLAYTYPE_BACK);
	_timer = new Timer();
	GameObjectContainer::GetInstance()->AddGameObject(_timer);
	_font = CreateFontToHandle("���C���I", 25, 0, DX_FONTTYPE_NORMAL);
}

void Logo::MainLoop() {
	DrawStringToHandle(250, 240, 
		"�Q�[���v���O���~���O�Q\n�@�@C++��b �ۑ�", GetColor(255, 255, 255), _font);
	_timer->Update();
	if (_timer->TimeCheck())
		SceneManager::GetInstance()->LoadScene(new TitleScene());
}

void Logo::Release(){}