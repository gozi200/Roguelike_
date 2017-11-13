#pragma once

class Tile_Judge {
public:
	//番号で判断する？

	bool is_wall = false; //壁だったらtrue

	bool is_up_stairs = false; //上り階段ならtrue

	bool is_down_stairs = false; //下り階段ならtrue

	//bool is_drop_item = false; //アイテムが落ちているか

	Tile_Judge() {};

	~Tile_Judge() {};
};