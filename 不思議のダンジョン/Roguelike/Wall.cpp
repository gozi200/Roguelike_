#include "Wall.h"

Wall::Wall() {
	wall_data.Set_File_Pass("CSV/Stage/Wall/Wall.csv"); //•Ç‚Ìî•ñ‚ğ“Ç‚İ‚Ş
	wall_data.Open_File(); //“Ç‚İ‚İ
}

Wall::~Wall() {}

void Wall::Draw_Wall(int call_ID, int set_x, int set_y) {
	//ID‚É‡‚í‚¹‚Ä‰æ‘œ‚ğ•`‰æ‚·‚é
	for (std::vector<SETTING_WALL_DATA>::const_iterator setting_wall = wall_data.set_wall_data.cbegin();
		setting_wall != wall_data.set_wall_data.cend();
		++setting_wall, ++loop_count) {
		if (setting_wall->ID == call_ID) { //Define’è”g—p
			DrawExtendGraph(set_x,
				set_y,
				set_x + setting_wall->width,
				set_y + setting_wall->height,
				setting_wall->graphic_handle, TRUE);
		}
	}
}