#pragma once

/*------------------------------
�ǂݍ���csv�t�@�C����ݒ肷��N���X
------------------------------*/

#include"DxLib.h"

#include<string>

class Set_File {
/*---------
�����o�ϐ�
----------*/
public:

/*---------
�����o�֐�
----------*/
public:
	// �R���X�g���N�^
	Set_File();

	// �f�X�g���N�^
	~Set_File();

	/*�J���t�@�C���̃p�X���w��
	�@@param open_file_pass �J���t�@�C�����w��
	*/
	std::string Set_File_Pass(std::string file_pass, const std::string& open_file_pass);
};