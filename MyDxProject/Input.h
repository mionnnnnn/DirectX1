#pragma once
#include "DxLib.h"

//�A�ő΍�N���X
class Input {
public:
	static int UpdateKey() {
		char tmpKey[256];
		GetHitKeyStateAll(tmpKey);
		for (int i = 0; i < 256; i++) {
			if (tmpKey[i] != 0)
				_keys[i]++;
			else
				_keys[i] = 0;
		}
		return 0;
	}

	static int GetKey(int keycode) {
		return _keys[keycode];
	}

private:
	//�L�[��������Ă���t���[�������i�[
	static int _keys[256];
};