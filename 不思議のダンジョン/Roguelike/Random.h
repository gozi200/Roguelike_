#pragma once

#include"Define.h"

class Random {
public:
/*////////
�����o�ϐ�
*/////////
	int random_number; //����o����闐��

/*////////
�����o�֐�
*/////////
public:
	//�R���X�g���N�^
	Random();

	//�f�X�g���N�^
	~Random();

	int Dungeon_Random(int bet);

};
