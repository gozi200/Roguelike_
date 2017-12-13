#pragma once

#include"Tile.h"
#include"Wall.h"
#include"Player_Manager.h"
#include"Create_Dungeon.h"
#include"Dungeon_Manager.h"

#include"Player.h"

#include<string>
#include<memory>

/*----------------------------
ダンジョンの画面を描画するクラス
-----------------------------*/

class Dungeon_GUI : public Create_Dungeon {
private:
	std::shared_ptr<Player_Manager> player_manager;
	std::shared_ptr<Tile> tile;
	std::shared_ptr<Wall> wall;

	std::shared_ptr<Player> player;

	int x,             // 画面全体の座標(横)
		y;             // 画面全体の座標(縦)
	int map_x,         // マップの座標(横)
		map_y;         // マップの座標(縦)
	int character_x,   // キャラクターの座標(縦)
		character_y;   // キャラクターの座標(横)
	int dungeon_x,     // ダンジョンの座標(縦)
		dungeon_y;     // ダンジョンの座標(横)

	int loop_cont;     // ループの回数を数える

/*--------
メンバ関数
---------*/
public:
	// コンストラクタ
	Dungeon_GUI();

	// デストラクタ
	~Dungeon_GUI();

	//画面の描画
	void Render();
};