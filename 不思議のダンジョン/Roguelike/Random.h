#pragma once
#include<random>

#include"Define.h"

class Random {
public:
/*////////
メンバ変数
*/////////


/*////////
メンバ関数
*/////////
public:
	//コンストラクタ
	Random();

	//デストラクタ
	~Random();

	int Dungeon_Random(int bet);

private:
	std::mt19937 engine;
};
