#pragma once

/*/////////////////////////////////
�v���C���[�̃L�[������Ǘ�����N���X
////////////////////////////////*/

class Player_Key_Controller {
public:
	int x; //�ړ��� ��
	int y; //�ړ��� �c

	bool Player_Move_Up(); //����L�����N�^�[����֓�����
	bool Player_Move_Right(); //����L�����N�^�[���E�֓�����
	bool Player_Move_Down(); //����L�����N�^�[�����֓�����
	bool Player_Move_Left(); //����L�����N�^�[�����֓�����

	bool Attack(); //����L�����N�^�[���U��������

	bool Projectile_Weapon(); //��ѓ���̈� ��Ȃǂ̎g�p
};