#pragma once

#include"DxLib.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>

/*////////////////////////////////////////////////
�����̃X�e�[�^�X��CSV�t�@�C���ŊǗ�����N���X(�摜��)
*/////////////////////////////////////////////////

struct PARTNER_STATUS_DATA {
	int ID; //�i���o�[
	std::string name; //����H
	int x; //x�����W
	int y; //y�����W
	int width; //�摜�̉���
	int height; //�摜�̉���
	int level;
	int hit_point;
	int noble_phantasm; //���������߂̃|�C���g
	int experience_point; //�o���l
	int attack; //�f�̍U����(�����ɕ���̍U���́A�͂��v�Z)
	int defence; //�f�̖h���(�����ɖh��̖h��́A�͂��v�Z)
	int power; //��
	int activity; //�P�^�[���ɍs���ł����
	int graphic_handle; //�摜�f�[�^���i�[
	char* graphic_handle_pass; //�摜�f�[�^�̂���ꏊ
};

class Partner_Data {
		std::string file_pass;

		PARTNER_STATUS_DATA partner_data;

	public:
		//�R���X�g���N�^
		Partner_Data(const std::string & open_filepass);

		//�f�X�g���N�^
		Partner_Data();

		void Load_Graph();
};