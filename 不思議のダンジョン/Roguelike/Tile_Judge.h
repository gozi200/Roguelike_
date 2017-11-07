#pragma once

class Tile_Judge {
public:
	bool is_wall; //壁だったらtrue

	bool is_up_stairs; //上り階段ならtrue

	bool is_down_stairs; //下り階段ならtrue

	bool is_drop_item; //アイテムが落ちているか

	Tile_Judge() {};

	~Tile_Judge() {};
};