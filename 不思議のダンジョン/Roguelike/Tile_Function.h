#pragma once

#include"Define.h"
#include"Tile_Data.h"

/*//////////////////////////
���Ɋ֌W����֐���ݒ肷��N���X
*//////////////////////////

class Tile_Function {
public:
	Tile_Data Tile_data;

	int loop_count = 0; //���[�v�񐔂𐔂���

	//�R���X�g���N�^
	Tile_Function();

	//�f�X�g���N�^
	~Tile_Function();

	/*���̉摜��`�悷��
	�@@param call_ID ID�ɍ������摜���Ă�
	*/
	void Draw_Tile(int call_ID);

};