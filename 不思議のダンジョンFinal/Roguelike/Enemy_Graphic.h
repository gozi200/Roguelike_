#pragma once

#include<vector>

/*-----------------------------------------------
�G�l�~�[�̉摜�t�@�C���̃p�X��z��Ɋi�[����N���X
------------------------------------------------*/

class Enemy_Graphic {
public:
/*--------
�����o�ϐ�
--------*/
	std::vector<char*> graphics; // �摜�t�@�C���̂̃p�X���i�[����

 /*--------
 �����o�֐�
 --------*/
public:
	// �R���X�g���N�^
	Enemy_Graphic();

	// �f�X�g���N�^
	~Enemy_Graphic();

	// �摜�̂���t�H���_�̃p�X��z��Ɋi�[����
	void Load();
};