#pragma once

#include"DxLib.h"
#include"Item.h"
#include"Define.h"
#include"Player_Graphic.h"
#include"Object_Status_Base.h"
#include"Split.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>

/*-----------------------------------------------------
�v���C���[�̃X�e�[�^�X��CSV�t�@�C���ŊǗ�����N���X(�摜��)
-----------------------------------------------------*/

struct SETTING_PLAYER_DATA : Object_Status_Base{
	int hunger_point;	  //�����x
	int noble_phantasm;	  //���������߂̃|�C���g
	int money;			  //������
};

class Player_Data {
/*--------
�����o�ϐ�
---------*/
public:
	Player_Graphic player_graphic;

	std::string file_pass;

	std::vector<SETTING_PLAYER_DATA> set_player_data;

	int loop_count;

/*--------
�����o�֐�
---------*/
public:
	//�R���X�g���N�^
	Player_Data();

	//�f�X�g���N�^
	~Player_Data();

	/*�J���t�@�C���̃p�X���w��
	�@@param open_file_pass �J���t�@�C�����w��
	 */
	void Set_File_Pass(const std::string & open_file_pass);

	//�t�@�C�����J��
	bool Open_File();
};