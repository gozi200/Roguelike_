#pragma once

#include"Enemy_Data.h"

class Data_Input {
public:
	Enemy_Data enemy_data;

	int loop_count;
public:
	//�R���X�g���N�^
	Data_Input();

	//�f�X�g���N�^
	~Data_Input();

	void Enemy_Data();

	int getExp(int id);

};