#include"Player.h"

Player::Player() { 
	player_data.Set_File_Pass("CSV/Actor/Player/Player.csv"); //CSV�t�@�C���������ǂݍ���
	player_data.Open_File(); //�t�@�C�����J���ēǂݍ���

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
	//ID�ɍ��킹�ĉ摜��`�悷��
	for (std::vector<SETTING_PLAYER_DATA>::const_iterator setting_player = player_data.set_player_data.cbegin();
		setting_player != player_data.set_player_data.cend();
		++setting_player, ++loop_count) {
		if (setting_player->ID == call_ID) { //Define�萔�g�p
			DrawExtendGraph(set_x,
							set_y,
							set_x + setting_player->width,
							set_y + setting_player->height,
							setting_player->graphic_handle, TRUE);
		}
	}
}

