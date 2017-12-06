#pragma once

#include"Item.h"

class Tile_Judge {
public:
	//番号で判断する？

	bool is_wall = false; //壁だったらtrue

	bool is_up_stairs = false; //上り階段ならtrue

	bool is_down_stairs = false; //下り階段ならtrue

	bool is_Mini_Map_On = false; //ミニマップの表示

	Item* drop_item;


	Tile_Judge() {};

	~Tile_Judge() {};
};