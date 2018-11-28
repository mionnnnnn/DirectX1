#pragma once

// オブザーバーインターフェース
// observe : 監視する
template<typename T>
class IObserver {
public:
	//仮想デストラクタ
	virtual ~IObserver(){}

	//オブザーバーに登録された処置の実行
	virtual void OnNext(T value) = 0;
};