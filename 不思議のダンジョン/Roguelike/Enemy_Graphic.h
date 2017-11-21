#pragma once

#include<vector>

/*---------------------------------
エネミーの画像を配列に格納するクラス
----------------------------------*/

class Enemy_Graphic {
public:
	std::vector<char*> enemy_graphic;

	void Load();
};