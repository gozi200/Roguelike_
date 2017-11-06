#pragma once

#include<vector>

/*//////////////////////////////
装飾品の画像を配列に格納するクラス
*///////////////////////////////

class Accessorie_Graphic {
public:
	std::vector<char*> accessorie_graphic;

	void Load();
};