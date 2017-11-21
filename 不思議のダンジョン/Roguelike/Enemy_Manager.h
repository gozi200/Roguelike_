#pragma once

#include"Enemy.h"

class Dungeon_Base; //インクルードの衝突を避ける

class Enemy_Manager : public Enemy {
/*---------
メンバ変数
---------*/

/*---------
メンバ関数	
----------*/
public:
	Enemy_Manager(){}

	virtual ~Enemy_Manager(){}

	//行動する
	virtual void Move(Dungeon_Base* dungeon_base) = 0;

	//新しい座標への移動を行う
	//先にプレイヤーがいたら攻撃を行い、壁や、ほかのエネミーがいたら何もしない
	bool Is_Move_Action(Dungeon_Base* dungeon_base, int mx, int my);

};