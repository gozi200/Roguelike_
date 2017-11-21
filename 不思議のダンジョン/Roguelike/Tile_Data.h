#pragma once

/*---------------------------------
���̏����Ǘ�����N���X(�K�i���܂�)
----------------------------------*/

#include"DxLib.h"
#include"Define.h"
#include"Tile_Graphic.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>

//���Ɏ����������ݒ肷��
struct SETTING_TILE_DATA {
	int ID;				//�i���o�[
	std::string name;	//����H
	//int x;				//x�����W ����Ȃ��H
	//int y;				//y�����W
	int width;			//�摜�̉���
	int height;			//�摜�̏c��
	int graphic_handle; //�摜�f�[�^���i�[����
};

class Tile_Data {
/*---------
�����o�ϐ�
----------*/
public:
	Tile_Graphic tile_graphic;

	std::string file_pass;

	std::vector<SETTING_TILE_DATA> set_tile_data;

	int loop_count;

/*---------
�����o�֐�
----------*/
public:
	//�R���X�g���N�^
	Tile_Data();

	//�f�X�g���N�^
	~Tile_Data();

	/*�J���t�@�C���̃p�X���w��
	�@@param open_file_pass �J���t�@�C�����w��
	*/
	void Set_File_Pass(const std::string & open_file_pass);

	//�t�@�C�����J��
	bool Open_File();
};