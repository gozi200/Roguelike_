#pragma once

#include"Player.h"
#include"Random.h"
#include"Create_Dungeon.h"
#include"Dungeon_Manager.h"

#include<memory>

class Player_Manager {
/*--------
�����o�ϐ�
--------*/
public:
	int map_x, map_y,
		character_x, character_y,
		dungeon_y, dungeon_x;

	Random random;
	std::shared_ptr<Player> player;
	std::shared_ptr<Create_Dungeon> create_dungeon;
	std::shared_ptr<Dungeon_Manager> dungeon_manager;

/*-------
�����o�֐�
--------*/
public:
	// �R���X�g���N�^
	Player_Manager();

	// �f�X�g���N�^
	~Player_Manager();

	// �v���C���[��z�u����
	void Player_Arrange();
};