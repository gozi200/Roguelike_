#pragma once

class Tile_Judge {
public:
	bool is_wall; //�ǂ�������true

	bool is_up_stairs; //���K�i�Ȃ�true

	bool is_down_stairs; //����K�i�Ȃ�true

	bool is_drop_item; //�A�C�e���������Ă��邩

	Tile_Judge() {};

	~Tile_Judge() {};
};