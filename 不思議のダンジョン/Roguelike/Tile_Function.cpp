#include "Tile_Function.h"

Tile_Function::Tile_Function() {
	Tile_data.Set_File_Pass("CSV/Stage/Tile/Tile.csv"); //���̏���ǂݍ���
	Tile_data.Open_File(); //�ǂݍ���
}

Tile_Function::~Tile_Function() {}

void Tile_Function::Draw_Tile(int call_ID, int set_x, int set_y) {
	//ID�ɍ��킹�ĉ摜��`�悷��
	for (std::vector<SETTING_TILE_DATA>::const_iterator setting_tile = Tile_data.set_tile_data.cbegin();
		setting_tile != Tile_data.set_tile_data.cend();
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
