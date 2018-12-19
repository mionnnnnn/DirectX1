#include "TitleScene.h"
#include "GameScene.h"
#include "ResourceManager.h"
#include "Input.h"

void TitleScene::Initialize() {
	//sound load
	_sound = ResourceManager::GetInstance()->LoadResource(
		"Resource\\sound\\Sousa-Stars-and-Stripes-Forever.mp3", TYPE_SOUND);
	PlaySoundMem(_sound, DX_PLAYTYPE_LOOP);

	//to get font
	_font = CreateFontToHandle("���C���I", 32, 0, DX_FONTTYPE_NORMAL);
}

void TitleScene::MainLoop() {
	//�t�H���g�w��ł�������
	DrawStringToHandle(240, 240, "�^�C�g�����", GetColor(255, 255, 255), _font);
	//DrawString(280, 200, "Title", GetColor(255, 255, 255));
	//DrawString(280, 240, "Press Space Key", GetColor(255, 255, 255));

	//�L�[�Ŏ��̃V�[��
	Input::UpdateKey();
	if (Input::GetKey(KEY_INPUT_SPACE) == 1) {
		StopSoundMem(_sound);
		DeleteFontToHandle(_font);
		SceneManager::GetInstance()->LoadScene(new GameScene());
	}
	//int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//if (key & PAD_INPUT_10) {
	//	StopSoundMem(_sound);
	//	DeleteFontToHandle(_font);
	//	SceneManager::GetInstance()->LoadScene(new GameScene());
	//}
}

void TitleScene::Release() {}