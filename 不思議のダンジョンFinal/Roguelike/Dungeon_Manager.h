#pragma once

#include"random.h"
#include"Define.h"
#include"Tile_Judge.h"

/*-----------------------------
�_���W���������̂̌��ƂȂ�N���X
------------------------------*/

class Dungeon_Manager {
/*---------
�����o�ϐ�
---------*/
public:
	Random* random;         // ���������Ɏg�p 
	Tile_Judge* tile_judge; //���̍��W�̒n�ʂ͉��Ȃ̂��𔻒f
	DUNEON_RECTANGLE dungeon_rectangle[MAX_RECTANGLE]; //��`
	 
	int width;           // �_���W�����̕�
	int height;          // �_���W�����̍���

	int turn_count;      // �o�߃^�[���𐔂���
	
	int rectangle_count; // �P�t���A�̋��̐�

/*---------
�����o�֐�
----------*/
public:
	// �R���X�g���N�^
	Dungeon_Manager();

	// �f�X�g���N�^
	virtual ~Dungeon_Manager();

	// �_���W�����̃������̊m��
	bool Alloc(int set_width, int set_height);

	// �^�C���̏����擾
	Tile_Judge* Get_Tile(int x, int y);

	// �w�肵���������̓K���ȍ��W���擾
	void Random_Room_Point(int index, int* px, int* py);

private:
	// ���̐����擾
	int Get_Rectangle_Count();

	// �����̐����擾
	int Get_Room_Count();

	//�w��ʒu�̕����C���f�b�N�X��Ԃ�(���A�ǂȂ�-1��Ԃ�)
	int Get_Room_Index(int x, int y);

	//�w��ʒu�̋�`�C���f�b�N�X��Ԃ�(���A�ǂȂ�-1��Ԃ�)
	int Get_Rectangle_Index(int x, int y);
};