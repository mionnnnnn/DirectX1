#include"Particle.h"
#include "ResourceManager.h"

//コンストラクタ
//引数で座標を受け取り更新
Particle::Particle(Vector2D<float> pos) {
	_transform._position = pos;
}

//引数で座標を受け取り更新
Particle::Particle(ObjectTransform* transform) {
	_transform._position = transform->_position;
	_transform._angle = transform->_angle;
	_transform._size = Vector2D<float>(1, 1);
}

//デストラクタ
Particle::~Particle() {

}

void Particle::Start() {
	//花火の存在を初期化
	int i;
	for (i = 0; i < MAX_SPARK; i++)
		Spark[i].Valid = 0;

	//花火を作成
	CreateSpark();
}

void Particle::Update() {
	//花火の移動処理
	int i;
	for (i = 0; i < MAX_SPARK; i++) {
		//花火データが無効だったらスキップ
		if (Spark[i].Valid == 0)
			continue;

		//位置を移動力に応じてズラす
		Spark[i].X += Spark[i].Sx;
		Spark[i].Y += Spark[i].Sy;

		//移動力を変更
		Spark[i].Sy += Spark[i].G;

		//明るさを下げる
		Spark[i].Bright -= 2;

		//花火の明るさが0以下になったら花火データを無効にする
		if (Spark[i].Bright < 0)
			Spark[i].Valid = 0;
	}

	for (int i = 0; i < MAX_SPARK; i++)
		if (Spark[i].Valid != 0)
			return;
	Destroy();
}

void Particle::Draw() {
	//花火を描画
	for (int i = 0; i < MAX_SPARK; i++)
		//花火データが有効な時のみ描画
		if (Spark[i].Valid == 1)
			DrawPixel(Spark[i].X / 100, Spark[i].Y / 100,
				GetColor(Spark[i].Bright, Spark[i].Bright, Spark[i].Bright));
}

//花火を作成
void Particle::CreateSpark() {
	for (int i = 0; i < MAX_SPARK; i++) {
		//花火の位置設定
		Spark[i].X = static_cast<int>(_transform._position._x) * 100;
		Spark[i].Y = static_cast<int>(_transform._position._y) * 100;

		//移動力を設定(DxLibのRand使用)
		Spark[i].Sx = GetRand(1000) - 500;
		Spark[i].Sy = -GetRand(500);

		//重さ
		Spark[i].G = GetRand(10);

		//明るさ
		Spark[i].Bright = 255;

		//花火データを使用中にセット
		Spark[i].Valid = 1;
	}
}