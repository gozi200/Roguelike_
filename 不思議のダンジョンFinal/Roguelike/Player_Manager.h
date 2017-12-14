#pragma once

#include"Player.h"
#include"Random.h"
#include"Dungeon_Manager.h"
#include"Create_Dungeon_Map.h"

#include<memory>

class Player_Manager {
/*--------
�����o�ϐ�
--------*/
private:
	int map_x, map_y,
		character_x, character_y,
		dungeon_y, dungeon_x;

	Random random;
	std::shared_ptr<Player> player;
	std::shared_ptr<Dungeon_Manager> dungeon_manager;
	std::shared_ptr<Create_Dungeon_Map> create_dungeon_map;

/*-------
�����o�֐�
--------*/
public:
	// �R���X�g���N�^
	Player_Manager();

	// �f�X�g���N�^
	~Player_Manager();

private:
	// �v���C���[��z�u����
	void Player_Arrange();
};