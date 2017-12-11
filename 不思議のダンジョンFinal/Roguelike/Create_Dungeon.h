#pragma once

#include"Define.h"
#include"Tile_Judge.h"
#include"Dungeon_Manager.h"

#include<memory>

/*---------------------------------------------------
�_���W�����}�b�v�𐶐�����N���X : Dungeon_Manager���p��
----------------------------------------------------*/

class Create_Dungeon : public Dungeon_Manager {
/*--------
�����o�ϐ�
--------*/
public:
	Dungeon_Manager* dungeon_manager;


	int x, // ���W(��)
		y; // ���W(�c)

	int a, b, ab, p;

	int upstairs_x;	  // ����K�i�̍��W(��)
	int upstairs_y;	  // ����K�i�̍��W(�c)
	int downstairs_x; // ����K�i�̍��W(��)
	int downstairs_y; // ����K�i�̍��W(�c)

/*-------
�����o�֐�
--------*/
public:
	//�R���X�g���N�^ 
	Create_Dungeon();
	
	// �f�X�g���N�^
	~Create_Dungeon();

	/*�������
	  @param left   ����
	  @param top    ���
	  @param right  �E��
	  @param bottom ����
	*/
	DUNEON_RECTANGLE* Create_Rectangle(int left, int top, int right, int bottom);

	/* �����ו�������
	   @param 
	*/
	void Split_Rectangle(bool is_vertical);
	
	// ���������
	void Create_Room();

	// �������q����
	void Connect_Room();

	/* �������
	   @param room_A �q����铹�̕Њ���
	   @param room_B �q����铹�̕Њ���
	*/
	void Create_Road(int room_A, int room_B);

	// �����͈̔�+�����̘A�����̂ݕǃt���O��false��
	void Fill_Rectangle(int left, int top, int right, int bottom, bool is_wall);

	// �����ƕ����̏c�����q��
	void Fill_Horizontal_Line(int left, int right, int y, bool is_wall);

	// �����ƕ����̉������q��
	void Fill_Vertical_Line(int top, int bottom, int x, bool is_wall);

	//�P�t���A���̃_���W�����𐶐�����B�_���W�����ֈڍs�A�K�w�ړ����ƂɌĂяo��
	void Create_Floor();

	// �P�t���A���̃_���W�����̍\����ݒ肷��(���̐��A�����̐��Ȃ�)
	void Set_Dungeon();
};