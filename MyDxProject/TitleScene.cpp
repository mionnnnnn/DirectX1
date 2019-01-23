#include "TitleScene.h"
#include "GameScene.h"
#include "ResourceManager.h"
#include "Input.h"

void TitleScene::Initialize() {
	//sound load
	_image = LoadGraph("Resource\\img\\juken03.png");
	//_sound = ResourceManager::GetInstance()->LoadResource(
	//	"Resource\\sound\\Sousa-Stars-and-Stripes-Forever.mp3", TYPE_SOUND);
	_sound = ResourceManager::GetInstance()->LoadResource(
		"Resource\\sound\\Twinkle-Little-Star.mp3", TYPE_SOUND);

	PlaySoundMem(_sound, DX_PLAYTYPE_LOOP);

	//to get font
	_font = CreateFontToHandle("UD �f�W�^�� ���ȏ��� NP-R", 35, 0, DX_FONTTYPE_NORMAL);
}

void TitleScene::MainLoop() {
	//�w�i
	DrawGraph(0, -70, _image, TRUE);

	//�t�H���g�w��ł�������
	DrawStringToHandle(50, 150, 
		"�Z���^�[�������T���Ă���j�̎q��\n�@�@�F���(��)�W�Q������Q�[��", 
		GetColor(0, 0, 0), _font);
	DrawStringToHandle(130, 250,
		"PRESS SPACE",
		GetColor(0, 0, 0), _font);
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