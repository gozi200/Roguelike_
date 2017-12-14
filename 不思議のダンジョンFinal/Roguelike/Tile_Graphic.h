#pragma once

#include<vector>

/*--------------------------------------
床の画像ファイルのパスを配列に格納するクラス
---------------------------------------*/ 

class Tile_Graphic {
/*-------
メンバ変数
--------*/
public:
	std::vector<char*> graphics; // 画像ファイルのパスを格納する

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