#pragma once

#include"Item.h"
#include"Actor.h"
#include"Enemy.h"
#include"Define.h"
#include"Random.h"
#include"Vector2D.h"
#include"Enemy_01.h"
#include"Tile_Judge.h"
#include"Enemy_Data.h"
#include"Actor_Status.h"

static Item ITEM_DATA_BASE[] {
	{ITEM_TYPE_USEITEM,    "�O�Ȏ�p�Z�b�g"   ,"��"     ,{HP_CURE, 50}},
	{ITEM_TYPE_USEITEM,    "���҂̑��蕨"     ,"��"     ,{HP_CURE, 100}},
	{ITEM_TYPE_USEITEM,    "����̉ʎ�"       ,"�H�ו�"   ,{HUNGER_CURE, 50}},
	{ITEM_TYPE_WEAPON,     "�G�N�X�J���o�["   ,"����"     ,{50}},
	{ITEM_TYPE_SHIELD,     "�M�����n�b�h�̏�" ,"��"       ,{50}},
	{ITEM_TYPE_ACCESSORIE, "���t"            ,"�T�O�瑕" ,{0,10}},
};

static SETTING_ENEMY_DATA;

/*----------------------------
�_���W�����쐬�̌��ƂȂ�N���X
----------------------------*/

class Dungeon_Base {
/*---------
�����o�ϐ�
---------*/
public:
	Actor* player; //�v���C���[

	Random random;

	Enemy_Data enemy_data;

	Tile_Judge* tile_judge; //�^�C�������Ȃ̂����Ȃ̂��𔻒f

	Enemy* m_enemy[MAX_ENEMY]; //�G�l�~�[�ւ̃|�C���^ �|�C���^�Ƃ̏d���������
	
	DUNEON_RECTANGLE dungeon_rectangle[MAX_RECTANGLE]; //rectangle�͋�`�̈Ӗ� �����ł͋����̂���

	int width; //�_���W�����̕� 
	
	int height; //�_���W�����̍���

	int rectangle_count; //��搔
	
	int enemy_count; //�o�^����Ă���G�l�~�[�̐�

	int turn_count; //�o�߃^�[���𐔂���

	int up_stairs_x; //����K�i�̂�����W(��)

	int up_stairs_y; //����K�i�̂�����W(�c)

	int down_stairs_x; //����K�i�̂�����W(��)

	int down_stairs_y; //����K�i�̂�����W(�c)

/*--------
�����o�֐�
---------*/
public:
	//�R���X�g���N�^
	Dungeon_Base();

	//�f�X�g���N�^
	virtual ~Dungeon_Base();

	//�_���W�����̃������̊m��
	bool Alloc(int width, int height); //MEMO: alloc�͗v�f�̐������܂��ĂȂ��l�Ɏg�p�������

	//�^�C�������擾
	Tile_Judge* Get_Tile(int x, int y); 

	//���̐����擾
	int Get_Rectangle_Count();

	//�����̐����擾
	int Get_Room_Count();

	//�����̐����擾
	int Get_Romm_Count();

	//�w��ꏊ���ړ��\�����f(true�Ȃ�ړ��\)
	bool Is_Move(int x, int y);

	//�w���`��ǂ����ɂ���(right,bottom�̃}�X�͓h��Ȃ�)
	void Fill_Rectangle(int left, int top, int right, int bottom, bool is_wall);

	//�w��̉��}�X��ǂ����ɂ���
	void Fill_Horizontal_Line(int left, int right, int y, bool is_wall); //H���ĂȂɁH

	//�w��̏c�}�X��ǂ����ɂ���
	void Fill_Vertical_Line(int top, int bottom, int x, bool is_wall); //����

	//�w�肵���������̓K���ȍ��W���擾
	void Random_Room_Point(int index, int *px, int *py);

	//�w�肵�����WA����A���WB�͈ړ��ł�����͂̂W�}�X�ł����true��Ԃ�
	bool Check_Move(int ax, int ay, int bx, int by);

	//�G�l�~�[�𕔉��ɔz�u
	void Create_Enemy(int floor);

	//�G�l�~�[��S�č폜����
	void Delete_Enemy();

	//�G�l�~�[�̐����擾(����ł�����̂��܂�)
	int Get_Enemy_Count();

	//�w����W�ɃG�l�~�[�����邩
	Actor* Get_Point_Enemy(int x, int y);

	//�w��C���f�b�N�X�̃G�l�~�[���𓾂�
	Actor* Get_Mob_From_Index(int index);

	//�w����W�ɃA�C�e���𗎂Ƃ�
	void Drop_Item(int x, int y, Item* item);

	//�w����W�ɗ����Ă���A�C�e�����폜
	void Remove_Item(int x, int y, Item * item);

	//�U������
	int Attack(Actor* player, Actor* target);

	//ID����G�l�~�[�N���X���쐬
	bool Make_Enemy(int ai, Enemy** enemy);

	//�����_���ɃG�l�~�[��z�u
	void Random_Create_Enemy(int floor);

	//�G�l�~�[�̃f�[�^�x�[�X����p�����[�^���Z�b�g
	void Set_Enemy_Parameter(Enemy* enemy, SETTING_ENEMY_DATA* enemy_data);

	//�w��ʒu�̕����C���f�b�N�X��Ԃ�(���A�ǂȂ�-1��Ԃ�)
	int Get_Room_Index(int x, int y);

	//�w��ʒu�̋�`�C���f�b�N�X��Ԃ�(���A�ǂȂ�-1��Ԃ�)
	int Get_Rectangle_Index(int x, int y);

private:
	//�K�w�ɂ������G�l�~�[�𐶐��擾
	Enemy* Get_Enemy(int floor);
};