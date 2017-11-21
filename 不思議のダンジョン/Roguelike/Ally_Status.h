#pragma once

#include"Item.h"
#include"Weapon.h"
#include"Shield.h"
#include"Define.h"
#include"Vector2D.h"
#include"Item_Type.h"
#include"Accessorie.h"

/*----------------------------------
�������͂̃X�e�[�^�X���Ǘ�����N���X
-----------------------------------*/

class Ally_Status {
/*----------
�����o�ϐ�
-----------*/
public:
	int x; //���݈ʒu�̍��W(��)
	int y; //���݈ʒu�̍��W(�c)

/*---------
�����o�֐�
---------*/
public:
	//�R���X�g���N�^
	Ally_Status();

	//�f�X�g���N�^
	~Ally_Status();

	//�ʒu�̎擾
	void Set_Position(int x,int y);
	void Get_Position(int* px, int*py, DIRECTION* dir = NULL);

	////�p�����[�^�̃Z�b�g
	//void Set_Parameter(Enemy_Database* record, Item* drop_item);

	//HIt_Point�̑���(�v�Z�����l��Ԃ�)
	int Get_Hit_Point(int hit_point);

	//Magic_Point�̑���(�v�Z�����l��Ԃ�)
	int Get_Magic_Point(int magic_point);
	
	//�󕠃|�C���g��0~100%�ŕԂ�
	int Get_Hunger_Point();
	
	/*�H�����s��
	@param hunger_point �󕠃Q�[�W
	*/
	int Add_Hunger_Point(int hunger_point);
	
	/*�o���l���擾
	@param experience_point �o���l
	*/
	int Add_Experience_Point(int experience_point);

	//�U���͂̎擾
	int Get_Attack();

	//�h��͂̎擾
	int Get_Defence();

	//�s���͂̎擾
	int Get_Activity();
	
	//�^�[���̏I��
	void Turn();

	//�ő�Hit_Point�̎擾
	int Get_Max_Hit_Point(); //�ꉞ

	//�ő�Magic_Point�̎擾
	int Get_Max_Magic_Point(); //�ꉞ

	//TODO: �����A�C�e���Ǝg�p�A�C�e���ŕ�����H------------------------------
	
	/*�A�C�e���𑕔�
	@param item �����\�A�C�e��
 	*/
	void Set_Equipment(Item* equipment);

	//�A�C�e�����擾(��������Ȃ��Ƃ���false��Ԃ�)
	bool Get_Item(Item* item);

	//�w�肵���t�B���^���g���Ďw�肵���C���f�b�N�X�Ƃ̃A�C�e�����擾
	Item* Get_Item_Flom_Index(Item_Type* filter, int index);
	
	//------------------------------------------------------------------

	//���S����
	bool Is_Dead();
};
