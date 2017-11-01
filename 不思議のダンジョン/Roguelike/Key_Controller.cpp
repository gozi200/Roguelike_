#include"DxLib.h"
#include"Key_Controller.h"

bool Key_Controller::Open_Menu() { //���j���[���J��
	if (CheckHitKey(KEY_INPUT_E)) {
		return true;
	}
	return false;
}

bool Key_Controller::Decide() { //�J�[�\���̂���Ƃ����I������
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		return true;
	}
	return false;
}

bool Key_Controller::Cursor_Move_Up() { //�J�[�\������֓�����
	if (CheckHitKey(KEY_INPUT_UP)) {
		return true;
	}
	return false;
}

bool Key_Controller::Cursor_Move_Right() { //�J�[�\�����E�֓�����
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		return true;
	}
	return false;
}

bool Key_Controller::Cursor_Move_Down() { //�J�[�\�������֓�����
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		return true;
	}
	return false;
}

bool Key_Controller::Cursor_Move_Left() { //�J�[�\�������֓�����
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		return true;
	}
	return false;
}