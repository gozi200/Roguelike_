#pragma once

#include<vector>

/*----------------------------------------
�ǂ̉摜�t�@�C���̃p�X��z��Ɋi�[����N���X
----------------------------------------*/

class Wall_Graphic {
public:
	/*-------
	�����o�ϐ�
	--------*/
	std::vector<char*> graphics; // �摜�t�@�C���̃p�X���i�[����

	/*--------
	�����o�֐�
	---------*/
public:
	// �R���X�g���N�^
	Wall_Graphic();

	// �f�X�g���N�^
	~Wall_Graphic();

	// �摜�̂���t�H���_�̃p�X��z��Ɋi�[����
	void Load();
};