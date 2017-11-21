#include"Player.h"

Player::Player() { 
	player_data.Set_File_Pass("CSV/Actor/Player/Player.csv"); //CSVファイルから情報を読み込む
	player_data.Open_File(); //ファイルを開いて読み込む

	loop_count = 0;
	is_hostility_flag = false;
}

Player::~Player() {

}

void Player::Set_Position(int set_x, int set_y) {

}

void Player::Get_Position(int *set_x, int* set_y, DIRECTION* set_direction) {

}

void Player::Render(int call_ID, int set_x, int set_y) {
	//IDに合わせて画像を描画する
	for (std::vector<SETTING_PLAYER_DATA>::const_iterator setting_player = player_data.set_player_data.cbegin();
		setting_player != player_data.set_player_data.cend();
		++setting_player, ++loop_count) {
		if (setting_player->ID == call_ID) { //Define定数使用
			DrawExtendGraph(set_x,
							set_y,
							set_x + setting_player->width,
							set_y + setting_player->height,
							setting_player->graphic_handle, TRUE);
		}
	}
}

