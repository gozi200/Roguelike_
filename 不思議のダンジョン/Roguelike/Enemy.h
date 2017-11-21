#pragma once

#include"Actor.h"
#include"DxLib.h"
#include"Define.h"
#include"Vector2D.h"
#include"Enemy_Data.h"

/*----------------
Actorクラスを継承

敵を管理するクラス
-----------------*/

class Enemy : public Actor {
/*--------
メンバ変数
---------*/
Enemy_Data enemy_data;

int loop_count;

/*--------
メンバ関数
--------*/
public:
	//エネミーのコンストラクタ
	Enemy();

	//プレイヤーのデストラクタ
	~Enemy();

	//位置の設定、取得
	void Set_Position(int x, int y);
	void Get_Position(int* px, int* py, DIRECTION* direction = NULL);

	/*プレイヤーの画像を描画する
	 @param call_ID IDに合った画像を呼ぶ
	 @param x 描画する場所のx軸
	 @param y 描画する場所のy軸
	 */
	void Render(int call_ID, int x, int y);
};