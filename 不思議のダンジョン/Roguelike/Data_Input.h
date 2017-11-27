#pragma once

#include"Enemy_Data.h"

class Data_Input {
public:
	Enemy_Data enemy_data;

	int loop_count;
public:
	//コンストラクタ
	Data_Input();

	//デストラクタ
	~Data_Input();

	void Enemy_Data();

	int getExp(int id);

};