#pragma once

#include"DxLib.h"
#include"Item.h"
#include"Define.h"
#include"Enemy_Graphic.h"
#include"Split.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>

/*-----------------------------------------------------
�G�l�~�[�̃X�e�[�^�X��CSV�t�@�C���ŊǗ�����N���X(�摜��)
-----------------------------------------------------*/

struct SETTING_ENEMY_DATA {
	int ID;						//�i���o�[
	char* name;					//���O
	int x;						//���̍��W
	int y;						//�c�̍��W

	int level;					//���x��
	int power;					//������ (�f�̍U���́B�����ɕ���̍U���́A���x���ŕϓ�����U���͂��v�Z)
	int attack;					//�U����
	int defence;				//�h���
	int agility;				//�q����(�����ł͉��)
	int hit_point;				//�q�b�g�|�C���g(0�Ŏ��S)
	int activity;				//�s����(�����ł͂P�^�[���ɍs���ł��鐔)
	int turn_count;				//�o�߃^�[�����J�E���g
	int experience_point;		//�o���l(���l���ƂɃ��x�����オ��)

	int graphic_handle;			//�摜�̃n���h��
	int paturn;					//�s���p�^�[��
	int evolution;				//�i���`��
	int drop_item;				//���S���Ɋm���ŗ��Ƃ��A�C�e��
	int first_floor;			//�o���J�n�K�w
	int last_floor;				//�o���I���K�w
	int drop_item_ID;			//�h���b�v����A�C�e����ID
	int width;					//�\������镝
	int height;					//�\������鍂��
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