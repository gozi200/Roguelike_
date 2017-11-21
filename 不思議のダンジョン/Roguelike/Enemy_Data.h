#pragma once

#include"DxLib.h"
#include"Item.h"
#include"Define.h"
#include"Enemy_Graphic.h"
#include"Object_Status_Base.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>

/*-----------------------------------------------------
�G�l�~�[�̃X�e�[�^�X��CSV�t�@�C���ŊǗ�����N���X(�摜��)
-----------------------------------------------------*/

struct SETTING_ENEMY_DATA : Object_Status_Base {
	int paturn;			  //�s���p�^�[��
	int evolution;		  //�i���`��
	int drop_item;		  //���S���Ɋm���ŗ��Ƃ��A�C�e��
	int experience_point; //�o���l(�����ł͓|���ꂽ�Ƃ��Ƀv���C���[���ɗ^���鐔�l)
};

class Enemy_Data {
/*--------
�����o�ϐ�
---------*/
public:
	Enemy_Graphic enemy_graphic;

	std::string file_pass;

	std::vector<SETTING_ENEMY_DATA> set_enemy_data;

	int loop_count;

	/*--------
	�����o�֐�
	---------*/
public:
	//�R���X�g���N�^
	Enemy_Data();

	//�f�X�g���N�^
	~Enemy_Data();

	/*�J���t�@�C���̃p�X���w��
	�@@param open_file_pass �J���t�@�C�����w��
	 */
	void Set_File_Pass(const std::string & open_file_pass);

	//�t�@�C�����J��
	bool Open_File();
};