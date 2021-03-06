#pragma once
#include"IObservable.h"
#include"IObserver.h"
#include<list>

// SubjectNX
// Ï@ÎÛÆÈèNXÌo^ÆAÊmðS¤
template<typename T>
class Subject : public IObservable<T>, public IObserver<T> {
public:
	//CxgÌÊmæðo^
	void Subscribe(std::function<void(T)> func) {
		_list.push_back(std::move(func));
	}

	//CxgðÊm
	void OnNext(T value) {
		for (std::function<void(T)>s : _list)
			s(value);
	}

	//Ï@ÎÛðí
	void Dispose() {
		_list.clear();
	}

private:
	//Ï@ÎÛXg
	std::list<std::function<void(T)>>_list;
};