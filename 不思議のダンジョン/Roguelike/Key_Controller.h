#pragma once

/*//////////////////////////
�L�[������Ǘ�����N���X
/////////////////////////*/

class Key_Controller {
public:
	int x; //�ړ��� ��
	int y; //�ړ��� �c

	bool Cursor_Move_Up(); //�J�[�\������֓�����
	bool Cursor_Move_Right(); //�J�[�\�����E�֓�����
	bool Cursor_Move_Down(); //�J�[�\�������֓�����
	bool Cursor_Move_Left(); //�J�[�\�������֓�����

	bool Open_Menu(); //���j���[���J��

	bool Decide(); //�J�[�\���̂���Ƃ����I������
};