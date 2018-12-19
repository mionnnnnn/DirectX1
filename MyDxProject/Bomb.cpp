#include "Bomb.h"
#include "ResourceManager.h"

Bomb::Bomb(ObjectTransform* transform) {
	_transform._position = transform->_position;
	_tag = "Bomb";
	_transform._size = Vector2D<float>(96, 96);
	_index = 0;
}

Bomb::~Bomb() {
	//画像を解放する
	for (int i = 0; i < 8; i++)
		DeleteGraph(_grp[i]);
}

void Bomb::Start() {
	//アニメーション用グラフィックロード
	LoadDivGraph("Resource\\img\\BOMB.png", 8, 8, 1, 96, 96, _grp);
	_sound = ResourceManager::GetInstance()->LoadResource("Resource\\sound\\bomb.mp3", TYPE_SOUND);
	PlaySoundMem(_sound, DX_PLAYTYPE_BACK);
}

void Bomb::Update() {

}

void Bomb::Draw() {
	DrawGraph(
		static_cast<int>(_transform._position._x - _transform._size._x / 2),
		static_cast<int>(_transform._position._y - _transform._size._y / 2),
		_grp[_index], TRUE);

	//8枚でアニメーション
	_index++;
	if (_index >= 8)
		Destroy();
}