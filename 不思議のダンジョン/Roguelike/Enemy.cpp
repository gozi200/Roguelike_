#include"Enemy.h"

Enemy::Enemy() {
	enemy_data.Set_File_Pass("CSV/Actor/Enemy/Enemy.csv"); //CSV�t�@�C���������ǂݍ���
	enemy_data.Open_File(); //�t�@�C�����J���ēǂݍ���

	loop_count = 0;
	is_hostility_flag = false;
}

Enemy::~Enemy() {

}

void Enemy::Set_Position(int set_x, int set_y) {

};

void Enemy::Get_Position(int* set_x, int* set_y, DIRECTION* direction) {

}

void Enemy::Render(int call_ID, int set_x, int set_y) {
	//ID�ɍ��킹�ĉ摜��`�悷��
	for (std::vector<SETTING_ENEMY_DATA>::const_iterator setting_enemy = enemy_data.set_enemy_data.cbegin();
		setting_enemy != enemy_data.set_enemy_data.cend();
		++setting_enemy, ++loop_count) {
		if (setting_enemy->ID == call_ID) { //Define�萔�g�p
			DrawExtendGraph(set_x,
				set_y,
				set_x + setting_enemy->width,
				set_y + setting_enemy->height,
				setting_enemy->graphic_handle, TRUE);
		}
	}
}