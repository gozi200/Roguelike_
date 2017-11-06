#include "Tile_Function.h"

Tile_Function::Tile_Function() {
	Tile_data.Set_File_Pass("CSV/Stage/Tile/Tile.csv"); //床の情報を読み込む
	Tile_data.Open_File(); //読み込み
}

Tile_Function::~Tile_Function() {}

void Tile_Function::Draw_Tile(int call_ID) {
	//IDに合わせて画像を描画する
	switch (call_ID) {

	//草原用の床を描画
	case 1:
		for (std::vector<SETTING_Tile_DATA>::const_iterator setting_tile = Tile_data.set_Tile_data.cbegin();
			setting_tile != Tile_data.set_Tile_data.cend();
			++setting_tile, ++loop_count) {
			if (setting_tile->ID == TILE_GRASS) { //Define定数使用
				DrawExtendGraph(HALF_WINDOW_X,
					HALF_WINDOW_Y,
					HALF_WINDOW_X + setting_tile->width,
					HALF_WINDOW_Y + setting_tile->height,
					setting_tile->graphic_handle, TRUE);
			}
		} break;

	//洞窟用の床を描画
	case 2:
		for (std::vector<SETTING_Tile_DATA>::const_iterator setting_tile = Tile_data.set_Tile_data.cbegin();
			setting_tile != Tile_data.set_Tile_data.cend();
			++setting_tile, ++loop_count) {
			if (setting_tile->ID == TILE_CAVE) { //Define定数使用
				DrawExtendGraph(HALF_WINDOW_X,
					HALF_WINDOW_Y,
					HALF_WINDOW_X + setting_tile->width,
					HALF_WINDOW_Y + setting_tile->height,
					setting_tile->graphic_handle, TRUE);
			}
		} break;
	}
}


