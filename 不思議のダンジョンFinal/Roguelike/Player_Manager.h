#pragma once

#include"Player.h"
#include"Dungeon_Manager.h"

#include<memory>

class Player_Manager {
/*--------
メンバ変数
--------*/
private:
	int map_x, map_y,
		character_x, character_y,
		dungeon_y, dungeon_x;

	std::shared_ptr<Player> player;
	std::shared_ptr<Dungeon_Manager> dungeon_manager;

/*-------
メンバ関数
--------*/
public:
	// コンストラクタ
	Player_Manager();

	// デストラクタ
	~Player_Manager();

	// プレイヤーを配置する
	void Player_Arrange();
};