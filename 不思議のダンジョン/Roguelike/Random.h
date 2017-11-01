#pragma once

#include"Define.h"

class Random {
public:
/*////////
メンバ変数
*/////////
	int random_number; //割り出される乱数

/*////////
メンバ関数
*/////////
public:
	//コンストラクタ
	Random();

	//デストラクタ
	~Random();

	int Dungeon_Random(int bet);

};
