#include"random.h"

// コンストラクタ
Random::Random() : engine(10) {

}

// コンストラクタ
Random::~Random() {

}

//乱数を取得する
int Random::Dungeon_Random(int bet) {
	std::random_device rd;
	std::mt19937 mt(rd());

	auto uid = std::uniform_int_distribution<int>(0, bet);
	return uid(mt);
}