#pragma once

#include"Item.h"
#include"Actor.h"
#include"Random.h"


/*-----------------------------------------
�v���C���[�ƃp�[�g�i�[�Ɏ����������ݒ肷��
------------------------------------------*/
struct ALLY_DATA : public ACTOR_DATA {
	int power;                // ��(�U���͂ɏ�悹�����)
	int max_power;            // �͂̍ő�l
	int command_card;         // �R�}���h�J�[�h
	int arts_card;            // �A�[�c�J�[�h�̖���
	int arts_attack_count;    // �A�[�c�J�[�h�I�����̍U����
	int quick_card;           // �N�C�b�N�J�[�h�̖���
	int quick_attack_count;   // �A�[�c�J�[�h�I�����̍U����
	int buster_card;          // �o�X�^�[�J�[�h�̖���
	int buster_attack_count;  // �A�[�c�J�[�h�I�����̍U����
	int extra_attack;         // �G�N�X�g���A�^�b�N
	int star_generater;       // �X�^�[������
	int noble_weapom;         // ��� 
	int noble_phantasm;       // ���������߂̃|�C���g
	int max_noble_phantasm;   // np�̍ő�l
	int attack_rise_NP;       // �U������NP�㏸��
	int defence_rise_NP;      // �h��(��_��)����NP�̏㏸��

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
	Random random;

	int power;               // ��(�U���͂ɏ�悹�����)
	int max_power;           // �͂̍ő�l
	int star_occur;          // �X�^�[������
	int command_card;        // �R�}���h�J�[�h
	int atrs_card;           // �A�[�c�J�[�h�̖���
	int arts_attack_count;   // �A�[�c�J�[�h�I�����̍U����
	int quick_card;          // �N�C�b�N�J�[�h�̖���
	int quick_attack_count;  // �N�C�b�N�J�[�h�I�����̍U����
	int buster_card;         // �o�X�^�[�J�[�h�̖���
	int buster_attack_count; // �o�X�^�[�J�[�h�I�����̍U����
	int extra_attack;        // �G�N�X�g���A�^�b�N
	int attack_rise_NP;      // �U������NP�㏸��
	int defence_rise_NP;     // �h��(��_��)����NP�̏㏸��
	int noble_weapon;        // ���
	int noble_phantasm;      // ���������߂̃|�C���g
	int max_noble_phantasm;  // np�̍ő�l

	//Item items[MAX_STOCK_ITEM]; //�A�C�e���̎����؂�鐔
	//Item weapon;				//����
	//Item shield;				//��
	//Item accessorie;			//�����i

/*--------
�����o�֐�
---------*/
public:
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

	// ���݂̌o���l�ʂ��擾
	virtual int Get_Experience_Point(int set_EXP);

	// �o���l���烌�x�������߂�
	int Get_EXP_Level();

	// ���x���𓾂�
	int Get_Level(int set_level);
};