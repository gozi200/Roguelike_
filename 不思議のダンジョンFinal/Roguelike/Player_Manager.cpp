#include "Player_Manager.h"

// コンストラクタ
Player_Manager::Player_Manager() {
	player = std::make_shared<Player>();
	dungeon_manager = std::make_shared<Dungeon_Manager>();
	create_dungeon_map = std::make_shared<Create_Dungeon_Map>();	
}

// デストラクタ
Player_Manager::~Player_Manager() {

}

//　プレイヤーを配置する
void Player_Manager::Player_Arrange() {
	
}
