#pragma once

#include"Define.h"
#include"Player.h"
#include"Make_Dungeon_Map.h"

#include<memory>

/*--------------------------
作られたデータを元に画像を描画
--------------------------*/

class Make_Dungeon {
/*--------
メンバ変数
--------*/
private:
	std::shared_ptr<Player> player;
	std::shared_ptr<Make_Dungeon_Map> make_dungeon_map;

/*-------
メンバ関数
--------*/
public:
	// コンストラクタ
	Make_Dungeon();

	// デストラクタ
	~Make_Dungeon();

	// ダンジョンを作る
	void Render();

	// ダンジョンの初期化 (ダンジョン進入時、階層移動時に呼ばれる)
	void Initialize_Dungeon();
};