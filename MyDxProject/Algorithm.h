#pragma once

//�A���S���Y���N���X
class Algorithm {
public:
	//�����o�e���v���[�g
	template<typename T>
	static T Clamp(T x, T min, T max) {
		//�ŏ��l�����������ŏ��l��Ԃ�
		//�ő�l����������ő�l��Ԃ�
		if (x < min)
			return min;
		else if (x>max)
			return max;

		//�����ɓ��Ă͂܂�Ȃ��Ȃ�l�͕ԋp
		return x;
	}
};
