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
	std::vector<char*> graphics; // 画像のパスを格納する

/*--------
メンバ関数
---------*/
public:
	// コンストラクタ
	Tile_Graphic();

	// デストラクタ
	~Tile_Graphic();

	// 画像のあるフォルダのパスを配列に格納する
	void Load();
};