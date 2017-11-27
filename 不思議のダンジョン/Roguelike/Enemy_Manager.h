#pragma once

#include"Actor.h"
#include"DxLib.h"
#include"Define.h"
#include"Vector2D.h"
#include"Data_Input.h"

/*----------------
Actor�N���X���p��

�G���Ǘ�����N���X
-----------------*/

class Enemy_Manager : Actor{
/*--------
�����o�ϐ�
---------*/
public:
Data_Input data_input;

int loop_count;

/*--------
�����o�֐�
--------*/
public:
	//�G�l�~�[�̃R���X�g���N�^
	Enemy_Manager();

	//�v���C���[�̃f�X�g���N�^
	~Enemy_Manager();

	//�ʒu�̐ݒ�A�擾
	void Set_Position(int x, int y);
	void Get_Position(int* px, int* py, DIRECTION* direction = NULL);
};