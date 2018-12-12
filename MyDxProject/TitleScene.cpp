#include "TitleScene.h"
#include "GameScene.h"

void TitleScene::Initialize() {}

void TitleScene::MainLoop() {
	DrawString(280, 200, "Title", GetColor(255, 255, 255));
	DrawString(280, 240, "Press Space Key", GetColor(255, 255, 255));

	//キーで次のシーン
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (key & PAD_INPUT_10)
		SceneManager::GetInstance()->LoadScene(new GameScene());
}

void TitleScene::Release() {}