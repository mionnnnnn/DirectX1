#pragma once

//シーンの基底クラス　インターフェース
class IScene {
public:
	//初期化
	virtual void Initialize() = 0;
	//メインループ
	virtual void MainLoop() = 0;
	//解放
	virtual void Release() = 0;
};