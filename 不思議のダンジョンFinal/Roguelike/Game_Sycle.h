#pragma once

#include"Create_Dungeon.h"

#include<memory>

class Game_Sycle {
/*--------
�����o�ϐ�
---------*/
	std::shared_ptr<Create_Dungeon> create_dungeon = std::shared_ptr<Create_Dungeon>(new Create_Dungeon());

/*--------
�����o�֐�
----------*/
private:
	// �R���X�g���N�^
	Game_Sycle();

	// �f�X�g���N�^
	~Game_Sycle();

	// �������B�Q�[���V�[���ڍs��A�K�w�ړ���ɌĂ΂��
	void Initialize();
};