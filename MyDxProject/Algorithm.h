#pragma once

//アルゴリズムクラス
class Algorithm {
public:
	//メンバテンプレート
	template<typename T>
	static T Clamp(T x, T min, T max) {
		//最小値を下回ったら最小値を返す
		//最大値を上回ったら最大値を返す
		if (x < min)
			return min;
		else if (x>max)
			return max;

		//条件に当てはまらないなら値は返却
		return x;
	}
};
