#include "Tile.h"

Tile::Tile() {
	Tile_data.Set_File_Pass("CSV/Stage/Tile/Tile.csv"); //CSVファイルから情報を読み込む
	Tile_data.Open_File(); //ファイルを開いて読み込む
}

Tile::~Tile() {}

void Tile::Draw_Tile(int call_ID, int set_x, int set_y) {
	//IDに合わせて画像を描画する
	for (std::vector<SETTING_TILE_DATA>::const_iterator setting_tile = Tile_data.set_tile_data.cbegin();
		setting_tile != Tile_data.set_tile_data.cend();
		++setting_tile, ++loop_count) {
		if (setting_tile->ID == call_ID) { //Define定数使用
			DrawExtendGraph(set_x,
				set_y,
				set_x + setting_tile->width,
				set_y + setting_tile->height,
				setting_tile->graphic_handle, TRUE);
		}
	}
}