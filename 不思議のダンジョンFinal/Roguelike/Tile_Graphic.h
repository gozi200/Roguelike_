#pragma once

#include<vector>

/*--------------------------------------
���̉摜�t�@�C���̃p�X��z��Ɋi�[����N���X
---------------------------------------*/ 

class Tile_Graphic {
/*-------
�����o�ϐ�
--------*/
public:
	std::vector<char*> graphics; // �摜�t�@�C���̃p�X���i�[����

/*--------
�����o�֐�
---------*/
public:
	// �R���X�g���N�^
	Tile_Graphic();

	// �f�X�g���N�^
	~Tile_Graphic();

	// �摜�̂���t�H���_�̃p�X��z��Ɋi�[����
	void Load();
};