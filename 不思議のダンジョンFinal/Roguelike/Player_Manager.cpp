#include "Player_Manager.h"

// �R���X�g���N�^
Player_Manager::Player_Manager() {
	player = std::make_shared<Player>();
	dungeon_manager = std::make_shared<Dungeon_Manager>();
	create_dungeon = std::make_shared<Create_Dungeon>();	
}

// �f�X�g���N�^
Player_Manager::~Player_Manager() {

}

//�@�v���C���[��z�u����
void Player_Manager::Player_Arrange() {
	
}
