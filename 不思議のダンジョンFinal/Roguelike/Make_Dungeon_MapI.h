#pragma once

#include"Tile.h"
#include"Wall.h"
#include"Dungeon_Manager.h"
#include"Create_Dungeon_Map.h"

#include<string>
#include<memory>

/*----------------------------
�_���W�����̉�ʂ�`�悷��N���X
-----------------------------*/

class Dungeon_GUI : public Create_Dungeon_Map {
private:
	std::shared_ptr<Tile> tile;
	std::shared_ptr<Wall> wall;

	int x,             // ��ʑS�̂̍��W(��)
		y;             // ��ʑS�̂̍��W(�c)
	int map_x,         // �}�b�v�̍��W(��)
		map_y;         // �}�b�v�̍��W(�c)
	int character_x,   // �L�����N�^�[�̍��W(�c)
		character_y;   // �L�����N�^�[�̍��W(��)
	int dungeon_x,     // �_���W�����̍��W(�c)
		dungeon_y;     // �_���W�����̍��W(��)

	int loop_cont;     // ���[�v�̉񐔂𐔂���

/*--------
�����o�֐�
---------*/
public:
	// �R���X�g���N�^
	Dungeon_GUI();

	// �f�X�g���N�^
	~Dungeon_GUI();

	//��ʂ̕`��
	void Render();
};