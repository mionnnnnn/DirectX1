#pragma once
#include"DxLib.h"

class FPS {
	int startTime;//測定開始時刻
	int count;//カウンター
	float fps;//fps
	static const int N = 60;//平均をとるサンプル数
	static const int staticFps = 60;//設定したfps

public:
	FPS() {//コンストラクタ
		startTime = 0;
		count = 0;
		fps = 0;
	}
	//更新
	bool Update() {
		if(count == 0)//1フレーム目なら
			startTime = GetNowCount();//時刻を記憶
		if (count == N) {//60フレーム目なら平均を計算する
			int t = GetNowCount();
			fps = 1000.0f / ((t - startTime) / (float)N);
			count = 0;
			startTime = t;
		}
		count++;
		return true;
	}
	//描画
	void Draw() {
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", fps);
	}
	//処理を待つ
	void Wait() {
		int tookTime = GetNowCount() - startTime;//かかった時間
		int waitTime = count * 1000 / staticFps - tookTime;//待つべき時間
		if (waitTime > 0)
			Sleep(waitTime);//待機
	}
};