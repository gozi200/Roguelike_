#pragma once

#include"Actor.h"
#include"Vector2D.h"

/*/////////////////
Actorクラスを継承

敵を管理するクラス
////////////////*/

class Enemy : public Actor {
public:
	//エネミーのコンストラクタ
	Enemy();

	//プレイヤーのデストラクタ
	~Enemy();

	//位置の設定、取得
	void Set_Position(int x, int y);
	void Get_Position(int *px, int*py, DIRECTION *direction = NULL);

};