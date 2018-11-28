#pragma once
#include"IObservable.h"
#include"IObserver.h"
#include<list>

// Subjectクラス
// 観察対象となりクラスの登録と、通知を担う
template<typename T>
class Subject : public IObservable<T>, public IObserver<T> {
public:
	//イベントの通知先を登録
	void Subscribe(std::function<void(T)> func) {
		_list.push_back(std::move(func));
	}

	//イベントを通知
	void OnNext(T value) {
		for (std::function<void(T)>s : _list)
			s(value);
	}

	//観察対象を削除
	void Dispose() {
		_list.clear();
	}

private:
	//観察対象リスト
	std::list<std::function<void(T)>>_list;
};