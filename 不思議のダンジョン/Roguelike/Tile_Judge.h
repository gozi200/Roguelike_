#pragma once

class Tile_Judge {
public:
	//�ԍ��Ŕ��f����H

	bool is_wall = false; //�ǂ�������true

	bool is_up_stairs = false; //���K�i�Ȃ�true

	bool is_down_stairs = false; //����K�i�Ȃ�true

	//bool is_drop_item = false; //�A�C�e���������Ă��邩

	Tile_Judge() {};

	~Tile_Judge() {};
};