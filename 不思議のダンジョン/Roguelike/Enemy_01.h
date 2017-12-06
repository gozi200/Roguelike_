#pragma once

#include"Enemy.h"
#include"Random.h"

class Enemy_01 : public Enemy {
/*--------
メンバ変数
--------*/
public:
	int x, y; //座標
	Random* random;
	eDIRECTION direciton;

/*--------
メンバ関数
---------*/
public:
	//コンストラクタ
	Enemy_01();

	//デストラクタ
	virtual ~Enemy_01();

	//行動する
	virtual void Move(Dungeon_Base* dungeon_base);
};