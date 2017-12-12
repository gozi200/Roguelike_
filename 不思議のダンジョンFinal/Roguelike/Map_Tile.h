#pragma once

#include"Set_File.h"

#include<string>
#include<memory>

/*----------------------------
�^�C���Ɏ���������̊��\����
----------------------------*/

struct MAP_TILE_TADA {
	int ID;			    //ID
	std::string name;   //���O
	int width;		    //�摜�̕�
	int height;         //�摜�̍���
	int graphic_handle; //�摜�n���h��
};

/*------------------------------
�}�b�v�ɔz�u����^�C���̊��N���X
-------------------------------*/

class Map_Tile {
/*--------
�����o�ϐ�
--------*/
protected:
	int ID;           //ID
	std::string name; //���O
	int width;		  //�摜�̕�
	int height;		  //�摜�̍���

	int loop_count;

	std::string file_pass;
	std::shared_ptr<Set_File> set;

/*--------
�����o�֐�
---------*/
	virtual void Set_Parametor() = 0;

	virtual void Render(int x, int y, int call_ID) = 0;
};