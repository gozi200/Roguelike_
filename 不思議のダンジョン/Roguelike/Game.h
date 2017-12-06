#pragma once

#include"Define.h"
#include"Actor.h"
#include"Enemy.h"
#include"Dungeon01.h"
#include"Dungeon_Base.h"
#include"Actor_Status.h"

#include<string>

class Game {
	enum ACTION {
		ACTION_MOVE,      //�ړ�����
		ACTION_GET_ITEM,  //�A�C�e�����E��
		ACTION_EQUIPMENT, //�����A�C�e���𑕔�����
		ACTION_DORP_ITEM, //�A�C�e���𗎂Ƃ�
		ACTION_USE_ITEM,  //�A�C�e�����g��
		ACTION_STEP,      //�K�i�ړ��m�F
		ACTION_MAX,       //Game�N���X�Ő錾�����Ă���ACTION�̍ő�l
	};

/*--------
�����o�ϐ�
---------*/
public:
	Dungeon_Base* dungeon_base;
	Dungeon01* dungeon01;
	Actor player;
	Enemy* enemy_;
	Actor_Status actor_status;

	int floor; //���݂̊K�w

private:
	ACTION action; //���݂̃��C������

	int action_count; //���C�������ėp�ϐ�

	Item* use_item; //�g�p�A�C�e��(�������̃A�C�e���ւ̃|�C���^)

/*---------
�����o�֐�
----------*/
public:
	//�R���X�g���N�^
	Game();

	//�f�X�g���N�^
	virtual ~Game();

	//�Q�[���̏�����
	void Init();

	//�Q�[���̃��C�����[�v���s(�T�C�N�����s)
	bool Cycle();

	//�t���A�̍쐬
	void Create_Floor();

	//�A�C�e���̎擾
	void Action_Get_Item();

	//�A�C�e�����̂Ă�
	void Action_Drop_Item();

	//�A�C�e�����g��
	void Action_Use_Item();

	//�A�C�e���̑���
	void Action_Equip();


	//��ʂ̕`��
	virtual void Render() = 0;

private:
	//�����A�C�e����I��\��
	int Message_Items(eITEM_TYPE filter = ITEM_TYPE_NONE); //�߂�l�̓A�C�e���̐�

	//�����̐؂�ւ�
	void Set_Action(ACTION action);

	//�����̎��s
	void Run_Action();

	//�ړ�����
	bool Action_Step();

	bool Use_Item_HP_Cure(Item* item);

	bool Use_Item_Food(Item* item);

	bool Move_Check_Enemy(int x, int y);

	bool Move_Check_Command();

	void Enemy_Move();
};