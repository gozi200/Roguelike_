#pragma once

#include<vector>

/*/////////////////////////////////
プレイヤーの画像を配列に格納するクラス
*//////////////////////////////////

class Player_Graphic {
public:
	std::vector<char*> player_graphic;

	void Load();
};