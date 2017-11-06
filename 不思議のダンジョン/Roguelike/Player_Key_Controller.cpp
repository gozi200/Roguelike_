#include"DxLib.h"
#include"Player_Key_Contloroller.h"

/*///////////////////
キャラクターの操作
///////////////////*/

bool Player_Key_Controller::Player_Move_Up() { //キャラクターを上方向に移動
	if (CheckHitKey(KEY_INPUT_W)) {
		return true;
	}
	return false;
}

bool Player_Key_Controller::Player_Move_Right() { //キャラクターを右方向に移動
	if (CheckHitKey(KEY_INPUT_D)) {
		return true;
	}
	return false;
}

bool Player_Key_Controller::Player_Move_Down() { //キャラクターを下方向に移動
	if (CheckHitKey(KEY_INPUT_S)) {
		return true;
	}
	return false;
}

bool Player_Key_Controller::Player_Move_Left() { //キャラクターを左方向に移動
	if (CheckHitKey(KEY_INPUT_A)) {
		return true;
	}
	return false;
}

bool Player_Key_Controller::Attack() { //キャラクターの攻撃
	if (CheckHitKey(KEY_INPUT_RETURN)) { //ENTERキー
		return true;
	}
	return false;
}

bool Player_Key_Controller::ProjecTile_Weapon() { //飛び道具の使用
	if (CheckHitKey(KEY_INPUT_LBRACKET)) { //'['キー
		return true;
	}
	return false;
}