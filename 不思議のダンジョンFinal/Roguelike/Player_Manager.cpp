#include "Player_Manager.h"

// コンストラクタ
Player_Manager::Player_Manager() {
	player = std::make_shared<Player>();
	dungeon_manager = std::make_shared<Dungeon_Manager>();
	create_dungeon = std::make_shared<Create_Dungeon>();	
}

// デストラクタ
Player_Manager::~Player_Manager() {

}

//　プレイヤーを配置する
void Player_Manager::Player_Arrange() {
	
}
