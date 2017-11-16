#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Food_Graphic.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>

//���Ɏ����������ݒ肷��
struct SETTING_FOOD_DATA {
	int ID;				//�i���o�[
	std::string name;	//����H

	int x;				//x�����W
	int y;				//y�����W
	int effect;			//���ʒl
	int add_capacity;	//�ő�l�̑���
	int ask;			//���鎞�̋��z
	int price;			//�������̋��z
	int damage;			//�������Ă��Ƃ��̂̃_���[�W

	int width;			//�摜�̉���
	int height;			//�摜�̏c��
	int graphic_handle; //�摜�f�[�^���i�[����
};

/*////////////////////////////////
���̉摜���Ǘ�����N���X(�K�i���܂�)
*/////////////////////////////////

class Food_Data {
	/*////////
	�����o�ϐ�
	*/////////
public:
	Food_Graphic tile_graphic;

	std::string file_pass;

	std::vector<SETTING_FOOD_DATA> set_tile_data;

	/*////////
	�����o�֐�
	*/////////
public:
	//�R���X�g���N�^
	Food_Data();

	//�f�X�g���N�^
	~Food_Data();

	/*�J���t�@�C���̃p�X���w��
	�@@param open_file_pass �J���t�@�C�����w��
	*/
	void Set_File_Pass(const std::string & open_file_pass);

	//�t�@�C�����J��
	bool Open_File();
};