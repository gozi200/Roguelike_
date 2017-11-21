#pragma once

#include"Ally.h"
#include"Vector2D.h"
#include"Player_Data.h"
#include"Player_Key_Contloroller.h"

/*------------------
Actorクラスを継承

自機を管理するクラス
-------------------*/

class Player : public Ally {


/*--------
メンバ変数
---------*/
public:
	Player_Key_Controller* player_key_controller;
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
	void Get_Position(int *px, int*py, DIRECTION *direction = NULL);

	/*床の画像を描画する
	　@param call_ID IDに合った画像を呼ぶ
	 @param x 描画する場所のx軸
	 @param y 描画する場所のy軸
	 */
	void Render(int call_ID, int x, int y);
};