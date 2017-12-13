#pragma once

#include"Item.h"
#include"Actor.h"
#include"Random.h"

/*------------------------------
�v���C���[�Ɏ����������ݒ肷��
------------------------------*/
struct ALLY_DATA : public ACTOR_DATA {
	int power;              // ��(�U���͂ɏ�悹�����)
	int max_power;          // �͂̍ő�l
	int noble_phantasm;     // ���������߂̃|�C���g
	int max_noble_phantasm; // np�̍ő�l

	//Item items[MAX_STOCK_ITEM]; //�A�C�e���̎����؂�鐔
	//Item weapon;				//����
	//Item shield;				//��
	//Item accessorie;			//�����i
};


/*-----------------------
Player��Partner�̐e�N���X
------------------------*/
class Ally : public Actor {
/*--------
�����o�ϐ�
--------*/
protected:
	int power;              // ��(�U���͂ɏ�悹�����)
	int max_power;          // �͂̍ő�l
	int noble_phantasm;     // ���������߂̃|�C���g
	int max_noble_phantasm; // np�̍ő�l

	//Item items[MAX_STOCK_ITEM]; //�A�C�e���̎����؂�鐔
	//Item weapon;				//����
	//Item shield;				//��
	//Item accessorie;			//�����i

private:	
	Random random;

/*--------
�����o�֐�
---------*/
	// �R���X�g���N�^
	Ally();

	// �f�X�g���N�^
	~Ally();

protected:
	// �͂̍ő�l�̎擾
	virtual int Get_Max_Power();

	// NP�̎擾
	virtual int Get_Max_NP();

	// NP�̑���
	virtual int Variation_NP(int vlue);

	// �͂̑���
	virtual int Variation_Power(int vlue);

	// �o���l�𓾂�
	virtual void Add_Experience_Point(int experience_point);

	// �o���l���烌�x�������߂�
	int Get_Level();
};