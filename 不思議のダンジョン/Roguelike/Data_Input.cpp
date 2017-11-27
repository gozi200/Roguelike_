#include "Data_Input.h"


Data_Input::Data_Input() {
	enemy_data.Set_File_Pass("CSV/Actor/Enemy/Enemy.csv"); //CSVファイルから情報を読み込む
	enemy_data.Open_File(); //ファイルを開いて読み込む
}


Data_Input::~Data_Input()
{
}

void Data_Input::Enemy_Data() {
	for (std::vector<SETTING_ENEMY_DATA>::const_iterator setting_enemy = enemy_data.set_enemy_data.cbegin();
		setting_enemy != enemy_data.set_enemy_data.cend();
		++setting_enemy, ++loop_count);

}

int Data_Input::getExp(int id) {
	for (std::vector<SETTING_ENEMY_DATA>::const_iterator &setting_enemy = enemy_data.set_enemy_data.cbegin();
		setting_enemy != enemy_data.set_enemy_data.cend();
		++setting_enemy) {
		if (setting_enemy->ID == id) {
			return setting_enemy->experience_point;
		}
	}
}