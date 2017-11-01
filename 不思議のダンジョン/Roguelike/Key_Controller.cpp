#include"DxLib.h"
#include"Key_Controller.h"

bool Key_Controller::Open_Menu() { //メニューを開く
	if (CheckHitKey(KEY_INPUT_E)) {
		return true;
	}
	return false;
}

bool Key_Controller::Decide() { //カーソルのあるところを選択する
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		return true;
	}
	return false;
}

bool Key_Controller::Cursor_Move_Up() { //カーソルを上へ動かす
	if (CheckHitKey(KEY_INPUT_UP)) {
		return true;
	}
	return false;
}

bool Key_Controller::Cursor_Move_Right() { //カーソルを右へ動かす
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		return true;
	}
	return false;
}

bool Key_Controller::Cursor_Move_Down() { //カーソルを下へ動かす
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		return true;
	}
	return false;
}

bool Key_Controller::Cursor_Move_Left() { //カーソルを左へ動かす
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		return true;
	}
	return false;
}