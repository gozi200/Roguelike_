#pragma once
#include<random>

#include"Define.h"

static class Random {
public:
/*////////
�����o�ϐ�
*/////////


/*////////
�����o�֐�
*/////////
public:
	//�R���X�g���N�^
	Random();

	//�f�X�g���N�^
	~Random();

	int Dungeon_Random(int bet);

private:
	std::mt19937 engine;
};
