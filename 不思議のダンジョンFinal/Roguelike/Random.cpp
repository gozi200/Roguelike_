#include"random.h"

// �R���X�g���N�^
Random::Random() : engine(10) {

}

// �R���X�g���N�^
Random::~Random() {

}

//�������擾����
int Random::Dungeon_Random(int bet) {
	std::random_device rd;
	std::mt19937 mt(rd());

	auto uid = std::uniform_int_distribution<int>(0, bet);
	return uid(mt);
}