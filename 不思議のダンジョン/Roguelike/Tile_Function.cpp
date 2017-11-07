#include "Tile_Function.h"

Tile_Function::Tile_Function() {
	Tile_data.Set_File_Pass("CSV/Stage/Tile/Tile.csv"); //°‚Ìî•ñ‚ğ“Ç‚İ‚Ş
	Tile_data.Open_File(); //“Ç‚İ‚İ
}

Tile_Function::~Tile_Function() {}

void Tile_Function::Draw_Tile(int call_ID) {
	//ID‚É‡‚í‚¹‚Ä‰æ‘œ‚ğ•`‰æ‚·‚é
	for (std::vector<SETTING_Tile_DATA>::const_iterator setting_tile = Tile_data.set_Tile_data.cbegin();
		setting_tile != Tile_data.set_Tile_data.cend();
		++setting_tile, ++loop_count) {
		if (setting_tile->ID == call_ID) { //Define’è”g—p
			DrawExtendGraph(HALF_WINDOW_X,
				HALF_WINDOW_Y,
				HALF_WINDOW_X + setting_tile->width,
				HALF_WINDOW_Y + setting_tile->height,
				setting_tile->graphic_handle, TRUE);
		}
	}
}
