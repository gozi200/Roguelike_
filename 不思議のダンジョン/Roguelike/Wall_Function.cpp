#include "Wall_Function.h"

Wall_Function::Wall_Function() {
	wall_data.Set_File_Pass("CSV/Stage/Wall/Wall.csv"); //壁の情報を読み込む
	wall_data.Open_File(); //読み込み
}

Wall_Function::~Wall_Function() {}

void Wall_Function::Draw_Wall(int call_ID, int set_x, int set_y) {
	//IDに合わせて画像を描画する
	for (std::vector<SETTING_WALL_DATA>::const_iterator setting_wall = wall_data.set_wall_data.cbegin();
		setting_wall != wall_data.set_wall_data.cend();
		++setting_wall, ++loop_count) {
		if (setting_wall->ID == call_ID) { //Define定数使用
			DrawExtendGraph(set_x,
							set_y,
							set_x + setting_wall->width,
							set_y + setting_wall->height,
							setting_wall->graphic_handle, TRUE);
		}
	}
}