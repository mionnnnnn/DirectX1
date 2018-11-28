#pragma once
#include"IObservable.h"
#include"IObserver.h"
#include<list>

// Subject�N���X
// �ώ@�ΏۂƂȂ�N���X�̓o�^�ƁA�ʒm��S��
template<typename T>
class Subject : public IObservable<T>, public IObserver<T> {
public:
	//�C�x���g�̒ʒm���o�^
	void Subscribe(std::function<void(T)> func) {
		_list.push_back(std::move(func));
	}

	//�C�x���g��ʒm
	void OnNext(T value) {
		for (std::function<void(T)>s : _list)
			s(value);
	}

	//�ώ@�Ώۂ��폜
	void Dispose() {
		_list.clear();
	}

private:
	//�ώ@�Ώۃ��X�g
	std::list<std::function<void(T)>>_list;
};