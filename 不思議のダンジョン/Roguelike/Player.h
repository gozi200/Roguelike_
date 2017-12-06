#pragma once

#include"Actor.h"
#include"DxLib.h"
#include"Define.h"
#include"Vector2D.h"
#include"Player_Data.h"

/*------------------
Allyクラスを継承

自機を管理するクラス
-------------------*/

class Player : Actor{
/*--------
メンバ変数
---------*/
public:
	Player_Data player_data;

	int loop_count;

/*--------
メンバ関数
---------*/
public:
	//コンストラクタ
	Player();

	//デストラクタ
	~Player();

	//位置の設定、取得
	void Set_Position(int x, int y);
	void Get_Position(int* px, int* py, eDIRECTION* direction = NULL);

	/*プレイヤーの画像を描画する
	 @param call_ID IDに合った画像を呼ぶ
	 @param x 描画する場所のx軸
	 @param y 描画する場所のy軸
	 */
	void Render(int call_ID, int x, int y);
};