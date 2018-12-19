#include "GameOver.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "Input.h"

GameOver::GameOver() {
	_transform._size = Vector2D<float>(640, 320);
	_transform._position = Vector2D<float>(320, 240);
}

GameOver::~GameOver(){}

void GameOver::Start() {
	_grp = ResourceManager::GetInstance()->LoadResource("Resource\\img\\GameOver.png");
	_snd = ResourceManager::GetInstance()->
		LoadResource("Resource\\sound\\Bad.mp3", TYPE_SOUND);
	PlaySoundMem(_snd, DX_PLAYTYPE_BACK);
}

void GameOver::Update() {
	Input::UpdateKey();
	if (Input::GetKey(KEY_INPUT_SPACE)) {
		StopSoundMem(_snd);
		SceneManager::GetInstance()->LoadScene(new GameScene());
	}

	//ª‘‚«Š·‚¦
	//int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//if (key & PAD_INPUT_10) {
	//	StopSoundMem(_snd);
	//	SceneManager::GetInstance()->LoadScene(new TitleScene());
	//}
}

void GameOver::Draw() {
	DrawGraph(
		static_cast<int>(_transform._position._x - _transform._size._x / 2),
		static_cast<int>(_transform._position._y - _transform._size._y / 2),
		_grp, TRUE);
}