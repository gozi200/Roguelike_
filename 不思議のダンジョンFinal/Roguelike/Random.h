#pragma once

#include"Define.h"

#include<random>

/*------------------------------
MT�@���g�p���ė������擾����N���X
-------------------------------*/
static class Random {
public:
/*--------
�����o�ϐ�
---------*/


/*////////
�����o�֐�
*/////////
public:
	// �R���X�g���N�^
	Random();

	// �f�X�g���N�^
	~Random();

	/*�������擾����
	  @param bet 
	*/
	int Dungeon_Random(int bet);

private:
	std::mt19937 engine;
};
