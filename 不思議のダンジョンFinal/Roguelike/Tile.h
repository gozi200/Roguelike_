#pragma once

#include"Split.h"
#include"Define.h"
#include"Set_File.h"
#include"Tile_Graphic.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>

// ���Ɏ����������ݒ肷��
struct TILE_DATA {
	int ID;             // �i���o�[
	std::string name;   // ���O
	int width;          // �摜�̉���
	int height;         // �摜�̏c��
	int graphic_handle; // �摜�f�[�^���i�[����
};

/*-------------
���̂������N���X
--------------*/
class Tile {
private:
	Set_File open;            // csv�t�@�C�����J�����߂̃N���X
	Tile_Graphic tile_graphic; // ���\�[�X����O���t�B�b�N�f�[�^���ĂԃN���X

	int ID;             // �i���o�[
	std::string name;   // ���O
	int width;          // �摜�̉���
	int height;         // �摜�̏c��
	int graphic_handle; // �摜�f�[�^���i�[����

	int loop_count;     // ���[�v�񐔂ɉ����ĉ��Z
	
	std::string file_pass;              //�t�@�C���̃p�X
	std::vector <TILE_DATA> tile_datas; //�^�C���̎�ނ��ƂɊi�[

public:
	// �R���X�g���N�^
	Tile();

	//�f�X�g���N�^
	~Tile();

	//csv�œǂݍ��񂾏����i�[���Ă���
	void Set_Parametor();

public:
	/*������ID�Ɠ���ID�̉摜���A�����̍��W�֕`�悷��
	  @param x       �����W
	  @param y       �c���W
	  @param call_ID �Ăяo��ID
	*/
	void Render(int x, int y, int call_ID);
};