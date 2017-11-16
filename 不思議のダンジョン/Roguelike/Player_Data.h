#pragma once

#include"DxLib.h"
#include"Item.h"
#include"Define.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>

/*////////////////////////////////////////////////////
�v���C���[�̃X�e�[�^�X��CSV�t�@�C���ŊǗ�����N���X(�摜��)
*/////////////////////////////////////////////////////

struct PLAYER_STATUS_DATA {
	int ID;				  //�i���o�[
	std::string name;	  
	int x;				  //x�����W
	int y;				  //y�����W

	int level;			  //���x��
	int hit_point;		  //�̗�
	int power;			  //������ �f�̍U����(�����ɕ���̍U���́A�͂��v�Z)
	int attack;			  //���x���A�b�v�ŏ㏸����{�[�i�X
	int defence;		  //�f�̖h���(�����ɖh��̖h��́A�͂��v�Z)
	int hunger_point;	  //���Ȃ��Q�[�W
	int noble_phantasm;	  //���������߂̃|�C���g
	int experience_point; //�o���l
	int activity;		  //�P�^�[���ɍs���ł����
	int turn_count;		  //�o�߃^�[�����J�E���g
	
	int money;			  //������

	Item items[MAX_STOCK_ITEM]; //�����؂��A�C�e���̐�

	int width;			  //�摜�̉���
	int height;			  //�摜�̉���
	int graphic_handle;   //�摜�f�[�^���i�[
};

class Player_Data {
	std::string file_pass;

	PLAYER_STATUS_DATA player_data;

public:
	//�R���X�g���N�^
	Player_Data(const std::string & open_filepass);

	//�f�X�g���N�^
	Player_Data() {};

};