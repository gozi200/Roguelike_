#pragma once

#include"Item.h"

class Tile_Judge {
public:
	//�ԍ��Ŕ��f����H

	bool is_wall = false; //�ǂ�������true

	bool is_up_stairs = false; //���K�i�Ȃ�true

	bool is_down_stairs = false; //����K�i�Ȃ�true

	bool is_Mini_Map_On = false; //�~�j�}�b�v�̕\��

	Item* drop_item;


	Tile_Judge() {};

	~Tile_Judge() {};
};