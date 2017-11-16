#pragma once

//----------------------------
//����̏����Ǘ�����N���X
//----------------------------

#include"DxLib.h"
#include"Define.h"
#include"Weapon_Graphic.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>

//���Ɏ����������ݒ肷��
struct SETTING_WEAPON_DATA {
	int ID;					 //�i���o�[
	std::string name;		 //����H
							 
	int x;					 //x�����W
	int y;					 //y�����W
	int ask;				 //���鎞�̋��z
	int price;				 //�������̋��z
	int level;				 //����̃��x��
	int attack;				 //�U����
	int peculiar_seal;		 //���X���Ă���ŗL�̈�
	int slot;				 //������邽�߂̃X���b�g
	int damage;				 //�������Ă��Ƃ��̃_���[�W
	int evolution_level;	 //�i���ɕK�v�ȃ��x��
	int reinforcement_value; //�����l

	int width;				 //�摜�̉���
	int height;				 //�摜�̏c��
	int SD_graphic_handle;			 //�������A�������̕���̉摜
	int graphic_handle;		 //�摜�f�[�^���i�[����
};

class Weapon_Data {
	/*////////
	�����o�ϐ�
	*/////////
public:
	Weapon_Graphic weapon_graphic;

	std::string file_pass;

	std::vector<SETTING_WEAPON_DATA> set_weapon_data;

	/*////////
	�����o�֐�
	*/////////
public:
	//�R���X�g���N�^
	Weapon_Data();

	//�f�X�g���N�^
	~Weapon_Data();

	/*�J���t�@�C���̃p�X���w��
	�@@param open_file_pass �J���t�@�C�����w��
	 */
	void Set_File_Pass(const std::string & open_file_pass);

	//�t�@�C�����J��
	bool Open_File();
};