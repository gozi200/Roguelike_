#include"DxLib.h"
#include"Define.h"
#include"Default_Player_Status.h"
#include"Player.h"

Player::Player() { 
	is_hostility_flag = false;
}

Player::~Player(){

}

/* スポーンしたプレイヤーを配置
   @param set_x x座標
   @param set_y y座標
*/
void Player::Arrange(int set_x, int set_y) {
	player_data->x = set_x;
	player_data->y = set_y;

	is_exist = true;

	hit_point = DEFAULT_PLAYER_HIT_POINT; //Define定数使用
}

void Player::Update() { //TODO: 簡潔にするために処理を別の場所へ
	if (player_key_controller->Player_Move_Up()) { //上方向への移動 
		player_data->y -= ACTOR_MOVEMENT;
	}

	if (player_key_controller->Player_Move_Right()) { //右方向への移動
		player_data->x += ACTOR_MOVEMENT;
	}

	if (player_key_controller->Player_Move_Down()) { //下方向への移動
		player_data->y += ACTOR_MOVEMENT;
	}

	if (player_key_controller->Player_Move_Left()) { //左方向への移動
		player_data->x -= ACTOR_MOVEMENT;
	}
}

void Player::Set_Position(int set_x, int set_y) {

}

void Player::Get_Position(int *set_x, int* set_y, DIRECTION* set_direction) {

}


//////////////////////////////////////////ヘッダー参照
void Player::Render_Hit_Point() {}

void Player::Render_Stmach() {}

void Player::Render_Experiece_Point() {}