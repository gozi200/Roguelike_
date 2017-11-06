#pragma once

#include<vector>

/*///////////////////////////////
食べ物の画像を配列に格納するクラス
*///////////////////////////////

class Food_Graphic {
public:
	std::vector<char*> food_graphic;

	void Load();
};