#pragma once

/*--------------------------
���̎�ނ̔��f�Ɏg�p����N���X
---------------------------*/

class Tile_Judge {
/*-------
�����o�ϐ�
--------*/
public:
	bool is_wall;		// �ǂ��ǂ���
	bool is_upstairs;	// ����K�i���ǂ���
	bool is_downstairs;	// ����K�i���ǂ���

/*--------
�����o�֐�
---------*/
public:
	// �R���X�g���N�^
	Tile_Judge() {};

	// �f�X�g���N�^
	~Tile_Judge() {};

};