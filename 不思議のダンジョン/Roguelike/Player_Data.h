#pragma once

#include"DxLib.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>

/*////////////////////////////////////////////////////
�v���C���[�̃X�e�[�^�X��CSV�t�@�C���ŊǗ�����N���X(�摜��)
*/////////////////////////////////////////////////////

struct PLAYER_STATUS_DATA {
	int ID; //�i���o�[
	std::string name;
	int x; //x�����W
	int y; //y�����W
	int width; //�摜�̉���
	int height; //�摜�̉���
	int level;
	int hit_point;
	int noble_phantasm; //���������߂̃|�C���g
	int hunger_point; //���Ȃ��Q�[�W
	int experience_point; //�o���l
	int attack; //�f�̍U����(�����ɕ���̍U���́A�͂��v�Z)
	int defence; //�f�̖h���(�����ɖh��̖h��́A�͂��v�Z)
	int power; //��
	int activity; //�P�^�[���ɍs���ł����
	int turn_point; //�o�߃^�[�����J�E���g
	int graphic_handle; //�摜�f�[�^���i�[
	char* graphic_handle_pass; //�摜�f�[�^�̂���ꏊ
};

class Player_Data {
	std::string file_pass;

	PLAYER_STATUS_DATA player_data;

public:
	//�R���X�g���N�^
	Player_Data(const std::string & open_filepass);

	//�f�X�g���N�^
	Player_Data() {};

	void Load_Graph();
};