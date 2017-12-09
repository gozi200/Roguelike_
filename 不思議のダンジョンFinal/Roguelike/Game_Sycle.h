#pragma once

#include"Create_Dungeon.h"

#include<memory>

class Game_Sycle {
/*--------
メンバ変数
---------*/
	std::shared_ptr<Create_Dungeon> create_dungeon = std::shared_ptr<Create_Dungeon>(new Create_Dungeon());

/*--------
メンバ関数
----------*/
private:
	// コンストラクタ
	Game_Sycle();

	// デストラクタ
	~Game_Sycle();

	// 初期化。ゲームシーン移行後、階層移動後に呼ばれる
	void Initialize();
};