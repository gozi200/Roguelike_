#include"DxLib.h"
#include"Define.h"
#include"Default_Player_Status.h"
#include"Player.h"

Player::Player() { 
	is_hostility_flag = false;
}

Player::~Player(){

}

/* �X�|�[�������v���C���[��z�u
   @param set_x x���W
   @param set_y y���W
*/
void Player::Arrange(int set_x, int set_y) {
	player_data->x = set_x;
	player_data->y = set_y;

	is_exist = true;

	hit_point = DEFAULT_PLAYER_HIT_POINT; //Define�萔�g�p
}

void Player::Update() { //TODO: �Ȍ��ɂ��邽�߂ɏ�����ʂ̏ꏊ��
	if (player_key_controller->Player_Move_Up()) { //������ւ̈ړ� 
		player_data->y -= ACTOR_MOVEMENT;
	}

	if (player_key_controller->Player_Move_Right()) { //�E�����ւ̈ړ�
		player_data->x += ACTOR_MOVEMENT;
	}

	if (player_key_controller->Player_Move_Down()) { //�������ւ̈ړ�
		player_data->y += ACTOR_MOVEMENT;
	}

	if (player_key_controller->Player_Move_Left()) { //�������ւ̈ړ�
		player_data->x -= ACTOR_MOVEMENT;
	}
}

void Player::Set_Position(int set_x, int set_y) {

}

void Player::Get_Position(int *set_x, int* set_y, DIRECTION* set_direction) {

}


//////////////////////////////////////////�w�b�_�[�Q��
void Player::Render_Hit_Point() {}

void Player::Render_Stmach() {}

void Player::Render_Experiece_Point() {}