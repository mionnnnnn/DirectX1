#pragma once
#include<functional> // ラムダ式使用のため

//観察される側:playerクラス
//観察する側:gamemainクラス
//処理:オブザーバー

//IObservableインターフェース
//監視するクラスを追加するインターフェース
//https://qiita.com/mattak/items/106dfd0974653aa06fbc
template<typename T>
class IObservable {
public:
	//仮想デストラクタ
	virtual ~IObservable(){}

	//処理の登録
	virtual void Subscribe(std::function<void(T)>func) = 0;
};