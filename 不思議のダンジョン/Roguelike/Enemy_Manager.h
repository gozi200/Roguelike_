#pragma once

#include"Enemy.h"
#include"Dungeon_Base.h"

class Enemy_Manager : public Enemy {
/*////////
�����o�ϐ�
*/////////

/*////////
�����o�֐�	
*/////////
public:
	Enemy_Manager(){}

	virtual ~Enemy_Manager(){}

	//�s������
	virtual void Move(Dungeon_Base* dungeon_base) = 0;

	//�V�������W�ւ̈ړ����s��
	//��Ƀv���C���[��������U�����s���A�ǂ�A�ق��̃G�l�~�[�������牽�����Ȃ�
	bool Is_Move_Action(Dungeon_Base* dungeon_base, int mx, int my);

};