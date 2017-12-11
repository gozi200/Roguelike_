#pragma once

#include<vector>

/*--------------------------
壁の画像を配列に格納するクラス
----------------------------*/

class Wall_Graphic {
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
	Wall_Graphic();

	// デストラクタ
	~Wall_Graphic();

	// 画像のあるフォルダのパスを配列に格納する
	void Load();
};