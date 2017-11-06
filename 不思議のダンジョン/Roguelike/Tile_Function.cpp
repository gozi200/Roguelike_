#include "Tile_Function.h"

Tile_Function::Tile_Function() {
	Tile_data.Set_File_Pass("CSV/Stage/Tile/Tile.csv"); //���̏���ǂݍ���
	Tile_data.Open_File(); //�ǂݍ���
}

Tile_Function::~Tile_Function() {}

void Tile_Function::Draw_Tile(int call_ID) {
	//ID�ɍ��킹�ĉ摜��`�悷��
	switch (call_ID) {

	//�����p�̏���`��
	case 1:
		for (std::vector<SETTING_Tile_DATA>::const_iterator setting_tile = Tile_data.set_Tile_data.cbegin();
			setting_tile != Tile_data.set_Tile_data.cend();
			++setting_tile, ++loop_count) {
			if (setting_tile->ID == TILE_GRASS) { //Define�萔�g�p
				DrawExtendGraph(HALF_WINDOW_X,
					HALF_WINDOW_Y,
					HALF_WINDOW_X + setting_tile->width,
					HALF_WINDOW_Y + setting_tile->height,
					setting_tile->graphic_handle, TRUE);
			}
		} break;

	//���A�p�̏���`��
	case 2:
		for (std::vector<SETTING_Tile_DATA>::const_iterator setting_tile = Tile_data.set_Tile_data.cbegin();
			setting_tile != Tile_data.set_Tile_data.cend();
			++setting_tile, ++loop_count) {
			if (setting_tile->ID == TILE_CAVE) { //Define�萔�g�p
				DrawExtendGraph(HALF_WINDOW_X,
					HALF_WINDOW_Y,
					HALF_WINDOW_X + setting_tile->width,
					HALF_WINDOW_Y + setting_tile->height,
					setting_tile->graphic_handle, TRUE);
			}
		} break;
	}
}


