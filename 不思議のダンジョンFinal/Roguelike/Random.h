#pragma once

#include"Define.h"

#include<random>

/*------------------------------
MT法を使用いて乱数を取得するクラス
-------------------------------*/
static class Random {
public:
/*--------
メンバ変数
---------*/


/*////////
メンバ関数
*/////////
public:
	// コンストラクタ
	Random();

	// デストラクタ
	~Random();

	/*乱数を取得する
	  @param bet 
	*/
	int Dungeon_Random(int bet);

private:
	std::mt19937 engine;
};
