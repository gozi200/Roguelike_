#include"Random.h"


//Random::Random() : engine(std::random_device()()) {
Random::Random() : engine(10){

}

Random::~Random() {

}

int Random::Dungeon_Random(int bet) {
	std::uint32_t random = engine();

	auto uid = std::uniform_int_distribution<int>(0, bet);
	return uid(engine);
	//return random % bet;
}