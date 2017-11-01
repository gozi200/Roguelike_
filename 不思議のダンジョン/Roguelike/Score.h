#pragma once

#include<algorithm>
#include<assert.h>

class Score {
public:
	Score(int set_score = 0) : score(set_score) {
		clamp(); //固定の意 ここでは上限を指す
	}

	void add(int set_score) {
		assert(0 <= set_score && set_score <= 1000000);
		score += set_score;
		clamp();
	}

	void clear() {
		score = 0;
	}

	int get() const {
		return score;
	}

private:
	int score; //得点

	void clamp() {
		score = std::min(score, 9999999);
	}
};