#include"DxLib.h"
#include"Player_Key_Contloroller.h"

/*///////////////////
�L�����N�^�[�̑���
///////////////////*/

bool Player_Key_Controller::Player_Move_Up() { //�L�����N�^�[��������Ɉړ�
	if (CheckHitKey(KEY_INPUT_W)) {
		return true;
	}
	return false;
}

bool Player_Key_Controller::Player_Move_Right() { //�L�����N�^�[���E�����Ɉړ�
	if (CheckHitKey(KEY_INPUT_D)) {
		return true;
	}
	return false;
}

bool Player_Key_Controller::Player_Move_Down() { //�L�����N�^�[���������Ɉړ�
	if (CheckHitKey(KEY_INPUT_S)) {
		return true;
	}
	return false;
}

bool Player_Key_Controller::Player_Move_Left() { //�L�����N�^�[���������Ɉړ�
	if (CheckHitKey(KEY_INPUT_A)) {
		return true;
	}
	return false;
}

bool Player_Key_Controller::Attack() { //�L�����N�^�[�̍U��
	if (CheckHitKey(KEY_INPUT_RETURN)) { //ENTER�L�[
		return true;
	}
	return false;
}

bool Player_Key_Controller::ProjecTile_Weapon() { //��ѓ���̎g�p
	if (CheckHitKey(KEY_INPUT_LBRACKET)) { //'['�L�[
		return true;
	}
	return false;
}