#include "Background.h"
#include "ResourceManager.h"

Background::Background()
{
	_transform._position = Vector2D<float>(0, 0);
	_transform._size = Vector2D<float>(0, 0);
}

Background::~Background()
{

}

void Background::Start()
{
	_grp = LoadGraph("Resource\\img\\bg.png");
	//サウンドロード
	_snd = ResourceManager::GetInstance()->LoadResource("Resource\\sound\\gameplay_BGM.mp3", TYPE_SOUND);

	//再生
	PlaySoundMem(_snd, DX_PLAYTYPE_LOOP);
}

void Background::Update()
{

}

void Background::Draw()
{
	DrawGraph(static_cast<int>(_transform._position._x),
		static_cast<int>(_transform._position._y),
		_grp, TRUE);
}