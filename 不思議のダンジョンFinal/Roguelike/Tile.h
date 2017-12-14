#pragma once

#include"Split.h"
#include"Define.h"
#include"Set_File.h"
#include"Map_Tile.h"
#include"Tile_Graphic.h"

#include<vector>
#include<string>
#include<fstream>
#include<memory>

/*----------------------
���Ɏ����������ݒ肷��
-----------------------*/
struct TILE_DATA  : public MAP_TILE_TADA {
};

/*-------------
���̈����N���X
--------------*/
class Tile : public Map_Tile{
private:
	std::shared_ptr<Tile_Graphic> tile_graphic;

	std::vector<TILE_DATA> tile_datas; //�^�C���̎�ނ��ƂɊi�[

public:
	// �R���X�g���N�^
	Tile();

	//�f�X�g���N�^
	~Tile();

	/*������ID�Ɠ���ID�̉摜���A�����̍��W�֕`�悷��
	  @param x       �����W
	  @param y       �c���W
	  @param call_ID �Ăяo��ID
	*/
	void Render(int x, int y, int call_ID);
	
private:
	//csv�œǂݍ��񂾏����i�[���Ă���
	void Set_Parametor();
};