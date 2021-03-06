#pragma once

#include"Tile.h"
#include"Wall.h"
#include"Dungeon_Manager.h"
#include"Create_Dungeon_Map.h"

/*-------------------------------------
ダンジョンのデータを参照し、画像を配置する
--------------------------------------*/

class Make_Dungeon_Map : public Create_Dungeon_Map {
private:
	std::shared_ptr<Tile> tile;
	std::shared_ptr<Wall> wall;

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
	Make_Dungeon_Map();

	// デストラクタ
	~Make_Dungeon_Map();

	//画面の描画
	void Render();

	void DebugOutput();
};