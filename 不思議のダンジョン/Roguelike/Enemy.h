#pragma once

#include"Actor.h"

class Dungeon_Base; //インクルードの衝突を避ける

class Enemy : public Actor {
/*---------
メンバ変数
---------*/

/*---------
メンバ関数	
----------*/
public:
	Enemy();

	virtual ~Enemy();

	//行動する
	virtual void Move(Dungeon_Base* dungeon_base) = 0;

	//新しい座標への移動を行う
	//先にプレイヤーがいたら攻撃を行い、壁や、ほかのエネミーがいたら何もしない
	bool Move_Action(Dungeon_Base* dungeon_base, int mx, int my);

	/*エネミーの画像を描画する
	@param call_ID IDに合った画像を呼ぶ
	@param x 描画する場所のx軸
	@param y 描画する場所のy軸
	*/
	void Render(int call_ID, int x, int y);

	int Reset();

	int Turn(Dungeon_Base* dungeon_base, int count);
};