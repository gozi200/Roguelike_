#pragma once

#include"Item.h"
#include"Enemy.h"
#include"Player.h"
#include"Define.h"
#include"Vector2D.h"
#include"Tile_Judge.h"
#include"Enemy_Database.h"

/*///////////////////////////
�_���W�����쐬�̌��ƂȂ�N���X
///////////////////////////*/

class Dungeon_Base {
/*////////
�����o�ϐ�
*/////////
public:
	DUNEON_RECTANGLE dungeon_rectangle[MAX_RECTANGLE]; //rectangle�͋�`�̈Ӗ� �����ł͋����̂���

	int rectangle_count; //��搔

	int width; //�_���W�����̕� �����H
	
	int height; //�_���W�����̍����@�����H

	Tile_Judge* tile_judge;// = new Tile_Judge; //�^�C�������Ȃ̂����Ȃ̂��𔻒f

	Player *player; //�v���C���[

	Enemy *m_enemy[MAX_ENEMY]; //�G�l�~�[�ւ̃|�C���^ �|�C���^�Ƃ̏d���������

	int enemy_count; //�o�^����Ă���G�l�~�[�̐�

	int up_stairs_x;

	int up_stairs_y;

	int down_stairs_x;

	int down_stairs_y;

/*////////
�����o�֐�
*/////////
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

	//�w��ꏊ���ړ��\�����f(true�Ȃ�ړ��\)
	bool is_Move(int x, int y);

	//�w���`��ǉ����ɂ���(right,bottom�̃}�X�͓h��Ȃ�)
	void Fill_Rectangle(int left, int top, int right, int bottom, bool is_wall);

	//�w��̉��}�X��ǉ����ɂ���
	void Fill_H_Line(int left, int right, int y, bool is_wall); //TODO: H���ĂȂɁH

	//�w��̏c�}�X��ǉ����ɂ���
	void Fill_V_Line(int top, int bottom, int x, bool is_wall); //����

	//�w�肵���������̓K���ȍ��W���擾
	void Random_Room_Point(int index, int *px, int *py);

	//�w�肵�����WA����A���WB�͈ړ��ł�����͂̂W�}�X�ł����true��Ԃ�
	bool Chekc_Move(int ax, int ay, int bx, int by);

	//�G�l�~�[�𕔉��ɔz�u
	void Enemy_Array(int floor);

	//�G�l�~�[��S�č폜����
	void Delete_Enemy();

	//�G�l�~�[�̐����擾(����ł�����̂��܂�)
	int Get_Enemy_Count();

	//�w����W�ɃG�l�~�[�����邩
	Enemy* Get_Point_Enemy(int x, int y);

	//�w��C���f�b�N�X�̃G�l�~�[���𓾂�
	Enemy* Get_Mob_From_Index(int index);

	//�w����W�ɃA�C�e���𗎂Ƃ�
	void Drop_Item(int x, int y, Item* item);

	//�w����W�ɗ����Ă���A�C�e�����폜
	void Remove_Item(int x, int y, Item * item);

	//�w��ʒu�̕����C���f�b�N�X��Ԃ�(���܂��͕ǂȂ�-1��Ԃ�)
	int Get_Room_Index(int x, int y);

	//�U������
	int Attack(Player* player, Player* target);

	//ID����G�l�~�[�N���X���쐬
	bool Make_Enemy(int ai, Enemy** enemy);

	//�G�l�~�[�̃x�[�X�e�[�u������p�����[�^���Z�b�g
	void Set_Enemy_Parameter(Enemy* enemy, Enemy_Database* enemy_data);

private:
	//�K�w�ɂ������G�l�~�[�𐶐��擾
	Enemy* Get_Enemy(int floor);
};