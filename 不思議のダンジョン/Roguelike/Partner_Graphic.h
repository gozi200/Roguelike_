#pragma once

#include<vector>

/*////////////////////////////
相方の画像を配列に格納するクラス
*/////////////////////////////

class Partner_Graphic {
public:
	std::vector<char*> partner_graphic;

	void Load();
};