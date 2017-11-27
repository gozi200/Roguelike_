#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Wall_Graphic.h"
#include"Split.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>

/*/////////////////////
�ǂ̉摜���Ǘ�����N���X
*//////////////////////

struct SETTING_WALL_DATA {
	int ID;				//�i���o�[
	std::string name;	//���O
	int x;				//x�����W
	int y;				//y�����W
	int width;			//�摜�̉���
	int height;			//�摜�̏c��
	int graphic_handle; //�摜�f�[�^���i�[����
};

class Wall_Data {
/*////////
�����o�ϐ�
*/////////
public:
	Wall_Graphic wall_graphic;

	std::string file_pass;

	std::vector<SETTING_WALL_DATA> set_wall_data;

/*////////
�����o�֐�
*/////////
public:
	//�R���X�g���N�^
	Wall_Data();

	//�f�X�g���N�^
	~Wall_Data();

	void Set_File_Pass(const std::string & open_file_path);

	bool Open_File();

	void Load_Graph();
};