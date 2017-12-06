#pragma once

#include"Actor.h"

class Dungeon_Base; //�C���N���[�h�̏Փ˂������

class Enemy : public Actor {
/*---------
�����o�ϐ�
---------*/

/*---------
�����o�֐�	
----------*/
public:
	Enemy();

	virtual ~Enemy();

	//�s������
	virtual void Move(Dungeon_Base* dungeon_base) = 0;

	//�V�������W�ւ̈ړ����s��
	//��Ƀv���C���[��������U�����s���A�ǂ�A�ق��̃G�l�~�[�������牽�����Ȃ�
	bool Move_Action(Dungeon_Base* dungeon_base, int mx, int my);

	/*�G�l�~�[�̉摜��`�悷��
	@param call_ID ID�ɍ������摜���Ă�
	@param x �`�悷��ꏊ��x��
	@param y �`�悷��ꏊ��y��
	*/
	void Render(int call_ID, int x, int y);

	int Reset();

	int Turn(Dungeon_Base* dungeon_base, int count);
};