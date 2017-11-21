#pragma once

#include"Define.h"
#include"Tile_Data.h"

/*--------------
���̎��̂������H
---------------*/

class Tile {
public:
	Tile_Data tile_data;

	int loop_count; //���[�v�񐔂𐔂���

	//�R���X�g���N�^
	Tile();

	//�f�X�g���N�^
	~Tile();

	/*���̉摜��`�悷��
	�@@param call_ID ID�ɍ������摜���Ă�
	 @param x �`�悷��ꏊ��x��
	 @param y �`�悷��ꏊ��y��
	 */
	void Render(int call_ID, int x, int y);

};