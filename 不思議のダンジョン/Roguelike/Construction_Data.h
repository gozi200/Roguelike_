#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Construction_Graphic.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>

//���Ɏ����������ݒ肷��
struct SETTING_CONSTRUCTION_DATA {
	int ID; //�i���o�[�@TODO: ����H
	std::string name;
	int x; //x�����W
	int y; //y�����W
	int width; //�摜�̉���
	int height; //�摜�̏c��
	int graphic_handle; //�摜�f�[�^���i�[����
};

/*////////////////////////////
�����̉摜��z��Ɋi�[����N���X
*/////////////////////////////

class Construction_Data {
public:
	//Construction_Graphic Construction_graphic;

	std::string file_pass;

	std::vector<SETTING_CONSTRUCTION_DATA> set_construction_data;

	/*////////
	�����o�֐�
	*/////////
public:
	//�R���X�g���N�^
	Construction_Data();

	//�f�X�g���N�^
	~Construction_Data();

	/*�J���t�@�C���̃p�X���w��
	�@@param open_file_pass �J���t�@�C�����w��
	 */
	void Set_File_Pass(const std::string & open_file_pass);

	//�t�@�C�����J��
	bool Open_File();

	//�摜��ǂݍ���
	void Load_Graph();
};