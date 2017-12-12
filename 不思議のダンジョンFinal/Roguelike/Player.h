#pragma once

#include"Item.h"
#include"Actor.h"
#include"Split.h"
#include"Random.h"
#include"Define.h"
#include"Player_Graphic.h"

#include<vector>
#include<string>
#include<fstream>
#include<memory>

/*------------------------------
�v���C���[�Ɏ����������ݒ肷��
------------------------------*/
struct PLAYER_DATA : public ACTOR_DATA {
	int skill;              // �X�L��
	int power;              // ��(�U���͂ɏ�悹�����)
	int max_power;          // �͂̍ő�l
	int treasure_tool;      // ���
	int hunger_point;       // �󕠃|�C���g
	int noble_phantasm;     // ���������߂̃|�C���g
	int max_noble_phantasm; // np�̍ő�l

	//Item items[MAX_STOCK_ITEM]; //�A�C�e���̎����؂�鐔
	//Item weapon;				//����
	//Item shield;				//��
	//Item accessorie;			//�����i
};

/*--------------------------------------
�v���C���[���Ǘ�����N���X
---------------------------------------*/

class Player : public Actor {
/*--------
�����o�ϐ�
--------*/
public:
	Random random;
	std::shared_ptr<Player_Graphic> player_graphic;
	std::vector<PLAYER_DATA> player_data; // �L�������Ɋi�[
	
	int hunger_point;       // �󕠃|�C���g
	int noble_phantasm;     // ���������߂̃|�C���g

private:
	int max_noble_phantasm; // np�̍ő�l

/*--------
�����o�֐�
---------*/
public:
	// �R���X�g���N�^
	Player();

	// �f�X�g���N�^
	~Player();

	// ���W�̃Z�b�g
	void Set_Position(int x, int y) override;

	// ���W�̎擾
	void Get_Position(int* x, int* y, eDIRECTION* direction = NULL) override;

	// �p�����[�^���Z�b�g
	void Set_Parametor() override;

	// HP�̑���
	int Variation_HP(int value) override;

	// �^�[���̏I��
	void Turn_End() override;

	// �ő��HP�̎擾
	int Get_Max_HP() override;

	// �U���͂̎擾
	int Get_Attack() override;

	// �͂̎擾
	int Get_Power();

	// �h��͂̎擾
	int Get_Defence() override;

	// ��𗦂��擾
	int Get_Agility() override;

	// ���S����
	bool Is_Dead() override;

	// NP�̎擾
	int Get_Max_NP();

	// NP�̑���
	int Variation_NP(int vlue);

	// �o���l�𓾂�
	void Add_Experience_Point(int experience_point);

	// ���Ȃ��Q�[�W�̑���
	void Variation_Hunger_Point(int value);

	// �A�C�e���̑���
	void Set_Equipment(Item* item);

	// �A�C�e���̎擾�B�J�o���������ς��Ȃ� true ��Ԃ�
	bool Get_Item(Item* item);

	// �w�肵���t�B���^�Ŏw�肵���C���f�b�N�X�̃A�C�e�����擾
	Item* Get_Item_From_Index(eITEM_TYPE filter, int index);

	// �󕠗��� 0~100% �ŕԂ�
	int Get_Hunger_Percent();

	// �o���l���烌�x�������߂�
	int Get_Level();
};