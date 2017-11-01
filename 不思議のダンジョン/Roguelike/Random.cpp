#include"Random.h"

#include<iostream>
#include<random>

Random::Random() {

}

Random::~Random() {

}

int Random::Dungeon_Random(int bet) {
	std::random_device seed_gen;

	std::mt19937 engine(seed_gen());

	std::uint32_t random = engine();

	return random % bet;
}