#pragma once

#include<vector>

/*--------------------------
床の画像を配列に格納するクラス
----------------------------*/

class Tile_Graphic {
public:
/*-------
メンバ変数
--------*/
	std::vector<char*> graphics;

/*--------
メンバ関数
---------*/
	void Load();
};