#pragma once

#include"Define.h"
#include"Random.h"
#include"Actor_Status.h"

class Actor {
/*-------
�����o�ϐ�
--------*/
public:
	Random random;

	Actor_Status actor_status;

	char* name; //�L�����N�^�[�̖��O

	bool is_dead_frag; //�����t���O

	int next_count; //�^�[���̃J�E���g�Ɏg�p


/*--------
�����o�֐�
---------*/
public:
	//�R���X�g���N�^
	Actor();
	
	//�f�X�g���N�^
	virtual ~Actor();

	//���O�̐ݒ�
	void Set_Name(char* name);
	char* Get_Name();

	//�ʒu�̐ݒ�A�擾
	void Set_Position(int x, int y);
	void Get_Position(int* x, int* y, DIRECTION* dir = NULL);

	//�����m�F
	bool Is_Dead();

	//�ێ��^�[���������Z�b�g
	int reset();

	//�U��
	int Attack(Actor* target);
};