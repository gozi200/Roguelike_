#pragma once
#include<random>

#include"Define.h"

class Random {
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
