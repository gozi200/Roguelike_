#pragma once

#include"Item.h"
#include"Actor.h"

/*----------------------------
�G�l�~�[�Ɏ�������������肷��
----------------------------*/
struct ENEMY_DATA : public ACTOR_DATA {
	int evolition;   // �i���i�K
	int AI_paturn;   // �s���p�^�[��
	int first_floor; // �o���J�n�K�w
	int last_floor;  // �o���I���K�w
	int item_drop;   // ���S���ɃA�C�e���𗎂Ƃ��m��

	Item drop_item;  // ���S���Ɋm���ŗ��Ƃ��A�C�e��
};

/*-------------------------------
�G�l�~�[�̊��N���X(��ނŕ�����H)
--------------------------------*/

class Enemy : public Actor {
/*--------
�����o�ϐ�
--------*/
public:

/*--------
�����o�֐�
---------*/
public:
	// �R���X�g���N�^
	Enemy();

	// �f�X�g���N�^
	~Enemy();

	// ���W�̃Z�b�g
	void Set_Position(int x, int y) override;

	// ���W�̎擾
	void Get_Position(int* x, int* y, eDIRECTION* direction = NULL) override;

	// hit_point�̑���
	int Variation_HP(int value) override;

	// �^�[���̏I��
	void Turn_End() override;

	// �ő��HP�̎擾
	int Get_Max_HP() override;

	// �U���͂̎擾
	int Get_Attack() override;

	// �h��͂̎擾
	int Get_Defence() override;

	// ��𗦂��擾
	int Get_Agility() override;

	// ���S����
	bool Is_Dead() override;

};