#pragma once

#include"Item.h"
#include"Shield.h"
#include"Define.h"
#include"Weapon.h"
#include"Vector2D.h"
#include"Item_Type.h"
#include"Enemy_Data.h"
#include"Accessorie.h"

/*----------------------------------
�L�����N�^�[�̃X�e�[�^�X���Ǘ�����N���X
-----------------------------------*/

class Actor_Status {
/*----------
�����o�ϐ�
-----------*/
public:
	int ID;						//�i���o�[
	std::string name;			//���O
	int x;						//���̍��W
	int y;						//�c�̍��W

	int level;					//���x��
	int power;					//������ (�f�̍U���́B�����ɕ���̍U���́A���x���ŕϓ�����U���͂��v�Z)
	int attack;					//�U����
	int defence;				//�h���
	int agility;				//�q����(�����ł͉��)
	int hit_point;				//�q�b�g�|�C���g(0�Ŏ��S)
	int activity;				//�s����(�����ł͂P�^�[���ɍs���ł��鐔)
	int turn_count;				//�o�߃^�[�����J�E���g
	int experience_point;		//�o���l(�����ł͓|���ꂽ�Ƃ��ɑ���ɗ^����l)
	int graphic_handle;			//�摜�̃n���h��
	int paturn;					//�s���p�^�[��
	int evolution;				//�i���`��
	int drop_item;				//���S���Ɋm���ŗ��Ƃ��A�C�e��
	int first_floor;			//�o���J�n�K�w
	int last_floor;				//�o���I���K�w
	int drop_item_ID;			//�h���b�v����A�C�e����ID

	int width;					//�\������镝
	int height;					//�\������鍂��
/*---------
�����o�֐�
---------*/
public:
	//�R���X�g���N�^
	Actor_Status();

	//�f�X�g���N�^
	~Actor_Status();

	//�ʒu�̎擾
	void Set_Position(int x,int y);
	void Get_Position(int* px, int*py, DIRECTION* dir = NULL);

	//�p�����[�^�̃Z�b�g
	void Set_Parameter(SETTING_ENEMY_DATA* record, Item* drop_item);

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

	/*�A�C�e���𑕔�
	@param item �����\�A�C�e��
 	*/
	void Set_Equipment(Item* equipment);

	//�A�C�e�����擾(��������Ȃ��Ƃ���false��Ԃ�)
	bool Get_Item(Item* item);

	//�w�肵���t�B���^���g���Ďw�肵���C���f�b�N�X�Ƃ̃A�C�e�����擾
	Item* Get_Item_Flom_Index(Item_Type* filter, int index);
	
	//���S����
	bool Is_Dead();
};
