#pragma once

/*--------------------------
床の種類の判断に使用するクラス
---------------------------*/

class Tile_Judge {
/*-------
メンバ変数
--------*/
public:
	bool is_wall;		// 壁かどうか
	bool is_upstairs;	// 昇り階段かどうか
	bool is_downstairs;	// 下り階段かどうか

/*--------
メンバ関数
---------*/
public:
	// コンストラクタ
	Tile_Judge() {};

	// デストラクタ
	~Tile_Judge() {};

};