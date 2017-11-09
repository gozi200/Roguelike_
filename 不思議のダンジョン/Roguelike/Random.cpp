#include"Random.h"


//Random::Random() : engine(std::random_device()()) {
Random::Random() : engine(10){

}

Random::~Random() {

}

int Random::Dungeon_Random(int bet) {
	std::random_device rd;
	std::mt19937 mt(rd());
	//std::uint32_t random = engine(rd());

	auto uid = std::uniform_int_distribution<int>(0, bet);
	return uid(mt);
	//return random % bet;
}