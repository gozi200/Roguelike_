#pragma once

#include<vector>

/*-----------------------------------------------
�v���C���[�̉摜�t�@�C���̃p�X��z��Ɋi�[����N���X
------------------------------------------------*/

class Player_Graphic {
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
	Player_Graphic();

	// �f�X�g���N�^
	~Player_Graphic();

	// �摜�̂���t�H���_�̃p�X��z��Ɋi�[����
	void Load();
};