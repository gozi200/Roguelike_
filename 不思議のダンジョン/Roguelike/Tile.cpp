#include "Tile.h"

Tile::Tile() {
	tile_data.Set_File_Pass("CSV/Stage/Tile/Tile.csv"); //CSV�t�@�C���������ǂݍ���
	tile_data.Open_File(); //�t�@�C�����J���ēǂݍ���

	loop_count = 0; //������
}

Tile::~Tile() {}

void Tile::Render(int call_ID, int set_x, int set_y) {
	//ID�ɍ��킹�ĉ摜��`�悷��
	for (std::vector<SETTING_TILE_DATA>::const_iterator setting_tile = tile_data.set_tile_data.cbegin();
		setting_tile != tile_data.set_tile_data.cend();
		++setting_tile, ++loop_count) {
		if (setting_tile->ID == call_ID) { //Define�萔�g�p
			DrawExtendGraph(set_x,
				set_y,
				set_x + setting_tile->width,
				set_y + setting_tile->height,
				setting_tile->graphic_handle, TRUE);
		}
	}
}